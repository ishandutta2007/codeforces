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
int[][] P;

int[][][] graph;
int zeit;
int[][] rs, dis, fin;

void dfs(int s, int r, int u) {
  rs[s][u] = r;
  dis[s][u] = zeit++;
  foreach (v; graph[s][u]) {
    dfs(s, r, v);
  }
  fin[s][u] = zeit++;
}

void main() {
  try {
    for (; ; ) {
      N = readInt();
      P = new int[][](2, N);
      foreach (u; 0 .. N) {
        const p = readInt() - 1;
        const t = readInt();
        P[0][u] = P[1][u] = -1;
        if (t != -1) {
          P[t][u] = p;
        }
      }
      
      graph = new int[][][](2, N);
      foreach (s; 0 .. 2) {
        foreach (u; 0 .. N) {
          if (P[s][u] != -1) {
            graph[s][P[s][u]] ~= u;
          }
        }
      }
      
      rs = new int[][](2, N);
      dis = new int[][](2, N);
      fin = new int[][](2, N);
      foreach (s; 0 .. 2) {
        rs[s][] = -1;
        zeit = 0;
        foreach (u; 0 .. N) {
          if (rs[s][u] == -1) {
            dfs(s, u, u);
          }
        }
      }
      debug {
        writeln("rs = ", rs);
        writeln("dis = ", dis);
        writeln("fin = ", fin);
      }
      
      const Q = readInt();
      foreach (q; 0 .. Q) {
        const t = readInt();
        const u = readInt() - 1;
        const v = readInt() - 1;
        bool ans;
        if (t == 1) {
          ans = (dis[0][u] < dis[0][v] && fin[0][v] < fin[0][u]);
        } else {
          foreach (r; [rs[1][v], rs[0][u]]) {
            ans = ans || (dis[1][r] < dis[1][v] && fin[1][v] < fin[1][r] && dis[0][r] <= dis[0][u] && fin[0][u] <= fin[0][r]);
          }
        }
        writeln(ans ? "YES" : "NO");
      }
    }
  } catch (EOFException e) {
  }
}