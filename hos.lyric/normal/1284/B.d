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




void main() {
  try {
    for (; ; ) {
      const N = readInt();
      auto L = new int[N];
      auto S = new int[][N];
      foreach (i; 0 .. N) {
        L[i] = readInt();
        S[i] = new int[L[i]];
        foreach (x; 0 .. L[i]) {
          S[i][x] = readInt();
        }
      }
      
      auto decr = new bool[N];
      foreach (i; 0 .. N) {
        decr[i] = true;
        foreach (x; 0 .. L[i] - 1) {
          decr[i] = decr[i] && (S[i][x] >= S[i][x + 1]);
        }
      }
      
      int lim;
      foreach (i; 0 .. N) {
        foreach (x; 0 .. L[i]) {
          chmax(lim, S[i][x]);
        }
      }
      lim += 10;
      auto fs = new long[lim];
      foreach (i; 0 .. N) {
        if (decr[i]) {
          ++fs[S[i][0]];
        }
      }
      foreach (a; 1 .. lim) {
        fs[a] += fs[a - 1];
      }
      
      long ans = 1L * N * N;
      foreach (i; 0 .. N) {
        if (decr[i]) {
          ans -= fs[S[i][L[i] - 1]];
        }
      }
      writeln(ans);
    }
  } catch (EOFException e) {
  }
}