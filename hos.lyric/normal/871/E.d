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


int N, K;
int[][] D;

int[][] ans;

string solve() {
  auto us = new int[K];
  us[] = -1;
  foreach (k; 0 .. K) {
    foreach (u; 0 .. N) {
      if (D[k][u] == 0) {
        if (us[k] != -1) {
          return "two zeros";
        }
        us[k] = u;
      }
    }
    if (us[k] == -1) {
      return "no zeros";
    }
  }
  
  auto kss = new int[][N];
  foreach (u; 0 .. N) {
    foreach (k; 1 .. K) {
      if ((D[0][u] + D[k][u] + D[0][us[k]]) % 2 != 0) {
        return "dist parity error";
      }
      if (D[0][us[k]] > D[0][u] + D[k][u]) {
        return "triangle error";
      }
      if (D[0][us[k]] == D[0][u] + D[k][u]) {
        kss[u] ~= k;
      }
    }
  }
  debug {
    writeln("kss = ", kss);
  }
  
  alias Entry = Tuple!(int, "d", int, "u");
  
  // inside
  Entry[] es;
  foreach (u; 0 .. N) {
    if (u == us[0] || !kss[u].empty) {
      es ~= Entry(D[0][u], u);
    }
  }
  es.sort;
  debug {
    writeln("es = ", es);
  }
  auto parss = new int[][](K, N);
  foreach (k; 0 .. K) {
    parss[k][] = -1;
    parss[k][0] = us[0];
  }
  foreach (ref e; es[1 .. $]) {
    if (!(1 <= e.d && e.d < N)) {
      return "dist skipped inside";
    }
    const p = parss[kss[e.u][0]][e.d - 1];
    if (p == -1) {
      return "dist skipped inside";
    }
    ans ~= [p, e.u];
    foreach (k; kss[e.u]) {
      parss[k][e.d] = e.u;
    }
  }
  
  auto uss = new int[][N];
  foreach (u; 0 .. N) {
    if (!(u == us[0] || !kss[u].empty)) {
      int km = 0;
      int dm = D[0][u];
      foreach (k; 1 .. K) {
        const d = (D[0][u] + D[k][u] - D[0][us[k]]) / 2;
        if (chmin(dm, d)) {
          km = k;
        }
      }
      if (!(0 <= D[0][u] - dm && D[0][u] - dm <= D[0][us[km]])) {
        return "out from nothing";
      }
      const r = parss[km][D[0][u] - dm];
      if (r == -1) {
        return "out from nothing";
      }
      uss[r] ~= u;
    }
  }
  debug {
    writeln("uss = ", uss);
  }
  
  // outside
  foreach (r; 0 .. N) {
    Entry[] esOut;
    foreach (u; uss[r]) {
      esOut ~= Entry(D[0][u] - D[0][r], u);
    }
    esOut.sort;
    debug {
      writeln("r = ", r, "; esOut = ", esOut);
    }
    auto pars = new int[uss[r].length + 1];
    pars[] = -1;
    pars[0] = r;
    foreach (ref e; esOut) {
      if (!(1 <= e.d && e.d < pars.length)) {
        return "dist skipped outside";
      }
      const p = pars[e.d - 1];
      if (p == -1) {
        return "dist skipped outside";
      }
      ans ~= [p, e.u];
      pars[e.d] = e.u;
    }
  }
  
  // check
  auto graph = new int[][N];
  foreach (edge; ans) {
    graph[edge[0]] ~= edge[1];
    graph[edge[1]] ~= edge[0];
  }
  foreach (k; 0 .. K) {
    auto que = new int[N];
    int qb, qe;
    auto dist = new int[N];
    dist[] = -1;
    dist[us[k]] = 0;
    que[qe++] = us[k];
    for (; qb != qe; ) {
      const u = que[qb++];
      foreach (v; graph[u]) {
        if (dist[v] == -1) {
          dist[v] = dist[u] + 1;
          que[qe++] = v;
        }
      }
    }
    if (D[k] != dist) {
      return "check failed";
    }
  }
  
  return "";
}

void main() {
  try {
    for (; ; ) {
      N = readInt();
      K = readInt();
      D = new int[][](K, N);
      foreach (k; 0 .. K) {
        foreach (u; 0 .. N) {
          D[k][u] = readInt();
        }
      }
      
      ans = [];
      const msg = solve();
      if (msg == "") {
        debug {
          writeln("ok");
        }
        foreach (edge; ans) {
          writeln(edge[0] + 1, " ", edge[1] + 1);
        }
      } else {
        debug {
          writeln(msg);
        }
        writeln(-1);
      }
    }
  } catch (EOFException e) {
  }
}