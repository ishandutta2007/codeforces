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


enum B = 16;
enum INF = 10L^^18;

void main() {
  try {
    for (; ; ) {
      const S = readToken();
      const L = cast(int)(S.length);
      
      auto BB = new long[L + 1];
      BB[0] = 1;
      foreach (i; 1 .. L + 1) {
        BB[i] = BB[i - 1] * B;
      }
      
      const X = S.to!long(B);
      auto A = new long[L];
      foreach (i; 0 .. L) {
        A[i] = X / BB[i] % B;
      }
      debug {
        writeln(A);
      }
      
      long ans = INF;
      foreach (carry; 0 .. 1 << (L - 1)) {
        auto as = A.dup;
        foreach (i; 0 .. L - 1) {
          if ((carry >> i) & 1) {
            as[i] -= B;
            as[i + 1] += 1;
          }
        }
        if (as.sum == 0) {
          debug {
            writeln("as = ", as);
          }
          auto asSums = new long[1 << L];
          asSums[0] = 0;
          foreach (i; 0 .. L) {
            foreach (p; 0 .. 1 << i) {
              asSums[p | 1 << i] = asSums[p] + as[i];
            }
          }
          auto dp = new long[1 << L];
          dp[] = INF;
          dp[0] = 0;
          foreach (p; 0 .. 1 << L) {
            if (dp[p] < INF) {
              foreach (i; 0 .. L) {
                if (!(p & 1 << i)) {
                  const pp = p | 1 << i;
                  if (0 <= asSums[pp] && asSums[pp] < B) {
                    chmin(dp[pp], dp[p] + BB[i] * asSums[p]);
                  }
                }
              }
            }
          }
          chmin(ans, dp[(1 << L) - 1]);
        }
      }
      
      if (ans >= INF) {
        writeln("NO");
      } else {
        writefln("%0*x", L, ans);
      }
    }
  } catch (EOFException e) {
  }
}