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
  /*
  debug {
    enum lim = 16;
    auto anss = new int[][][][](lim + 1, lim^^2 + 1);
    foreach (p; 0 .. 1 << lim) {
      const n = popcnt(p);
      int m;
      foreach (a; 1 .. lim + 1) foreach (b; a + 1 .. lim - a + 1) {
        if ((p & 1 << (a - 1)) && (p & 1 << (b - 1)) && (p & 1 << (a + b - 1))) {
          ++m;
        }
      }
      anss[n][m] ~= iota(1, lim + 1).filter!(a => (p & 1 << (a - 1))).array;
    }
    foreach (n; 0 .. lim + 1) {
      foreach (m; 0 .. n^^2 + 1) {
        writeln(n, " ", m, ": ", anss[n][m]);
      }
    }
  }
  */
  
  try {
    for (; ; ) {
      const N = readInt();
      const M = readInt();
      
      int[] ans;
      foreach (x; 1 .. N + 1) {
        // x, ..., x + N
        int all;
        foreach (i; 0 .. N + 1) {
          // 0 <= i < j <= N, (x + i) + (x + j) <= x + N
          const lb = i + 1;
          const ub = N - x - i;
          if (lb <= ub) {
            all += (ub - lb + 1);
          }
        }
        foreach (y; 0 .. N + 1) {
          // x, ..., x + y - 1, x + y + 1, ..., x + N
          int num = all;
          /*
            0 <= i < j <= y - 1, (x + i) + (x + j) = x + y
            0 <= i < -i - x + y <= y - 1
          */
          {
            const lb = max(0, -x - 1);
            const ub = ((-x + y - 1) - (((-x + y - 1)) & 1)) / 2;
            if (lb <= ub) {
              num -= (ub - lb + 1);
            }
          }
          // 0 <= i <= N, (x + y) + (x + i) <= x + N
          {
            const lb = 0;
            const ub = min(N, N - x - y);
            if (lb <= ub) {
              num -= (ub - lb + 1);
            }
          }
          // (x + y) + (x + y) <= x + N
          if ((x + y) + (x + y) <= x + N) {
            num += 1;
          }
          debug {
            // writeln(x, " ", y, ": ", num);
          }
          if (num == M) {
            ans = iota(x, x + y).array ~ iota(x + y + 1, x + N + 1).array;
            goto found;
          }
        }
      }
      writeln("-1");
      continue;
     found:
      assert(ans.length == N);
      foreach (i; 0 .. N) {
        if (i > 0) write(" ");
        write(ans[i]);
      }
      writeln();
      
      debug {
        bool[int] app;
        foreach (i; 0 .. N) {
          app[ans[i]] = true;
        }
        int cnt;
        foreach (i; 0 .. N) foreach (j; i + 1 .. N) {
          if ((ans[i] + ans[j]) in app) {
            ++cnt;
          }
        }
        assert(cnt == M);
      }
    }
  } catch (EOFException e) {
  }
}