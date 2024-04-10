import std.conv, std.functional, std.stdio, std.string;
import std.algorithm, std.array, std.bigint, std.complex, std.container, std.math, std.numeric, std.range, std.regex, std.typecons;
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


int Ask(int u, int v) {
  writefln("? %s %s", u + 1, v + 1);
  stdout.flush;
  const res = readInt();
  if (res == -1) {
    import core.stdc.stdlib;
    exit(0);
  }
  return res;
}
void Answer(int u) {
  writefln("! %s", u + 1);
  stdout.flush;
}

int N, M;
int[] U, V;

int[][][] G;
int C;
int[] scc;
int[] post;

void dfs(int s, int u) {
  scc[u] = C;
  foreach (v; G[s][u]) {
    if (scc[v] == ((s == 0) ? -1 : -2)) {
      dfs(s, v);
    }
  }
  if (s == 0) {
    post ~= u;
  }
}

void main() {
  N = readInt();
  M = readInt();
  U = new int[M];
  V = new int[M];
  foreach (i; 0 .. M) {
    U[i] = readInt() - 1;
    V[i] = readInt() - 1;
  }
  
  G = new int[][][](2, N);
  foreach (i; 0 .. M) {
    G[0][U[i]] ~= V[i];
    G[1][V[i]] ~= U[i];
  }
  C = -2;
  scc = new int[N];
  scc[] = -1;
  foreach (u; 0 .. N) {
    if (scc[u] == -1) {
      dfs(0, u);
    }
  }
  C = 0;
  foreach_reverse (u; post) {
    if (scc[u] == -2) {
      dfs(1, u);
      ++C;
    }
  }
  debug {
    writeln("scc = ", scc);
  }
  
  auto H = new int[][C];
  auto inDeg = new int[C];
  foreach (i; 0 .. M) {
    const c = scc[U[i]], d = scc[V[i]];
    if (c != d) {
      H[c] ~= d;
      ++inDeg[d];
    }
  }
  
  auto ls = new DList!int[C];
  foreach (u; 0 .. N) {
    ls[scc[u]].insertBack(u);
  }
  DList!int q;
  foreach (c; 0 .. C) {
    if (inDeg[c] == 0) {
      q.insertBack(c);
    }
  }
  
  int src = ls[q.front].front;
  for (; ; ) {
    debug {
      writeln("ls = ", ls.map!(l => l[]));
      writeln("q = ", q[]);
    }
    if (q.front == scc[src]) {
      const c0 = q.front; q.removeFront;
      if (q.empty) {
        break;
      }
      const c1 = q.front; q.removeFront;
      q.insertFront(c0);
      q.insertFront(c1);
    }
    int u = ls[q.front].front;
    if (Ask(src, u) == 0) {
      swap(src, u);
    }
    const c = scc[u];
    if (q.front != c) {
      const c0 = q.front; q.removeFront;
      const c1 = q.front; q.removeFront;
      q.insertFront(c0);
      q.insertFront(c1);
    }
    ls[c].removeFront;
    if (ls[c].empty) {
      q.removeFront;
      foreach (d; H[c]) {
        if (--inDeg[d] == 0) {
          q.insertBack(d);
        }
      }
    }
  }
  Answer(src);
}