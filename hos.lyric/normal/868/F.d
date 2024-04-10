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


enum INF = 10L^^18;

void main() {
  try {
    for (; ; ) {
      const N = readInt();
      const K = readInt();
      auto A = new int[N];
      foreach (i; 0 .. N) {
        A[i] = readInt() - 1;
      }
      
      auto dp = new long[][](K + 1, N + 1);
      foreach (k; 0 .. K + 1) {
        dp[k][] = INF;
      }
      dp[0][0] = 0;
      foreach (k; 0 .. K) {
        auto freq = new long[N];
        long cost;
        int l, r;
        void incrL() { cost -= --freq[A[l++]]; }
        void decrL() { cost += freq[A[--l]]++; }
        void incrR() { cost += freq[A[r++]]++; }
        void decrR() { cost -= --freq[A[--r]]; }
        
        void solve(int i0, int i1, int j0, int j1) {
          if (i1 - i0 < 1) {
            return;
          }
          debug {
            // writefln("solve [%s, %s) [%s, %s)", i0, i1, j0, j1);
          }
          const i = (i0 + i1) / 2;
          for (; r < i; ) incrR();
          for (; r > i; ) decrR();
          int jm = -1;
          foreach (j; j0 .. min(j1, i)) {
            debug {
              // writeln("  ", i, " ", j);
            }
            for (; l < j; ) incrL();
            for (; l > j; ) decrL();
            if (chmin(dp[k + 1][i], dp[k][j] + cost)) {
              jm = j;
            }
          }
          solve(i0, i, j0, jm + 1);
          solve(i + 1, i1, jm, j1);
        }
        solve(k + 1, N + 1, k, N);
      }
      
      debug {
        foreach (k; 0 .. K + 1) {
          writefln("dp[%s] = %s", k, dp[k]);
        }
      }
      writeln(dp[K][N]);
      
      debug {
        auto brt = new long[][](K + 1, N + 1);
        foreach (k; 0 .. K + 1) {
          brt[k][] = INF;
        }
        brt[0][0] = 0;
        foreach (k; 0 .. K) {
          foreach (i; 0 .. N + 1) {
            foreach (j; i + 1 .. N + 1) {
              long cost;
              foreach (grp; A[i .. j].dup.sort.group) {
                const long num = grp[1];
                cost += num * (num - 1) / 2;
              }
              chmin(brt[k + 1][j], brt[k][i] + cost);
            }
          }
        }
        foreach (k; 0 .. K + 1) {
          writefln("brt[%s] = %s", k, brt[k]);
        }
        assert(brt == dp);
      }
    }
  } catch (EOFException e) {
  }
}