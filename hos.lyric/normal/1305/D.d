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

int Ask(int u, int v) {
  writefln("? %s %s", u + 1, v + 1);
  stdout.flush;
  const res = readInt();
  if (res == -1) {
    import core.stdc.stdlib;
    exit(0);
  }
  return res - 1;
}
void Answer(int r) {
  writefln("! %s", r + 1);
  stdout.flush;
  import core.stdc.stdlib;
  exit(0);
}

int[][] G;
int[] sz;

void dfs(int u, int p) {
  sz[u] = 1;
  foreach (i; G[u]) {
    const v = A[i] ^ B[i] ^ u;
    if (v != p) {
      dfs(v, u);
      sz[u] += sz[v];
    }
  }
}

void main() {
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
  sz = new int[N];
  dfs(0, -1);
  
  int r;
  for (int u = 0; ; ) {
    int vm = -1;
    foreach (i; G[u]) {
      const v = A[i] ^ B[i] ^ u;
      if (vm == -1 || sz[vm] < sz[v]) {
        vm = v;
      }
    }
    if (vm == -1 || sz[u] >= 2 * sz[vm]) {
      r = u;
      break;
    } else {
      sz[u] -= sz[vm];
      sz[vm] += sz[u];
      u = vm;
    }
  }
  debug {
    writeln("r = ", r);
    writeln("sz = ", sz);
  }
  
  for (int u = r, p = -1; ; ) {
    int[] vs;
    foreach (i; G[u]) {
      const v = A[i] ^ B[i] ^ u;
      if (v != p) {
        vs ~= v;
      }
    }
    vs.sort!((v, w) => (sz[v] > sz[w]));
    const vsLen = cast(int)(vs.length);
    int vm = -1;
    foreach (j; 0 .. vsLen / 2) {
      const res = Ask(vs[j * 2], vs[j * 2 + 1]);
      if (res != u) {
        vm = res;
        goto found;
      }
    }
    if (vsLen % 2 != 0) {
      const res = Ask(vs[vsLen - 1], u);
      if (res != u) {
        vm = res;
        goto found;
      }
    }
    Answer(u);
   found:{}
    p = u;
    u = vm;
  }
}