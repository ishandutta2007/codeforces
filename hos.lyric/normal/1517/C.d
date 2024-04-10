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


void solve(const(int) N, const(int[]) P) {
  auto ans = new int[][](N + 2, N + 2);
  foreach (i; 1 .. N + 1) {
    int x = i, y = i;
    ans[x][y] = P[i];
    foreach (_; 1 .. P[i]) {
      if (y - 1 >= 1 && !ans[x][y - 1]) {
        ans[x][y - 1] = P[i];
        --y;
      } else if (x + 1 <= N && !ans[x + 1][y]) {
        ans[x + 1][y] = P[i];
        ++x;
      } else {
        assert(false);
      }
    }
  }
  foreach (i; 1 .. N + 1) {
    foreach (j; 1 .. i + 1) {
      if (j > 1) write(" ");
      write(ans[i][j]);
    }
    writeln;
  }
}

void main() {
  debug {
    foreach (n; 1 .. 8 + 1) {
      auto perm = iota(n + 1).array;
      do {
        writeln(perm);
        solve(n, perm);
      } while (perm[1 .. n + 1].nextPermutation);
    }
  }
  
  try {
    for (; ; ) {
      const N = readInt();
      auto P = new int[N + 1];
      foreach (i; 1 .. N + 1) {
        P[i] = readInt();
      }
      
      solve(N, P);
    }
  } catch (EOFException e) {
  }
}