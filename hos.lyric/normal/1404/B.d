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


int N, A, B, C, D;
int[] U, V;

int[][] G;
int[] dep;

void dfs(int u, int p) {
  dep[u] = (p == -1) ? 0 : (dep[p] + 1);
  foreach (i; G[u]) {
    const v = U[i] ^ V[i] ^ u;
    if (v != p) {
      dfs(v, u);
    }
  }
}

void main() {
  try {
    for (; ; ) {
      const numCases = readInt();
      foreach (caseId; 0 .. numCases) {
        N = readInt();
        A = readInt() - 1;
        B = readInt() - 1;
        C = readInt();
        D = readInt();
        U = new int[N - 1];
        V = new int[N - 1];
        foreach (i; 0 .. N - 1) {
          U[i] = readInt() - 1;
          V[i] = readInt() - 1;
        }
        
        G = new int[][N];
        foreach (i; 0 .. N - 1) {
          G[U[i]] ~= i;
          G[V[i]] ~= i;
        }
        
        int ans;
        
        dep = new int[N];
        dfs(A, -1);
        if (dep[B] <= C) {
          ans = 1;
        } else {
          const r = cast(int)(dep.maxIndex);
          dfs(r, -1);
          const diam = dep.maxElement;
          if (2 * C >= min(D, diam)) {
            ans = 1;
          } else {
            ans = 0;
          }
        }
        
        writeln(ans ? "Alice" : "Bob");
      }
    }
  } catch (EOFException e) {
  }
}