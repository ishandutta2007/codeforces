import std.conv, std.functional, std.range, std.stdio, std.string;
import std.algorithm, std.array, std.bigint, std.bitmanip, std.complex, std.container, std.math, std.mathspecial, std.numeric, std.regex, std.typecons;
import core.bitop;

class EOFException : Throwable { this() { super("EOF"); } }
string[] tokens;
string readToken() { for (; tokens.empty; ) { if (stdin.eof) { throw new EOFException; } tokens = readln.split; } auto token = tokens.front; tokens.popFront; return token; }
int readInt() { return readToken.to!int; }
long readLong() { return readToken.to!long; }
real readReal() { return readToken.to!real; }

bool chmin(T)(ref T t, in T f) { if (t > f) { t = f; return true; } else { return false; } }
bool chmax(T)(ref T t, in T f) { if (t < f) { t = f; return true; } else { return false; } }

int binarySearch(alias pred, T)(in T[] as) { int lo = -1, hi = cast(int)(as.length); for (; lo + 1 < hi; ) { const mid = (lo + hi) >> 1; (unaryFun!pred(as[mid]) ? hi : lo) = mid; } return hi; }
int lowerBound(T)(in T[] as, T val) { return as.binarySearch!(a => (a >= val)); }
int upperBound(T)(in T[] as, T val) { return as.binarySearch!(a => (a > val)); }




void main() {
  debug {
    foreach (n; 1 .. 8 + 1) {
      auto prv = new int[1 << n];
      prv[] = -1;
      prv[0] = -2;
      for (; ; ) {
        bool upd;
        foreach (p; 0 .. 1 << n) {
          if (!~prv[p]) {
            foreach (i; 0 .. n - 2) {
              const s = popcnt((p >> i) & 7) & 1;
              int pp = p;
              if (s) {
                pp |= 7 << i;
              } else {
                pp &= ~(7 << i);
              }
              if (~prv[pp]) {
                prv[p] = i;
                upd = true;
                break;
              }
            }
          }
        }
        if (!upd) {
          break;
        }
      }
      foreach (p; 0 .. 1 << n) {
        /*
        if (~prv[p]) {
          foreach (i; 0 .. n) {
            write((p >> i) & 1);
          }
          writeln(" ", prv[p]);
        }
        */
        if (!(popcnt(p) & 1) && !~prv[p]) {
          foreach (i; 0 .. n) {
            write((p >> i) & 1);
          }
          writeln;
        }
      }
      writeln(n, ": ", (1 << n) - prv.count(-1));
    }
  }
  
  try {
    for (; ; ) {
      const numCases = readInt();
      foreach (caseId; 0 .. numCases) {
        const N = readInt();
        auto A = new int[N];
        foreach (i; 0 .. N) {
          A[i] = readInt();
        }
        
        auto sumA = new int[N + 1];
        foreach (i; 0 .. N) {
          sumA[i + 1] = sumA[i] + A[i];
        }
        
        int[] ans;
        void waf(int l, int r) {
          for (int i = r - 3; i >= l; i -= 2) {
            ans ~= i;
          }
          for (int i = l + 2; i + 3 <= r; i += 2) {
            ans ~= i;
          }
        }
        
        if (N % 2 == 0) {
          for (int k = 1; k < N; k += 2) {
            if (sumA[k] % 2 == 0 && (sumA[N] - sumA[k]) % 2 == 0) {
              debug {
                writeln("k = ", k);
              }
              waf(0, k);
              waf(k, N);
              break;
            }
          }
        } else {
          if (sumA[N] % 2 == 0) {
            waf(0, N);
          }
        }
        
        if (ans) {
          writeln("YES");
          writeln(ans.length);
          foreach (index, i; ans) {
            if (index > 0) write(" ");
            write(i + 1);
          }
          writeln;
        } else {
          writeln("NO");
        }
      }
    }
  } catch (EOFException e) {
  }
}