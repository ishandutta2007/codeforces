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


int N, M;
int[] A, B;

int[][] G;
bool[] vis;
int[] us;

void dfs(int u) {
  if (!vis[u]) {
    vis[u] = true;
    foreach (i; G[u]) {
      dfs(B[i]);
    }
    us ~= u;
  }
}

void main() {
  N = readInt();
  M = readInt();
  const T = readInt();
  A = new int[M];
  B = new int[M];
  foreach (i; 0 .. M) {
    A[i] = readInt() - 1;
    B[i] = readInt() - 1;
  }
  
  G = new int[][N];
  foreach (i; 0 .. M) {
    G[A[i]] ~= i;
  }
  vis = new bool[N];
  foreach (u; 0 .. N) {
    dfs(u);
  }
  debug {
    writeln("us = ", us);
  }
  
  auto ids = new int[N];
  foreach (x; 0 .. N) {
    ids[us[x]] = x;
  }
  auto adj = new bool[][](N, N);
  foreach (i; 0 .. M) {
    adj[ids[A[i]]][ids[B[i]]] = true;
  }
  alias Entry = Tuple!(char, "sig", int, "x", int, "y");
  Entry[] es;
  void add(int x, int y) {
    assert(!adj[x][y]);
    adj[x][y] = true;
    es ~= Entry('+', x, y);
  }
  void rem(int x, int y) {
    assert(adj[x][y]);
    adj[x][y] = false;
    es ~= Entry('-', x, y);
  }
  void flip(int x, int y) {
    if (!adj[x][y]) {
      add(x, y);
    } else {
      rem(x, y);
    }
  }
  
  debug {
    const K = min(N, 2);
  } else {
    const K = min(N, 20);
  }
  foreach (x; 0 .. K) {
    foreach (y; 0 .. N) {
      if (x != y) {
        if (adj[x][y] != (y < x)) {
          flip(x, y);
        }
      }
    }
  }
  int[] ps;
  foreach (l; 0 .. 3 + 1) {
    foreach (p; 0 .. 1 << K) {
      if (popcnt(p) == l) {
        ps ~= p;
      }
    }
  }
  auto tr = new int[1 << K];
  tr[] = -1;
  foreach (x; K .. N) {
    add(x, x);
    int key;
    foreach (y; 0 .. K) {
      if (adj[x][y]) {
        key ^= 1 << y;
      }
    }
    foreach (p; ps) {
      const q = key ^ p;
      if (tr[q] == -1 && q != (1 << K) - 1) {
        tr[q] = x;
        foreach (y; 0 .. K) {
          if (p & 1 << y) {
            flip(x, y);
          }
        }
        break;
      }
    }
  }
  
  writeln(es.length);
  foreach (ref e; es) {
    writefln("%s %s %s", e.sig, us[e.x] + 1, us[e.y] + 1);
  }
  stdout.flush;
  
  int ask(int[] xs) {
    writef("? %s", xs.length);
    foreach (x; xs) {
      writef(" %s", us[x] + 1);
    }
    writeln;
    stdout.flush;
    const res = readToken();
    switch (res) {
      case "Win": return +1;
      case "Lose": return 0;
      case "Draw": return -1;
      default: assert(false);
    }
  }
  
  foreach (t; 0 .. T) {
    auto ress = new int[K];
    foreach (x; 0 .. K) {
      ress[x] = ask([x]);
    }
    int ans = -1;
    if (ress.all!"a != -1") {
      foreach (x; 0 .. K) {
        if (ress[x] == 0) {
          ans = x;
        }
      }
    } else {
      int p;
      foreach (x; 0 .. K) {
        if (ress[x] == 1) {
          p ^= 1 << x;
        }
      }
      ans = tr[p];
    }
    writefln("! %s", us[ans] + 1);
    stdout.flush;
    const verdict = readToken();
    assert(verdict == "Correct");
  }
}