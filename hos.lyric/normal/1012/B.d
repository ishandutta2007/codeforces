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
      const M = readInt();
      const N = readInt();
      const Q = readInt();
      auto R = new int[Q];
      auto C = new int[Q];
      foreach (q; 0 .. Q) {
        R[q] = readInt() - 1;
        C[q] = readInt() - 1;
      }
      
      auto uf = new int[M + N];
      uf[] = -1;
      foreach (q; 0 .. Q) {
        uf.connect(R[q], M + C[q]);
      }
      int num, isoRow, isoCol;
      foreach (u; 0 .. M + N) {
        if (uf[u] < 0) {
          if (-uf[u] >= 2) {
            ++num;
          } else {
            (u < M) ? ++isoRow : ++isoCol;
          }
        }
      }
      debug {
        writeln(num, " ", isoRow, " ", isoCol);
      }
      int ans;
      if (num == 0) {
        ans = M + N - 1;
      } else {
        ans += num - 1;
        ans += isoRow;
        ans += isoCol;
      }
      writeln(ans);
    }
  } catch (EOFException e) {
  }
}