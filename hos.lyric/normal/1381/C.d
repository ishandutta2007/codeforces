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
      const numCases = readInt();
      foreach (caseId; 0 .. numCases) {
        const N = readInt();
        const X = readInt();
        const Y = readInt();
        auto B = new int[N];
        foreach (i; 0 .. N) {
          B[i] = readInt();
        }
        
        const M = N + 2;
        auto iss = new int[][M];
        foreach (i; 0 .. N) {
          iss[B[i]] ~= i;
        }
        int fake;
        foreach (b; 1 .. M) {
          if (iss[b].empty) {
            fake = b;
            break;
          }
        }
        
        int mLim;
        foreach (m; 0 .. N - X + 1) {
          if (min(2 * (N - X - m), N - X) >= Y - X) {
            chmax(mLim, m);
          }
        }
        debug {
          writeln("mLim = ", mLim);
        }
        
        int must;
        foreach (b; 1 .. M) {
          const len = cast(int)(iss[b].length);
          must += max(len - mLim, 0);
        }
        if (must <= X) {
          int[] hits;
          foreach (b; 1 .. M) {
            const len = cast(int)(iss[b].length);
            if (len - mLim >= 0) {
              hits ~= iss[b][mLim .. len];
              iss[b].length = mLim;
            }
          }
          int x = X - must;
          foreach (b; 1 .. M) {
            const len = cast(int)(iss[b].length);
            const tmp = min(len, x);
            hits ~= iss[b][len - tmp .. len];
            iss[b].length = len - tmp;
            x -= tmp;
          }
          debug {
            writeln("hits = ", hits);
            writeln("iss = ", iss);
          }
          auto ans = new int[N];
          ans[] = fake;
          foreach (i; hits) {
            ans[i] = B[i];
          }
          int bm;
          foreach (b; 1 .. M) {
            if (iss[bm].length < iss[b].length) {
              bm = b;
            }
          }
          if (2 * iss[bm].length <= N - X) {
            int[] blows;
            foreach (b; 1 .. M) {
              blows ~= iss[b];
            }
            foreach (j; 0 .. Y - X) {
              ans[blows[j]] = B[blows[(j + (N - X) / 2) % (N - X)]];
            }
          } else {
            int[] others;
            foreach (b; 1 .. M) {
              if (b != bm) {
                others ~= iss[b];
              }
            }
            const othersLen = cast(int)(others.length);
            assert(2 * othersLen >= Y - X);
            int y = Y - X;
            foreach (j; 0 .. othersLen) {
              if (y > 0) {
                ans[others[j]] = B[iss[bm][j]];
                --y;
              }
            }
            foreach (j; 0 .. othersLen) {
              if (y > 0) {
                ans[iss[bm][j]] = B[others[j]];
                --y;
              }
            }
          }
          writeln("YES");
          foreach (i; 0 .. N) {
            if (i > 0) write(" ");
            write(ans[i]);
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