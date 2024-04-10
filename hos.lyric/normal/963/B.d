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
int[] P;
int[][] G;

int[] sz;

void dfs0(int u, int p) {
  sz[u] = 1;
  foreach (v; G[u]) {
    if (v != p) {
      dfs0(v, u);
      sz[u] += sz[v];
    }
  }
}

int[] ans;

void dfs1(int u, int p) {
  foreach (v; G[u]) {
    if (v != p) {
      if (sz[v] % 2 == 0) {
        dfs1(v, u);
      }
    }
  }
  ans ~= u;
  foreach (v; G[u]) {
    if (v != p) {
      if (sz[v] % 2 != 0) {
        dfs1(v, u);
      }
    }
  }
}

void main() {
  try {
    for (; ; ) {
      N = readInt();
      P = new int[N];
      foreach (u; 0 .. N) {
        P[u] = readInt() - 1;
      }
      
      if (N % 2 == 0) {
        writeln("NO");
      } else {
        G = new int[][N];
        foreach (u; 0 .. N) {
          if (P[u] != -1) {
            G[u] ~= P[u];
            G[P[u]] ~= u;
          }
        }
        sz = new int[N];
        dfs0(0, -1);
        ans = [];
        dfs1(0, -1);
        writeln("YES");
        foreach (u; ans) {
          writeln(u + 1);
        }
      }
    }
  } catch (EOFException e) {
  }
}