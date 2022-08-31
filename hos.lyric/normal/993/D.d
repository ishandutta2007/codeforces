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
enum R = 1000;

alias Task = Tuple!(long, "a", long, "b");

void main() {
  try {
    for (; ; ) {
      const N = readInt();
      auto T = new Task[N];
      foreach (i; 0 .. N) {
        T[i].a = readLong();
      }
      foreach (i; 0 .. N) {
        T[i].b = readLong();
      }
      T.sort;
      T.reverse;
      
      long[] as;
      long[][] bss;
      for (int i = 0, j; i < N; i = j) {
        long[] bs;
        for (j = i; j < N && T[i].a == T[j].a; ++j) {
          bs ~= T[j].b;
        }
        as ~= T[i].a;
        bss ~= bs;
      }
      const asLen = cast(int)(as.length);
      auto bsLens = new int[asLen];
      foreach (i; 0 .. asLen) {
        bsLens[i] = cast(int)(bss[i].length);
      }
      debug {
        writeln("as = ", as);
        writeln("bss = ", bss);
      }
      
      bool check(long t) {
        debug {
          writeln("t = ", t);
        }
        // pos, room
        auto dp = new long[][](asLen + 1, N + 1);
        foreach (i; 0 .. asLen + 1) {
          dp[i][] = INF;
        }
        dp[0][0] = 0;
        foreach (i; 0 .. asLen) {
          auto vals = new long[bsLens[i] + 1];
          foreach (x; 0 .. bsLens[i]) {
            vals[x + 1] = vals[x] + (R * as[i] - t * bss[i][x]);
          }
          debug {
            writefln("  vals[%s] = %s", i, vals);
          }
          foreach (j; 0 .. N + 1) {
            if (dp[i][j] < INF) {
              foreach (x; 0 .. bsLens[i] + 1) {
                if (j >= bsLens[i] - x) {
                  chmin(dp[i + 1][j - (bsLens[i] - x) + x], dp[i][j] + vals[x]);
                }
              }
            }
          }
        }
        debug {
          foreach (i; 0 .. asLen + 1) {
            writefln("  dp[%s] = %s", i, dp[i]);
          }
        }
        foreach (j; 0 .. N + 1) {
          if (dp[asLen][j] <= 0) {
            return true;
          }
        }
        return false;
      }
      
      long lo = -1, hi = 10L^^12;
      for (; lo + 1 < hi; ) {
        const mid = (lo + hi) / 2;
        (check(mid) ? hi : lo) = mid;
      }
      writeln(hi);
    }
  } catch (EOFException e) {
  }
}