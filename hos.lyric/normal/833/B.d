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


enum INF = 10^^9;

void main() {
  try {
    for (; ; ) {
      const N = readInt();
      const K = readInt();
      auto A = new int[N];
      foreach (i; 0 .. N) {
        A[i] = readInt() - 1;
      }
      
      auto cnt = new int[N];
      int now;
      void add(int i) {
        if (cnt[A[i]]++ == 0) {
          ++now;
        }
      }
      void rem(int i) {
        if (--cnt[A[i]] == 0) {
          --now;
        }
      }
      
      auto dp = new int[][](K + 1, N + 1);
      foreach (k; 0 .. K + 1) {
        dp[k][] = -INF;
      }
      dp[0][0] = 0;
      
      foreach (k; 0 .. K) {
        cnt[] = 0;
        now = 0;
        int l, r;
        void doIt(int iL, int iR, int jL, int jR) {
          if (iR - iL >= 1) {
            debug {
              writeln("doIt ", iL, " ", iR, " ", jL, " ", jR);
            }
            const i = (iL + iR) / 2;
            for (; r < i; ) add(r++);
            for (; r > i; ) rem(--r);
            int jm = -1;
            foreach (j; jL .. min(jR, i)) {
              for (; l < j; ) rem(l++);
              for (; l > j; ) add(--l);
              debug {
                writefln("[%s, %s): %s", l, r, now);
              }
              if (chmax(dp[k + 1][i], dp[k][j] + now)) {
                jm = j;
              }
            }
            doIt(iL, i, jL, jm + 1);
            doIt(i + 1, iR, jm, jR);
          }
        }
        doIt(k + 1, N + 1, 0, N + 1);
        debug {
          writeln(k + 1, ": ", dp[k + 1]);
        }
      }
      writeln(dp[K][N]);
    }
  } catch (EOFException e) {
  }
}