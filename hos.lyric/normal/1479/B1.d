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
      const N = readInt();
      auto A = new int[N];
      foreach (i; 0 .. N) {
        A[i] = readInt();
      }
      
      const gs = A.group.array;
      const gsLen = cast(int)(gs.length);
      debug {
        writeln("A = ", A);
        writeln("gs = ", gs);
      }
      
      int ans;
      for (int j = 0, k; j < gsLen; j = k) {
        for (k = j; k < gsLen && (gs[j][1] == 1) == (gs[k][1] == 1); ++k) {}
        if (gs[j][1] == 1) {
          ans += (k - j);
          if (0 < j && k < gsLen && gs[j - 1][0] == gs[k][0]) {
            if ((k - j) % 2 != 0) {
              bool bad = true;
              for (int l = j + 1; l < k; l += 2) {
                bad = bad && (gs[j - 1][0] == gs[l][0]);
              }
              if (bad) {
                debug {
                  writeln("bad ", gs[j .. k]);
                }
                ans -= 1;
              }
            }
          }
        } else {
          ans += 2 * (k - j);
        }
      }
      writeln(ans);
      
      debug {
        int brt = 0;
        foreach (p; 0 .. 1 << N) {
          int cost;
          int[2] bs = [-1, -1];
          foreach (i; 0 .. N) {
            const s = (p >> i) & 1;
            if (bs[s] != A[i]) {
              ++cost;
              bs[s] = A[i];
            }
          }
          chmax(brt, cost);
        }
        writeln("brt = ", brt);
        assert(brt == ans);
      }
    }
  } catch (EOFException e) {
  }
}