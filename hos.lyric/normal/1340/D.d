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


int N;
int[] A, B;

int[][] G;
int T, now;
int[][] ans;

void dfs(int u, int p) {
  debug {
    writeln("dfs ", u, " ", p, "; now = ", now);
  }
  int[] vs;
  foreach (i; G[u]) {
    const v = A[i] ^ B[i] ^ u;
    if (v != p) {
      vs ~= v;
    }
  }
  const vsLen = cast(int)(vs.length);
  const start = now;
  foreach (j; 0 .. vsLen) {
    if (now == T) {
      assert(p != -1);
      ans ~= [u, now];
      now = start - 1 - (vsLen - j);
    }
    ans ~= [u, now];
    ++now;
    dfs(vs[j], u);
  }
  if (p != -1 && now > start - 1) {
    ans ~= [u, now];
    now = start - 1;
  }
  ans ~= [u, now];
  ++now;
}

void main() {
  try {
    for (; ; ) {
      N = readInt();
      A = new int[N - 1];
      B = new int[N - 1];
      foreach (i; 0 .. N - 1) {
        A[i] = readInt() - 1;
        B[i] = readInt() - 1;
      }
      
      G = new int[][N];
      foreach (i; 0 .. N - 1) {
        G[A[i]] ~= i;
        G[B[i]] ~= i;
      }
      T = 0;
      foreach (u; 0 .. N) {
        chmax(T, cast(int)(G[u].length));
      }
      now = 0;
      ans = [];
      dfs(0, -1);
      writeln(ans.length);
      foreach (row; ans) {
        writeln(row[0] + 1, " ", row[1]);
      }
    }
  } catch (EOFException e) {
  }
}