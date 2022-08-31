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
int[] par;
int[] gs;

void dfs(int u, int p) {
  par[u] = p;
  gs[u] = 0;
  foreach (i; G[u]) {
    const v = A[i] ^ B[i] ^ u;
    if (v != p) {
      dfs(v, u);
      gs[u] ^= (1 + gs[v]);
    }
  }
}

void main() {
  debug {
    // cycle?, after
    enum lim = 10;
    auto dp = new int[][](lim, lim);
    foreach (a; 1 .. lim) {
      foreach (b; 0 .. lim) {
        bool[int] app;
        app[(a == 1) ? 0 : dp[a - 1][b]] = true;
        foreach (bb; 0 .. b) {
          app[dp[a][bb]] = true;
        }
        for (int g = 0; ; ++g) {
          if (g !in app) {
            dp[a][b] = g;
            break;
          }
        }
      }
      writeln(a, ": ", dp[a]);
    }
  }
  
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
      par = new int[N];
      gs = new int[N];
      dfs(0, -1);
      debug {
        writeln("gs = ", gs);
      }
      
      // u -> par[u]
      auto cut = new bool[N];
      cut[0] = true;
      
      auto ans = new char[N];
      int g = gs[0];
      foreach (u; 0 .. N) {
        for (int v = u; !cut[v]; v = par[v]) {
          cut[v] = true;
          g ^= 1;
          g ^= gs[v];
          g ^= (1 + gs[v]);
        }
        ans[u] = g ? '1' : '2';
      }
      writeln(ans);
    }
  } catch (EOFException e) {
  }
}