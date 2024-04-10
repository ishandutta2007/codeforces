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


int N, M;
int[] A, B;

int[][] G;
int[] par, dep;
int[] us;
int[][] vss;

void dfs(int u, int p) {
  par[u] = p;
  dep[u] = (p == -1) ? 0 : (dep[p] + 1);
  us ~= u;
  foreach (i; G[u]) {
    const v = A[i] ^ B[i] ^ u;
    if (v != p) {
      if (par[v] == -2) {
        dfs(v, u);
      } else if (dep[u] > dep[v]) {
        vss[u] ~= v;
      }
    }
  }
}

void main() {
  try {
    for (; ; ) {
      N = readInt();
      M = readInt();
      A = new int[M];
      B = new int[M];
      foreach (i; 0 .. M) {
        A[i] = readInt() - 1;
        B[i] = readInt() - 1;
      }
      
      G = new int[][N];
      foreach (i; 0 .. M) {
        G[A[i]] ~= i;
        G[B[i]] ~= i;
      }
      par = new int[N];
      par[] = -2;
      dep = new int[N];
      us = [];
      vss = new int[][N];
      foreach (u; 0 .. N) {
        if (par[u] == -2) {
          dfs(u, -1);
        }
      }
      debug {
        writeln("par = ", par);
        writeln("us = ", us);
        writeln("vss = ", vss);
      }
      
      int[][] ans;
      foreach_reverse (u; us) {
        const vs = vss[u];
        const vsLen = cast(int)(vs.length);
        foreach (j; 0 .. vsLen / 2) {
          ans ~= [vs[j * 2], u, vs[j * 2 + 1]];
        }
        if (par[u] != -1) {
          if (vsLen % 2 == 0) {
            vss[par[u]] ~= u;
          } else {
            ans ~= [vs[vsLen - 1], u, par[u]];
          }
        }
      }
      
      writeln(ans.length);
      foreach (row; ans) {
        writeln(row[0] + 1, " ", row[1] + 1, " ", row[2] + 1);
      }
    }
  } catch (EOFException e) {
  }
}