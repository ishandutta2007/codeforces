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
  try {
    for (; ; ) {
      const N = readLong();
      const M = readInt();
      auto L = new long[M];
      foreach (i; 0 .. M) {
        L[i] = readLong();
      }
      
      auto LSum = new long[M + 1];
      foreach (i; 0 .. M) {
        LSum[i + 1] = LSum[i] + L[i];
      }
      
      long[] ans;
      if (LSum[M] >= N) {
        ans = new long[M];
        long bef = -1;
        foreach (i; 0 .. M) {
          /*
            bef < p
            p + L[i] <= N
            p + L[i] + ... + L[M - 1] >= N
          */
          ans[i] = max(bef + 1, N - (LSum[M] - LSum[i]));
          if (!(ans[i] + L[i] <= N)) {
            ans = [];
            break;
          }
          bef = ans[i];
        }
      }
      
      if (!ans.empty) {
        foreach (i; 0 .. M) {
          if (i > 0) write(" ");
          write(ans[i] + 1);
        }
        writeln();
      } else {
        writeln(-1);
      }
      
      debug {
        long[] brt;
        foreach (h; 0 .. N^^M) {
          auto ps = iota(M).map!(i => (h / N^^i % N)).array;
          bool ok = true;
          auto col = new int[cast(int)(N)];
          col[] = -1;
          foreach (i; 0 .. M) {
            if (ps[i] + L[i] <= N) {
              col[cast(int)(ps[i]) .. cast(int)(ps[i] + L[i])] = i;
            } else {
              ok = false;
              break;
            }
          }
          ok = ok && (col.count(-1) == 0);
          foreach (i; 0 .. M) {
            ok = ok && (col.count(i) != 0);
          }
          if (ok) {
            brt = ps;
            break;
          }
        }
        writeln("brt = ", brt);
        assert((!ans.empty) == (!brt.empty));
      }
    }
  } catch (EOFException e) {
  }
}