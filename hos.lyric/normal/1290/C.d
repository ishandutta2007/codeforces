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


int root(int[] uf, int u) {
  return (uf[u] < 0) ? u : (uf[u] = uf.root(uf[u]));
}
bool connect(int[] uf, int u, int v) {
  u = uf.root(u);
  v = uf.root(v);
  if (u == v) return false;
  if (uf[u] > uf[v]) swap(u, v);
  uf[u] += uf[v];
  uf[v] = u;
  return true;
}


int M, K;
string S;
int[] C;
int[][] X;

int[][] uss;
int[][] graph;
int[] colors;

void dfs(int u) {
  foreach (i; graph[u]) {
    const v = uss[i][0] ^ uss[i][1] ^ u;
    if (colors[v] == -1) {
      colors[v] = (colors[u] ^ ('1' - S[i]));
      dfs(v);
    }
    assert(colors[v] == (colors[u] ^ ('1' - S[i])));
  }
}

void main() {
  try {
    for (; ; ) {
      M = readInt();
      K = readInt();
      S = readToken();
      C = new int[K];
      X = new int[][K];
      foreach (u; 0 .. K) {
        C[u] = readInt();
        X[u] = new int[C[u]];
        foreach (j; 0 .. C[u]) {
          X[u][j] = readInt() - 1;
        }
      }
      
      uss = new int[][M];
      foreach (u; 0 .. K) {
        foreach (j; 0 .. C[u]) {
          uss[X[u][j]] ~= u;
        }
      }
      graph = new int[][K + 1];
      foreach (i; 0 .. M) {
        switch (uss[i].length) {
          case 0: {
            // no edge
          } break;
          case 1: {
            uss[i] ~= K;
            graph[uss[i][0]] ~= i;
            graph[uss[i][1]] ~= i;
          } break;
          case 2: {
            graph[uss[i][0]] ~= i;
            graph[uss[i][1]] ~= i;
          } break;
          default: assert(false);
        }
      }
      debug {
        writeln("uss = ", uss);
      }
      colors = new int[K + 1];
      colors[] = -1;
      foreach_reverse (u; 0 .. K + 1) {
        if (colors[u] == -1) {
          colors[u] = 0;
          dfs(u);
        }
      }
      debug {
        writeln("colors = ", colors);
      }
      
      int ans;
      auto nums = new int[][](K + 1, 2);
      foreach (u; 0 .. K + 1) {
        ++nums[u][colors[u]];
      }
      auto uf = new int[K + 1];
      uf[] = -1;
      int get(int r) {
        if (uf.root(K) == r) {
          return nums[r][1];
        } else {
          return min(nums[r][0], nums[r][1]);
        }
      }
      
      foreach (i; 0 .. M) {
        if (uss[i]) {
          int ru = uf.root(uss[i][0]);
          int rv = uf.root(uss[i][1]);
          if (ru != rv) {
            ans -= get(ru);
            ans -= get(rv);
            uf.connect(ru, rv);
            if (ru != uf.root(ru)) {
              swap(ru, rv);
            }
            nums[ru][] += nums[rv][];
            ans += get(ru);
          }
        }
        writeln(ans);
      }
    }
  } catch (EOFException e) {
  }
}