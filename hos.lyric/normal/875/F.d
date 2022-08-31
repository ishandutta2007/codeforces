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


alias Edge = Tuple!(int, "a", int, "b", long, "w");

void main() {
  try {
    for (; ; ) {
      const N = readInt();
      const M = readInt();
      auto E = new Edge[M];
      foreach (i; 0 .. M) {
        E[i].a = readInt() - 1;
        E[i].b = readInt() - 1;
        E[i].w = readLong();
      }
      
      E.sort!"a.w < b.w";
      
      auto uf = new int[N];
      uf[] = -1;
      auto ms = new int[N];
      long ans;
      foreach_reverse (ref e; E) {
        const ra = uf.root(e.a);
        const rb = uf.root(e.b);
        if (ra == rb) {
          if (ms[ra] < -uf[ra]) {
            debug {
              writeln(e, " make cycle");
            }
            ans += e.w;
            ++ms[ra];
          }
        } else {
          if (ms[ra] < -uf[ra] || ms[rb] < -uf[rb]) {
            debug {
              writeln(e, " connect");
            }
            ans += e.w;
            uf.connect(ra, rb);
            const int r = uf.root(ra);
            ms[r] = ms[ra] + ms[rb] + 1;
          }
        }
      }
      writeln(ans);
    }
  } catch (EOFException e) {
  }
}