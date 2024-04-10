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


enum LIM = 105;

void main() {
  try {
    for (; ; ) {
      const N = readInt();
      const M = readInt();
      const Q = readInt();
      auto W = new int[N];
      foreach (i; 0 .. N) {
        W[i] = readInt();
      }
      
      int readIt() {
        const str = readToken();
        int ret;
        foreach (i; 0 .. N) {
          ret |= (str[i] - '0') << i;
        }
        return ret;
      }
      
      auto S = new int[M];
      foreach (j; 0 .. M) {
        S[j] = readIt();
      }
      auto T = new int[Q];
      auto K = new int[Q];
      foreach (q; 0 .. Q) {
        T[q] = readIt();
        K[q] = readInt();
      }
      
      auto WSum = new int[1 << N];
      foreach (i; 0 .. N) {
        foreach (h; 0 .. 1 << i) {
          WSum[h | 1 << i] = WSum[h] + W[i];
        }
      }
      
      auto cnt = new int[1 << N];
      foreach (j; 0 .. M) {
        ++cnt[S[j]];
      }
      auto anss = new int[][](1 << N, LIM);
      foreach (t; 0 .. 1 << N) {
        foreach (s; 0 .. 1 << N) {
          const w = WSum[((1 << N) - 1) ^ s ^ t];
          if (w < LIM) {
            anss[t][w] += cnt[s];
          }
        }
        foreach (k; 1 .. LIM) {
          anss[t][k] += anss[t][k - 1];
        }
      }
      
      foreach (q; 0 .. Q) {
        writeln(anss[T[q]][K[q]]);
      }
    }
  } catch (EOFException e) {
  }
}