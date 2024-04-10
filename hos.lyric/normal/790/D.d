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


enum E = 18;

void main() {
  try {
    for (; ; ) {
      const N = readInt();
      auto T = new long[][](2, N);
      foreach (i; 0 .. 2) {
        foreach (j; 0 .. N) {
          T[i][j] = readLong();
        }
      }
      
      auto TSum = new long[][](3, N + 1);
      foreach (i; 0 .. 2) {
        foreach (j; 0 .. N) {
          TSum[i][j + 1] = TSum[i][j] + T[i][j];
        }
        TSum[2][] += TSum[i][];
      }
      
      auto nxt = new int[][](3, N + 1);
      foreach (i; 0 .. 3) {
        nxt[i][] = -1;
        int[long] cnt;
        int du;
        void add(int j) {
          if (cnt[TSum[i][j]]++ > 0) {
            ++du;
          }
        }
        void rem(int j) {
          if (--cnt[TSum[i][j]] > 0) {
            --du;
          }
        }
        int l, r;
        void doIt(int jL, int jR, int kL, int kR) {
          if (jR - jL < 1) {
            return;
          }
          const j = (jL + jR) / 2;
          for (; l < j; ) rem(l++);
          for (; l > j; ) add(--l);
          foreach (k; kL .. kR) {
            if (k == N + 1) {
              nxt[i][j] = N + 1;
              break;
            }
            for (; r < k + 1; ) add(r++);
            for (; r > k + 1; ) rem(--r);
            if (du > 0) {
              nxt[i][j] = k;
              break;
            }
          }
          doIt(jL, j, kL, nxt[i][j] + 1);
          doIt(j + 1, jR, nxt[i][j], kR);
        }
        doIt(0, N + 1, 0, N + 1 + 1);
      }
      debug {
        writeln("TSum = ", TSum);
        writeln("nxt = ", nxt);
        foreach (i; 0 .. 3) {
          foreach (j; 0 .. N + 1) {
            int brt = N + 1;
            bool[long] app;
            foreach (k; j .. N + 1) {
              if (TSum[i][k] in app) {
                brt = k;
                break;
              }
              app[TSum[i][k]] = true;
            }
            assert(brt == nxt[i][j]);
          }
        }
      }
      
      auto nxts = new int[][][](3, E, N + 2);
      foreach (i; 0 .. 3) {
        nxts[i][0][0 .. N + 1] = nxt[i][];
        nxts[i][0][N + 1] = N + 1;
        foreach (e; 0 .. E - 1) {
          foreach (j; 0 .. N + 2) {
            nxts[i][e + 1][j] = nxts[i][e][nxts[i][e][j]];
          }
        }
      }
      
      int[long] cache;
      int calc(int x, int y) {
        const key = 1L * x * (N + 1) + y;
        int ret;
        cache.update(key, {
          if (x <= y) {
            int score;
            int xx = x;
            foreach_reverse (e; 0 .. E) {
              if (nxts[0][e][xx] <= y) {
                score += 1 << e;
                xx = nxts[0][e][xx];
              }
            }
            chmax(ret, score);
            if (nxt[2][y] <= N) {
              chmax(ret, score + 1 + calc(nxt[2][y], nxt[2][y]));
            }
            if (nxt[0][xx] <= N) {
              chmax(ret, score + 1 + calc(nxt[0][xx], y));
            }
            if (nxt[1][y] <= N) {
              chmax(ret, score + 1 + calc(xx, nxt[1][y]));
            }
          }
          if (x >= y) {
            int score;
            int yy = y;
            foreach_reverse (e; 0 .. E) {
              if (nxts[1][e][yy] <= x) {
                score += 1 << e;
                yy = nxts[1][e][yy];
              }
            }
            chmax(ret, score);
            if (nxt[2][x] <= N) {
              chmax(ret, score + 1 + calc(nxt[2][x], nxt[2][x]));
            }
            if (nxt[1][yy] <= N) {
              chmax(ret, score + 1 + calc(x, nxt[1][yy]));
            }
            if (nxt[0][x] <= N) {
              chmax(ret, score + 1 + calc(nxt[0][x], yy));
            }
          }
          debug {
            writefln("calc %s %s = %s", x, y, ret);
          }
          return ret;
        }, (ref int r) {
          return ret = r;
        });
        return ret;
      }
      
      const ans = calc(0, 0);
      writeln(ans);
    }
  } catch (EOFException e) {
  }
}