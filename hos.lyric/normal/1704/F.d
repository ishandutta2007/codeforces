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


// https://oeis.org/A002187
enum LIM = 1000;
enum PER = 34;
int[] gs;
void init() {
  gs = new int[LIM];
  foreach (n; 0 .. LIM) {
    bool[int] app;
    for (int k = 0; k <= n - 2 - k; ++k) {
      app[gs[k] ^ gs[n - 2 - k]] = true;
    }
    for (int x = 0; ; ++x) {
      if (x !in app) {
        gs[n] = x;
        break;
      }
    }
  }
  debug {
    writeln("gs = ", gs);
  }
  foreach (n; LIM / 2 .. LIM) {
    assert(gs[n - PER] == gs[n]);
  }
}
int getG(int n) {
  if (n >= LIM) {
    n = (LIM - PER) + (n - (LIM - PER)) % PER;
  }
  return gs[n];
}

int N;
string S;

bool solve() {
  auto A = S.map!(s => ((s == 'B') ? 1 : 0)).array;
  int[2] cnt;
  foreach (i; 0 .. N) {
    ++cnt[A[i]];
  }
  if (cnt[0] > cnt[1]) return true;
  if (cnt[0] < cnt[1]) return false;
  
  int sum;
  for (int i = 0, j; i < N; i = j) {
    for (j = i; j < N && (A[i] ^ (i & 1)) == (A[j] ^ (j & 1)); ++j) {}
    const g = getG(j - i);
    debug {
      writeln("  ", S[i .. j], " ", g);
    }
    sum ^= g;
  }
  return (sum != 0);
}

void main() {
  /*
  debug {{
    foreach (n; 2 .. 8 + 1) {
      auto dp = new int[][](3^^n, 2);
      foreach (p; 0 .. 3^^n) {
        const s = iota(n).map!(i => "012"[p / 3^^i % 3]).array;
        foreach (turn; 0 .. 2) {
          const me = "12"[turn];
          bool[int] app;
          foreach (i; 0 .. n - 1) {
            if (s[i] == me || s[i + 1] == me) {
              int pp = p;
              pp -= (s[i] - '0') * 3^^i;
              pp -= (s[i + 1] - '0') * 3^^(i + 1);
              app[dp[pp][turn ^ 1]] = true;
            }
          }
          for (int x = 0; ; ++x) {
            if (x !in app) {
              dp[p][turn] = x;
              break;
            }
          }
        }
        int[2] cnt;
        foreach (turn; 0 .. 2) {
          cnt[turn] = cast(int)(s.count("12"[turn]));
        }
        if (cnt[0] > cnt[1]) {
          assert(dp[p][0]);
          assert(!dp[p][1]);
        } else if (cnt[0] < cnt[1]) {
          assert(!dp[p][0]);
          assert(dp[p][1]);
        } else {
          writeln(s, " ", dp[p]);
        }
      }
      stdout.flush;
    }
    return;
  }}
  */
  
  init;
  
  try {
    for (; ; ) {
      const numCases = readInt;
      foreach (caseId; 0 .. numCases) {
        N = readInt;
        S = readToken;
        
        const ans = solve;
        writeln(ans ? "Alice" : "Bob");
      }
    }
  } catch (EOFException e) {
  }
}