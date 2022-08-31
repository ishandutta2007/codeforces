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
int[] dep;

void dfs(int u, int p) {
  dep[u] = (p == -1) ? 0 : (dep[p] + 1);
  foreach (i; G[u]) {
    const v = A[i] ^ B[i] ^ u;
    if (v != p) {
      dfs(v, u);
    }
  }
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
      int rt = -1;
      foreach (u; 0 .. N) {
        if (G[u].length == 1) {
          rt = u;
          break;
        }
      }
      dep = new int[N];
      dfs(rt, -1);
      
      int ansMin = 1;
      foreach (u; 0 .. N) {
        if (G[u].length == 1) {
          if (dep[u] % 2 != 0) {
            ansMin = 3;
          }
        }
      }
      
      int ansMax;
      auto used = new bool[N];
      foreach (i; 0 .. N - 1) {
        if (G[A[i]].length == 1) {
          used[B[i]] = true;
        } else if (G[B[i]].length == 1) {
          used[A[i]] = true;
        } else {
          ++ansMax;
        }
      }
      foreach (u; 0 .. N) {
        if (used[u]) {
          ++ansMax;
        }
      }
      
      writeln(ansMin, " ", ansMax);
    }
  } catch (EOFException e) {
  }
}