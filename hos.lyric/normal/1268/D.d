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
      auto A = new string[N];
      foreach (u; 0 .. N) {
        A[u] = readToken();
      }
      
      auto a = new int[][](N, N);
      auto deg = new int[N];
      foreach (u; 0 .. N) foreach (v; 0 .. N) {
        a[u][v] = A[u][v] - '0';
        deg[u] += a[u][v];
      }
      
      void flip(int u) {
        foreach (v; 0 .. N) {
          if (u != v) {
            deg[u] -= a[u][v];
            deg[v] -= a[v][u];
            swap(a[u][v], a[v][u]);
            deg[u] += a[u][v];
            deg[v] += a[v][u];
          }
        }
      }
      bool check() {
        auto ds = deg.dup.sort;
        int sum;
        foreach (j; 1 .. N) {
          sum += ds[j - 1];
          if (sum == j * (j - 1) / 2) {
            return false;
          }
        }
        return true;
      }
      
      int ansNum = N + 1;
      long ansCnt;
      void doIt(int num) {
        if (chmin(ansNum, num)) {
          ansCnt = 0;
        }
        if (ansNum == num) {
          ++ansCnt;
        }
      }
      
      if (N <= 8) {
        foreach (p; 0 .. 1 << N) {
          foreach (u; 0 .. N) {
            if (p & 1 << u) {
              flip(u);
            }
          }
          if (check()) {
            doIt(popcnt(p));
          }
          foreach (u; 0 .. N) {
            if (p & 1 << u) {
              flip(u);
            }
          }
        }
      } else {
        if (check()) {
          doIt(0);
        }
        foreach (u; 0 .. N) {
          flip(u);
          if (check()) {
            doIt(1);
          }
          flip(u);
        }
      }
      if (ansNum > N) {
        writeln(-1);
      } else {
        foreach (k; 1 .. ansNum + 1) {
          ansCnt *= k;
        }
        writeln(ansNum, " ", ansCnt);
      }
    }
  } catch (EOFException e) {
  }
}