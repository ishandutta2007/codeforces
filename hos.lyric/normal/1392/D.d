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

bool isOk(int s, int t, int u) {
  if (s == 0 && u == 0) return (t == 1);
  if (s == 1 && u == 1) return (t == 0);
  return true;
}

void main() {
  try {
    for (; ; ) {
      const numCases = readInt();
      foreach (caseId; 0 .. numCases) {
        const N = readInt();
        const S = readToken();
        
        int cost(int i, int s) {
          return (S[i] != "LR"[s]) ? 1 : 0;
        }
        
        int ans = INF;
        foreach (a0; 0 .. 2) foreach (a1; 0 .. 2) {
          auto dp = new int[][][](N + 1, 2, 2);
          foreach (i; 0 .. N + 1) {
            foreach (s; 0 .. 2) foreach (t; 0 .. 2) {
              dp[i][s][t] = INF;
            }
          }
          dp[2][a0][a1] = cost(0, a0) + cost(1, a1);
          foreach (i; 2 .. N) {
            foreach (s; 0 .. 2) foreach (t; 0 .. 2) {
              if (dp[i][s][t] < INF) {
                foreach (u; 0 .. 2) {
                  if (isOk(s, t, u)) {
                    chmin(dp[i + 1][t][u], dp[i][s][t] + cost(i, u));
                  }
                }
              }
            }
          }
          foreach (s; 0 .. 2) foreach (t; 0 .. 2) {
            if (isOk(s, t, a0) && isOk(t, a0, a1)) {
              chmin(ans, dp[N][s][t]);
            }
          }
        }
        writeln(ans);
      }
    }
  } catch (EOFException e) {
  }
}