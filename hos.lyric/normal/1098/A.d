import std.conv, std.stdio, std.string;
import std.algorithm, std.array, std.bigint, std.container, std.math, std.range, std.regex, std.typecons;
import core.bitop, core.thread;

class EOFException : Throwable { this() { super("EOF"); } }
string[] tokens;
string readToken() { for (; tokens.empty; ) { if (stdin.eof) throw new EOFException; tokens = readln.split; } auto token = tokens[0]; tokens.popFront; return token; }
int readInt() { return readToken().to!int; }
long readLong() { return readToken().to!long; }
real readReal() { return readToken().to!real; }

void chmin(T)(ref T t, in T f) { if (t > f) t = f; }
void chmax(T)(ref T t, in T f) { if (t < f) t = f; }

int binarySearch(T)(in T[] as, in bool delegate(T) test) { int low = -1, upp = cast(int)(as.length); for (; low + 1 < upp; ) { int mid = (low + upp) >> 1; (test(as[mid]) ? low : upp) = mid; } return upp; }
int lowerBound(T)(in T[] as, in T val) { return as.binarySearch((T a) => (a < val)); }
int upperBound(T)(in T[] as, in T val) { return as.binarySearch((T a) => (a <= val)); }


int N;
int[] P;
long[] S;

long solve() {
  auto h = new int[N];
  h[0] = 1;
  foreach (u; 1 .. N) {
    h[u] = h[P[u]] + 1;
  }
  debug {
    writefln("h = %s", h);
  }
  foreach (u; 0 .. N) {
    if ((S[u] == -1) != (h[u] % 2 == 0)) {
      debug {
        writeln("incorrectly erased");
      }
      return -1;
    }
  }
  
  auto graph = new int[][N];
  foreach (u; 1 .. N) {
    graph[P[u]] ~= u;
  }
  
  auto a = new long[N];
  a[0] = S[0];
  foreach (u; 1 .. N) {
    if (S[u] == -1) {
      if (graph[u].empty) {
        a[u] = 0;
      } else {
        a[u] = graph[u].map!(v => S[v]).minElement - S[P[u]];
      }
    } else {
      a[u] = S[u] - S[P[P[u]]] - a[P[u]];
    }
    if (a[u] < 0) {
      debug {
        writeln("negative value needed");
      }
      return -1;
    }
  }
  debug {
    writefln("a = %s", a);
  }
  return a.sum;
}

void main() {
  try {
    for (; ; ) {
      N = readInt();
      P = new int[N];
      S = new long[N];
      foreach (u; 1 .. N) {
        P[u] = readInt() - 1;
      }
      foreach (u; 0 .. N) {
        S[u] = readInt();
      }
      const ans = solve();
      writeln(ans);
    }
  } catch (EOFException e) {
  }
}