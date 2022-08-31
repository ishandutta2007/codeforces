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


enum INF = 10^^9;

int N;
int[] A, B;

int[][] G;
int[] par;

alias Result = Tuple!(int, "min", int, "max");
enum IDENTITY = Result(INF, -INF);
Result mul(const(Result) a, const(Result) b) {
  return Result(min(a.min, b.min), max(a.max, b.max));
}
Result up(const(Result) a) {
  return (a.min >= INF) ? Result(0, 0) : Result(1 + a.min, 1 + a.max);
}

Result[] dp, DP;

void dfs(int u, int p) {
  par[u] = p;
  Result prod = IDENTITY;
  foreach (i; G[u]) {
    const v = A[i] ^ B[i] ^ u;
    if (v != p) {
      dfs(v, u);
      prod = mul(prod, dp[v]);
    }
  }
  dp[u] = up(prod);
}

void DFS(int u, int p) {
  int[] vs;
  foreach (i; G[u]) {
    const v = A[i] ^ B[i] ^ u;
    if (v != p) {
      vs ~= v;
    }
  }
  const len = cast(int)(vs.length);
  auto ls = new Result[len + 1];
  auto rs = new Result[len + 1];
  ls[0] = (p == -1) ? IDENTITY : DP[u];
  foreach (j; 0 .. len) {
    ls[j + 1] = mul(ls[j], dp[vs[j]]);
  }
  rs[len] = IDENTITY;
  foreach_reverse (j; 0 .. len) {
    rs[j] = mul(dp[vs[j]], rs[j + 1]);
  }
  foreach (j; 0 .. len) {
    DP[vs[j]] = up(mul(ls[j], rs[j + 1]));
  }
  foreach (v; vs) {
    DFS(v, u);
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
      par = new int[N];
      dp = new Result[N];
      DP = new Result[N];
      dfs(0, -1);
      DFS(0, -1);
      debug {
        writeln("dp = ", dp);
        writeln("DP = ", DP);
      }
      
      int ans = INF;
      foreach (u; 0 .. N) {
        bool ok = true;
        int[] ms;
        if (par[u] != -1) {
          ok = ok && (DP[u].min == DP[u].max);
          ms ~= DP[u].min;
        }
        foreach (i; G[u]) {
          const v = A[i] ^ B[i] ^ u;
          if (v != par[u]) {
            ok = ok && (dp[v].min == dp[v].max);
            ms ~= dp[v].min;
          }
        }
        ms = ms.sort.uniq.array;
        debug {
          writeln(u, ": ", ok, " ", ms);
        }
        if (ok && ms.length <= 2) {
          const cost = (G[u].length == 1) ? (ms[0] + 1) : (ms[0] + 1 + 1 + ms[$ - 1]);
          chmin(ans, cost >> bsf(cost));
        }
      }
      writeln((ans >= INF) ? -1 : ans);
    }
  } catch (EOFException e) {
  }
}