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


enum INF = 10L^^13;

void main() {
  try {
    for (; ; ) {
      const N = readInt();
      const M = readInt();
      const K = readInt();
      auto D = new int[M];
      auto S = new int[M];
      auto T = new int[M];
      auto C = new long[M];
      foreach (i; 0 .. M) {
        D[i] = readInt();
        S[i] = readInt() - 1;
        T[i] = readInt() - 1;
        C[i] = readLong();
      }
      
      const dLim = (M == 0) ? 1 : (D.maxElement + 1);
      auto iss = new int[][dLim];
      foreach (i; 0 .. M) {
        iss[D[i]] ~= i;
      }
      
      auto ls = new long[dLim];
      auto rs = new long[dLim];
      
      long now;
      auto mns = new long[N];
      
      mns[] = INF;
      now = N * INF;
      foreach (d; 0 .. dLim) {
        foreach (i; iss[d]) {
          if (T[i] == -1) {
            now -= mns[S[i]];
            chmin(mns[S[i]], C[i]);
            now += mns[S[i]];
          }
        }
        ls[d] = now;
      }
      
      mns[] = INF;
      now = N * INF;
      foreach_reverse (d; 0 .. dLim) {
        foreach (i; iss[d]) {
          if (S[i] == -1) {
            now -= mns[T[i]];
            chmin(mns[T[i]], C[i]);
            now += mns[T[i]];
          }
        }
        rs[d] = now;
      }
      
      long ans = INF;
      foreach (d; 0 .. dLim - K - 1) {
        chmin(ans, ls[d] + rs[d + K + 1]);
      }
      writeln((ans >= INF) ? -1 : ans);
    }
  } catch (EOFException e) {
  }
}