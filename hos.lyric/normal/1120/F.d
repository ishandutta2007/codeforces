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


enum INF = 10L^^18;

void main() {
  try {
    for (; ; ) {
      const N = readInt();
      const C = readLong();
      const D = readLong();
      auto T = new long[N + 1];
      auto P = new string[N];
      foreach (i; 0 .. N) {
        T[i] = readLong();
        P[i] = readToken();
      }
      T[N] = readLong();
      
      auto TSum = new long[N + 2];
      foreach (i; 0 .. N + 1) {
        TSum[i + 1] = TSum[i] + T[i];
      }
      
      long[] crt = [0];
      for (int i = 0, j; i < N; i = j) {
        for (j = i; j < N && P[i] == P[j]; ++j) {}
        long mn = INF;
        foreach (x; 0 .. cast(int)(crt.length)) {
          chmin(mn, crt[x] + C * T[i] * x);
        }
        auto nxt = new long[j - i + 1];
        foreach (y; 1 .. j - i + 1) {
          nxt[y] = mn - C * (T[i] + (TSum[j] - TSum[j - y + 1])) - D * y;
        }
        // from 0
        foreach (y; 1 .. j - i + 1) {
          chmin(nxt[y], 0 - C * (TSum[j] - TSum[j - y]) - D * y);
        }
        debug {
          writeln(i, " ", j, ": ", nxt);
        }
        crt = nxt;
      }
      long ans = INF;
      foreach (x; 0 .. cast(int)(crt.length)) {
        chmin(ans, crt[x] + C * T[N] * x);
      }
      ans += D * N;
      writeln(ans);
      
      debug {
        long brt = INF;
        foreach (p; 0 .. 1 << N) {
          long cost;
          string denP;
          long denCnt;
          foreach (i; 0 .. N) {
            if (p & 1 << i) {
              if (denP != P[i]) {
                cost += C * T[i] * denCnt;
                denP = P[i];
                denCnt = 0;
              }
              cost -= C * T[i];
              ++denCnt;
            } else {
              cost += D;
            }
          }
          cost += C * T[N] * denCnt;
          chmin(brt, cost);
          debug {
            if (cost == 916) {
              foreach (i; 0 .. N) {
                write(cast(char)(P[i][0] + ((p & 1 << i) ? 0 : 32)));
              }
              writeln();
            }
          }
        }
        writeln("brt = ", brt);
        assert(brt == ans);
      }
    }
  } catch (EOFException e) {
  }
}