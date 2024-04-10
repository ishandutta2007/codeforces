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


int N;
int[] A, B;

int[][] G;
int[] sz;

void dfsSz(int u, int p) {
  sz[u] = 1;
  foreach (i; G[u]) {
    const v = A[i] ^ B[i] ^ u;
    if (v != p) {
      dfsSz(v, u);
      sz[u] += sz[v];
    }
  }
}

void main() {
  try {
    for (; ; ) {
      N = readInt();
      A = new int[N - 1];
      B = new int[N - 1];
      foreach (i; 0 .. N - 1) {
        A[i] = readInt() - 1;
        B[i] = readInt() - 1;
      }
      
      G = new int[][N];
      foreach (i; 0 .. N - 1) {
        G[A[i]] ~= i;
        G[B[i]] ~= i;
      }
      sz = new int[N];
      dfsSz(0, -1);
      
      int[] rs;
      for (int u = 0; ; ) {
        int vm = -1;
        foreach (i; G[u]) {
          const v = A[i] ^ B[i] ^ u;
          if (vm == -1 || sz[vm] < sz[v]) {
            vm = v;
          }
        }
        if (vm == -1 || sz[u] >= 2 * sz[vm]) {
          rs ~= u;
          if (sz[u] == 2 * sz[vm]) {
            rs ~= vm;
          }
          break;
        } else {
          sz[u] -= sz[vm];
          sz[vm] += sz[u];
          u = vm;
        }
      }
      debug {
        writeln("rs = ", rs);
      }
      
      int[][] ans;
      auto par = new int[N];
      foreach (r; rs) {
        foreach (j; G[r]) {
          const s = A[j] ^ B[j] ^ r;
          if (rs.count(s) == 0) {
            int[] us;
            void dfs(int u, int p) {
              us ~= u;
              par[u] = p;
              foreach (i; G[u]) {
                const v = A[i] ^ B[i] ^ u;
                if (v != p) {
                  dfs(v, u);
                }
              }
            }
            dfs(s, r);
            debug {
              writeln(r, " ", s, " ", us);
            }
            int now = s;
            foreach (u; us) {
              if (par[u] != r) {
                ans ~= [r, now, u];
                now = u;
                ans ~= [u, par[u], s];
              }
            }
            ans ~= [r, now, s];
          }
        }
      }
      
      ans = ans.filter!(row => (row[1] != row[2])).array;
      
      writeln(ans.length);
      foreach (row; ans) {
        writeln(row[0] + 1, " ", row[1] + 1, " ", row[2] + 1);
      }
    }
  } catch (EOFException e) {
  }
}