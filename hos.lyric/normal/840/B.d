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


int N, M;
int[] D;
int[] A, B;

int[][] G;
int[] pari;
int[] us;

void dfs(int u, int pi) {
  pari[u] = pi;
  us ~= u;
  foreach (i; G[u]) {
    const v = A[i] ^ B[i] ^ u;
    if (pari[v] == -1) {
      dfs(v, i);
    }
  }
}

void main() {
  try {
    for (; ; ) {
      N = readInt();
      M = readInt();
      D = new int[N];
      foreach (u; 0 .. N) {
        D[u] = readInt();
      }
      A = new int[M];
      B = new int[M];
      foreach (i; 0 .. M) {
        A[i] = readInt() - 1;
        B[i] = readInt() - 1;
      }
      
      G = new int[][N];
      foreach (i; 0 .. M) {
        G[A[i]] ~= i;
        G[B[i]] ~= i;
      }
      pari = new int[N];
      pari[] = -1;
      
      auto ds = D.dup;
      
      bool ans = true;
      int[] edges;
      foreach (r; 0 .. N) {
        if (pari[r] == -1) {
          us = [];
          dfs(r, -2);
          debug {
            writeln("us = ", us);
          }
          const usLen = cast(int)(us.length);
          int sum;
          int[] js;
          foreach (j; 0 .. usLen) {
            if (ds[us[j]] == -1) {
              ds[us[j]] = 0;
              js ~= j;
            } else {
              sum ^= ds[us[j]];
            }
          }
          if (sum) {
            if (js.empty) {
              ans = false;
              break;
            } else {
              ds[us[js[0]]] = 1;
            }
          }
          foreach_reverse (j; 0 .. usLen) {
            if (ds[us[j]]) {
              const i = pari[us[j]];
              const p = A[i] ^ B[i] ^ us[j];
              edges ~= i;
              ds[p] ^= 1;
            }
          }
        }
      }
      
      if (ans) {
        edges.sort;
        writeln(edges.length);
        foreach (i; edges) {
          writeln(i + 1);
        }
      } else {
        writeln(-1);
      }
    }
  } catch (EOFException e) {
  }
}