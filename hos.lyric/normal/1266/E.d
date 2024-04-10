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
      auto A = new long[N];
      foreach (i; 0 .. N) {
        A[i] = readLong();
      }
      const Q = readInt();
      auto S = new int[Q];
      auto T = new int[Q];
      auto U = new int[Q];
      foreach (q; 0 .. Q) {
        S[q] = readInt() - 1;
        T[q] = readInt();
        U[q] = readInt() - 1;
      }
      
      auto us = new int[int][N];
      long now = A.sum;
      auto cs = new long[N];
      void add(int s, int t, int u) {
        if (cs[u] < A[u]) {
          --now;
        }
        ++cs[u];
        us[s][t] = u;
      }
      void remove(int s, int t) {
        const u = us[s][t];
        --cs[u];
        if (cs[u] < A[u]) {
          ++now;
        }
        us[s][t] = -1;
      }
      
      foreach (q; 0 .. Q) {
        if (T[q] in us[S[q]] && us[S[q]][T[q]] != -1) {
          remove(S[q], T[q]);
        }
        if (U[q] != -1) {
          add(S[q], T[q], U[q]);
        }
        writeln(now);
      }
    }
  } catch (EOFException e) {
  }
}