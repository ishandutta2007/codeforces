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
int[2][] dp;

void dfs(int u, int p) {
  int[] vs;
  foreach (i; G[u]) {
    const v = A[i] ^ B[i] ^ u;
    if (v != p) {
      vs ~= v;
      dfs(v, u);
    }
  }
  const len = cast(int)(vs.length);
  foreach (s; 0 .. 2) {
    int[2] num;
    num[0] = (len + 1) / 2;
    num[1] = (len + 1) - num[0];
    if (num[s] > 0) {
      --num[s];
      int[2][2] cnt;
      foreach (v; vs) {
        ++cnt[dp[v][0]][dp[v][1]];
      }
      if (cnt[0][0] == 0) {
        if (cnt[1][0] <= num[0] && cnt[0][1] <= num[1]) {
          dp[u][s] = 1;
        }
      }
    }
  }
}

int[][] ans;

void recover(int u, int p, int s) {
  int[] vs;
  foreach (i; G[u]) {
    const v = A[i] ^ B[i] ^ u;
    if (v != p) {
      vs ~= v;
    }
  }
  const len = cast(int)(vs.length);
  {
    int[2] num;
    num[0] = (len + 1) / 2;
    num[1] = (len + 1) - num[0];
    if (num[s] > 0) {
      --num[s];
      int[][2] vss;
      foreach (v; vs) {
        if (dp[v][0] && !dp[v][1]) vss[0] ~= v;
        if (!dp[v][0] && dp[v][1]) vss[1] ~= v;
      }
      foreach (v; vs) {
        if (dp[v][0] && dp[v][1]) {
          if (vss[0].length < num[0]) {
            vss[0] ~= v;
          } else {
            vss[1] ~= v;
          }
        }
      }
      bool f;
      int[2] itr;
      foreach_reverse (i; 1 .. (len + 1) + 1) {
        if ((i & 1) == s && !f) {
          if (~p) {
            ans ~= [u, p];
          }
          f = true;
        } else {
          const v = vss[i & 1][itr[i & 1]++];
          recover(v, u, i & 1);
        }
      }
    }
  }
}

void main() {
  try {
    for (; ; ) {
      const numCases = readInt;
      foreach (caseId; 0 .. numCases) {
        N = readInt;
        A = new int[N - 1];
        B = new int[N - 1];
        foreach (i; 0 .. N - 1) {
          A[i] = readInt - 1;
          B[i] = readInt - 1;
        }
        
        G = new int[][N];
        foreach (i; 0 .. N - 1) {
          G[A[i]] ~= i;
          G[B[i]] ~= i;
        }
        dp = new int[2][N];
        dfs(0, -1);
        debug {
          writeln(dp);
        }
        
        const s0 = (G[0].length + 1) & 1;
        if (dp[0][s0]) {
          ans = [];
          recover(0, -1, s0);
          writeln("YES");
          foreach (e; ans) {
            writeln(e[0] + 1, " ", e[1] + 1);
          }
        } else {
          writeln("NO");
        }
      }
    }
  } catch (EOFException e) {
  }
}