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
      const numCases = readInt();
      foreach (caseId; 0 .. numCases) {
        const N = readInt();
        const M = readInt();
        const A = readInt() - 1;
        const B = readInt() - 1;
        auto U = new int[M];
        auto V = new int[M];
        foreach (i; 0 .. M) {
          U[i] = readInt() - 1;
          V[i] = readInt() - 1;
        }
        
        long ans = 1L * (N - 2) * (N - 3) / 2;
        
        int[] doIt(int s) {
          auto uf = new int[N];
          uf[] = -1;
          foreach (i; 0 .. M) {
            if (U[i] != s && V[i] != s) {
              uf.connect(U[i], V[i]);
            }
          }
          foreach (u; 0 .. N) {
            if (uf[u] < 0) {
              long sz = -uf[u];
              if (u == uf.root(A)) --sz;
              if (u == uf.root(B)) --sz;
              ans -= sz * (sz - 1) / 2;
            }
          }
          return uf;
        }
        
        auto ufA = doIt(A);
        auto ufB = doIt(B);
        Tuple!(int, int)[] ts;
        foreach (u; 0 .. N) {
          if (u != A && u != B) {
            ts ~= tuple(ufA.root(u), ufB.root(u));
          }
        }
        ts.sort;
        foreach (grp; ts.group) {
          long sz = grp[1];
          ans += sz * (sz - 1) / 2;
        }
        writeln(ans);
      }
    }
  } catch (EOFException e) {
  }
}