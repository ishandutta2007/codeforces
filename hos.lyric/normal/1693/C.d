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


enum INF = 10^^9;

void main() {
  try {
    for (; ; ) {
      const N = readInt;
      const M = readInt;
      auto A = new int[M];
      auto B = new int[M];
      foreach (i; 0 .. M) {
        A[i] = readInt - 1;
        B[i] = readInt - 1;
      }
      
      auto ds = new int[N];
      auto G = new int[][N];
      foreach (i; 0 .. M) {
        ++ds[A[i]];
        G[B[i]] ~= i;
      }
      
      alias Entry = Tuple!(int, "c", int, "u");
      BinaryHeap!(Array!Entry, "a.c > b.c") que;
      auto vis = new bool[N];
      auto dist = new int[N];
      dist[] = INF;
      dist[N - 1] = 0;
      que.insert(Entry(0, N - 1));
      for (; !que.empty; ) {
        const c = que.front.c;
        const u = que.front.u;
        que.removeFront;
        if (!vis[u]) {
          vis[u] = true;
          foreach (i; G[u]) {
            const v = A[i];
            const cc = c + 1 + (--ds[v]);
            debug {
              writefln("%s <- %s: %s", u, v, cc);
            }
            if (chmin(dist[v], cc)) {
              que.insert(Entry(cc, v));
            }
          }
        }
      }
      debug {
        writeln("dist = ", dist);
      }
      writeln(dist[0]);
    }
  } catch (EOFException e) {
  }
}