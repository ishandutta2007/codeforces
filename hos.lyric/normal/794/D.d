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
      const M = readInt();
      auto A = new int[M];
      auto B = new int[M];
      foreach (i; 0 .. M) {
        A[i] = readInt() - 1;
        B[i] = readInt() - 1;
      }
      
      auto G = new int[][N];
      foreach (i; 0 .. M) {
        G[A[i]] ~= i;
        G[B[i]] ~= i;
      }
      
      DList!int que;
      auto dist = new int[N];
      
      void bfs(int src) {
        dist[] = -1;
        dist[src] = 0;
        que ~= src;
        for (; !que.empty; ) {
          const u = que.front;
          que.removeFront;
          foreach (i; G[u]) {
            const v = A[i] ^ B[i] ^ u;
            if (dist[v] == -1) {
              dist[v] = dist[u] + 1;
              que ~= v;
            }
          }
        }
      }
      
      bfs(0);
      debug {
        writeln("dist = ", dist);
      }
      int um = dist.maxIndex;
      if (dist[um] == 1) {
        foreach (u; 1 .. N) {
          int[] vs;
          foreach (i; G[u]) {
            const v = A[i] ^ B[i] ^ u;
            if (u < v) {
              vs ~= v;
            }
          }
          vs.sort;
          foreach (v; u + 1 .. N) {
            if (!(v - u - 1 < vs.length && vs[v - u - 1] == v)) {
              // no edge uv
              um = u;
              goto found;
            }
          }
        }
      }
     found:
      bfs(um);
      debug {
        writeln("dist = ", dist);
      }
      
      auto touch2 = new bool[N];
      foreach (u; 0 .. N) {
        if (dist[u] == 2) {
          foreach (i; G[u]) {
            const v = A[i] ^ B[i] ^ u;
            touch2[v] = true;
          }
        }
      }
      foreach (u; 0 .. N) {
        if (dist[u] == 1 && !touch2[u]) {
          dist[u] = 0;
        }
      }
      
      bool ok = true;
      foreach (i; 0 .. M) {
        ok = ok && (abs(dist[A[i]] - dist[B[i]]) <= 1);
      }
      
      auto freq = new long[N];
      foreach (u; 0 .. N) {
        ++freq[dist[u]];
      }
      long m;
      foreach (d; 0 .. N) {
        m += freq[d] * (freq[d] - 1) / 2;
      }
      foreach (d; 0 .. N - 1) {
        m += freq[d] * freq[d + 1];
      }
      ok = ok && (m == M);
      
      if (ok) {
        writeln("YES");
        foreach (u; 0 .. N) {
          if (u > 0) write(" ");
          write(dist[u] + 1);
        }
        writeln;
      } else {
        writeln("NO");
      }
    }
  } catch (EOFException e) {
  }
}