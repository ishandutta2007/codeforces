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


int root(int[] uf, int u) {
  return (uf[u] < 0) ? u : (uf[u] = uf.root(uf[u]));
}
bool connect(int[] uf, int u, int v) {
  u = uf.root(u);
  v = uf.root(v);
  if (u == v) return false;
  if (uf[u] > uf[v]) swap(u, v);
  uf[u] += uf[v];
  uf[v] = u;
  return true;
}


void main() {
  try {
    for (; ; ) {
      const N = readInt();
      auto F = new int[N];
      foreach (u; 0 .. N) {
        F[u] = readInt() - 1;
      }
      
      bool ans = true;
      int M;
      auto G = new int[N];
      G[] = -1;
      int[] H;
      
      auto uf = new int[N];
      uf[] = -1;
      foreach (u; 0 .. N) {
        uf.connect(u, F[u]);
      }
      foreach (r; 0 .. N) {
        if (uf[r] < 0) {
          int u = r;
          foreach (_; 0 .. -uf[r]) {
            u = F[u];
          }
          ans = ans && (u == F[u]);
          G[r] = M++;
          H ~= u;
        }
      }
      foreach (u; 0 .. N) {
        G[u] = G[uf.root(u)];
      }
      
      foreach (i; 0 .. M) {
        ans = ans && (G[H[i]] == i);
      }
      foreach (u; 0 .. N) {
        ans = ans && (H[G[u]] == F[u]);
      }
      
      if (ans) {
        writeln(M);
        foreach (u; 0 .. N) {
          if (u > 0) write(" ");
          write(G[u] + 1);
        }
        writeln;
        foreach (i; 0 .. M) {
          if (i > 0) write(" ");
          write(H[i] + 1);
        }
        writeln;
      } else {
        writeln(-1);
      }
    }
  } catch (EOFException e) {
  }
}