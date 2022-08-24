import std.conv, std.functional, std.stdio, std.string;
import std.algorithm, std.array, std.bigint, std.complex, std.container, std.math, std.numeric, std.range, std.regex, std.typecons;
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


enum INF = 3 * 10L^^18;

int N;
long[] S;
int Q;
long[] L, R;

void main() {
  try {
    for (; ; ) {
      N = readInt();
      S = new long[N];
      foreach (i; 0 .. N) {
        S[i] = readLong();
      }
      Q = readInt();
      L = new long[Q];
      R = new long[Q];
      foreach (q; 0 .. Q) {
        L[q] = readLong();
        R[q] = readLong();
      }
      
      S.sort;
      
      auto ds = new long[N];
      foreach (i; 0 .. N - 1) {
        ds[i] = S[i + 1] - S[i];
      }
      ds[N - 1] = INF;
      ds.sort;
      
      auto dsSum = new long[N + 1];
      foreach (i; 0 .. N) {
        dsSum[i + 1] = dsSum[i] + ds[i];
      }
      
      auto ans = new long[Q];
      foreach (q; 0 .. Q) {
        const pos = ds.lowerBound(R[q] - L[q] + 1);
        ans[q] = dsSum[pos] + (R[q] - L[q] + 1) * (N - pos);
      }
      foreach (q; 0 .. Q) {
        if (q > 0) {
          write(" ");
        }
        write(ans[q]);
      }
      writeln();
    }
  } catch (EOFException e) {
  }
}