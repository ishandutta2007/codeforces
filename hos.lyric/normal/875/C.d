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


Tuple!(int, int[]) scc(in int[][][] graph) {
  const n = cast(int)(graph[0].length);
  int compN;
  auto compIds = new int[n];
  int[] us;
  void dfs(int s, int u, int a, int b) {
    if (compIds[u] == a) {
      compIds[u] = b;
      foreach (v; graph[s][u]) {
        dfs(s, v, a, b);
      }
      if (s == 0) {
        us ~= u;
      }
    }
  }
  foreach (u; 0 .. n) {
    dfs(0, u, 0, -1);
  }
  foreach_reverse (u; us) {
    if (compIds[u] == -1) {
      dfs(1, u, -1, compN);
      ++compN;
    }
  }
  return tuple(compN, compIds);
}


void main() {
  try {
    for (; ; ) {
      const N = readInt();
      const M = readInt();
      auto L = new int[N];
      auto S = new int[][N];
      foreach (i; 0 .. N) {
        L[i] = readInt();
        S[i] = new int[L[i]];
        foreach (j; 0 .. L[i]) {
          S[i][j] = readInt() - 1;
        }
      }
      
      bool ans = true;
      auto graph = new int[][][](2, M << 1);
      void addEdge(int x, int y) {
        graph[0][x] ~= y;
        graph[1][y] ~= x;
      }
      
      foreach (i; 0 .. N - 1) {
        for (int j = 0; ; ++j) {
          if (j == L[i]) {
            break;
          } else if (j == L[i + 1]) {
            ans = false;
            break;
          } else {
            const u = S[i][j], v = S[i + 1][j];
            if (u < v) {
              // CAP(u) || NOCAP(v)
              addEdge(u << 1 | 0, v << 1 | 0);
              addEdge(v << 1 | 1, u << 1 | 1);
              break;
            } else if (u > v) {
              // CAP(u) && NOCAP(v)
              addEdge(u << 1 | 0, u << 1 | 1);
              addEdge(v << 1 | 1, v << 1 | 0);
              break;
            }
          }
        }
      }
      auto res = scc(graph);
      foreach (u; 0 .. M) {
        ans = ans && (res[1][u << 1 | 0] != res[1][u << 1 | 1]);
      }
      if (ans) {
        int[] us;
        foreach (u; 0 .. M) {
          if (res[1][u << 1 | 0] < res[1][u << 1 | 1]) {
            us ~= u;
          }
        }
        writeln("Yes");
        writeln(us.length);
        foreach (index, u; us) {
          if (index > 0) write(" ");
          write(u + 1);
        }
        writeln;
      } else {
        writeln("No");
      }
    }
  } catch (EOFException e) {
  }
}