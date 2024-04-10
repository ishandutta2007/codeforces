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

int[][][] G;

int[] vis;
bool[][] viss;

bool dfsTop(int u) {
  vis[u] = 1;
  foreach (i; G[0][u]) {
    const v = A[i] ^ B[i] ^ u;
    if (vis[v] == 0) {
      if (!dfsTop(v)) {
        return false;
      }
    } else if (vis[v] == 1) {
      return false;
    }
  }
  vis[u] = 2;
  return true;
}

void dfs(int s, int u) {
  viss[s][u] = true;
  foreach (i; G[s][u]) {
    const v = A[i] ^ B[i] ^ u;
    if (!viss[s][v]) {
      dfs(s, v);
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
      
      G = new int[][][](2, N);
      foreach (i; 0 .. M) {
        G[0][A[i]] ~= i;
        G[1][B[i]] ~= i;
      }
      
      vis = new int[N];
      bool ok = true;
      foreach (u; 0 .. N) {
        if (vis[u] == 0) {
          if (!dfsTop(u)) {
            ok = false;
          }
        }
      }
      if (ok) {
        viss = new bool[][](2, N);
        int ansCnt;
        auto ans = new char[N];
        ans[] = 'E';
        foreach (u; 0 .. N) {
          if (!viss[0][u] && !viss[1][u]) {
            ++ansCnt;
            ans[u] = 'A';
          }
          foreach (s; 0 .. 2) {
            if (!viss[s][u]) {
              dfs(s, u);
            }
          }
        }
        writeln(ansCnt);
        writeln(ans);
      } else {
        writeln(-1);
      }
    }
  } catch (EOFException e) {
  }
}