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


enum LIM_B = 10;
enum LIM_L = 100;

void main() {
  auto dp = new long[][][LIM_B + 1];
  foreach (B; 2 .. LIM_B + 1) {
    dp[B] = new long[][](LIM_L + 1, 1 << B);
    dp[B][0][0] = 1;
    foreach (l; 0 .. LIM_L) {
      foreach (p; 0 .. 1 << B) {
        foreach (x; 0 .. B) {
          dp[B][l + 1][p ^ 1 << x] += dp[B][l][p];
        }
      }
    }
  }
  
  long solve(const(int) B, const(long) N) {
    int[] as;
    for (long n = N; n; n /= B) {
      as ~= cast(int)(n % B);
    }
    as.reverse;
    const asLen = cast(int)(as.length);
    long ans;
    // short
    foreach (l; 1 .. asLen) {
      foreach (x; 1 .. B) {
        ans += dp[B][l - 1][1 << x];
      }
    }
    // as long
    int p;
    foreach (i; 0 .. asLen) {
      foreach (x; 0 .. as[i]) {
        if (i > 0 || x > 0) {
          debug {
            // writeln("  ", B, " ", asLen - 1 - i, " ", p ^ 1 << x, ": ", dp[B][asLen - 1 - i][p ^ 1 << x]);
          }
          ans += dp[B][asLen - 1 - i][p ^ 1 << x];
        }
      }
      p ^= 1 << as[i];
    }
    debug {
      writeln("solve ", B, " ", as, " = ", ans);
    }
    debug {
      long brt;
      foreach (n; 1 .. N) {
        int q;
        for (long nn = n; nn; nn /= B) {
          q ^= 1 << cast(int)(nn % B);
        }
        if (q == 0) {
          ++brt;
        }
      }
      writeln("brt = ", brt);
      assert(brt == ans);
    }
    return ans;
  }
  
  try {
    for (; ; ) {
      const numCases = readInt();
      foreach (caseId; 0 .. numCases) {
        const B = readInt();
        const L = readLong();
        const R = readLong();
        
        long ans;
        ans -= solve(B, L);
        ans += solve(B, R + 1);
        writeln(ans);
      }
    }
  } catch (EOFException e) {
  }
}