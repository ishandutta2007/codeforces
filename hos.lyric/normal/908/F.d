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
      auto P = new long[N];
      auto C = new char[N];
      foreach (u; 0 .. N) {
        P[u] = readLong();
        C[u] = readToken()[0];
      }
      
      int[] rs, gs, bs;
      foreach (u; 0 .. N) {
        switch (C[u]) {
          case 'R': rs ~= u; break;
          case 'G': gs ~= u; break;
          case 'B': bs ~= u; break;
          default: assert(false);
        }
      }
      
      long ans;
      if (rs.empty || bs.empty) {
        ans = P[N - 1] - P[0];
      } else if (gs.empty) {
        ans = (P[rs[$ - 1]] - P[rs[0]]) + (P[bs[$ - 1]] - P[bs[0]]);
        /*
        if (!rs.empty && !bs.empty) {
          long mn = INF;
          foreach (u; 0 .. N - 1) {
            if (C[u] != C[u + 1]) {
              chmin(mn, P[u + 1] - P[u]);
            }
          }
          ans += mn;
        }
        */
      } else {
        ans = P[gs[$ - 1]] - P[gs[0]];
        foreach (c; ['R', 'B']) {
          foreach (u; 0 .. gs[0]) {
            if (C[u] == c) {
              ans += P[gs[0]] - P[u];
              break;
            }
          }
          foreach_reverse (u; gs[$ - 1] + 1 .. N) {
            if (C[u] == c) {
              ans += P[u] - P[gs[$ - 1]];
              break;
            }
          }
        }
        foreach (j; 1 .. gs.length) {
          const a = gs[j - 1];
          const b = gs[j];
          long[] mxs;
          foreach (c; ['R', 'B']) {
            int[] us;
            us ~= a;
            foreach (u; a + 1 .. b) {
              if (C[u] == c) {
                us ~= u;
              }
            }
            us ~= b;
            long mx;
            foreach (k; 1 .. us.length) {
              chmax(mx, P[us[k]] - P[us[k - 1]]);
            }
            mxs ~= mx;
          }
          ans += min((P[b] - P[a]), ((P[b] - P[a]) - mxs[0]) + ((P[b] - P[a]) - mxs[1]));
        }
      }
      writeln(ans);
    }
  } catch (EOFException e) {
  }
}