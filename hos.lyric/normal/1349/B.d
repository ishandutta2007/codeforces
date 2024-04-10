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


bool solve(int[] as) {
  const n = cast(int)(as.length);
  const cnt1 = as.count(1);
  if (cnt1 == 0) {
    return false;
  }
  if (cnt1 == n) {
    return true;
  }
  foreach (i; 0 .. n - 2 + 1) {
    if (as[i] >= 1 && as[i + 1] >= 1) {
      return true;
    }
  }
  foreach (i; 0 .. n - 3 + 1) {
    if (as[i] >= 1 && as[i + 2] >= 1) {
      return true;
    }
  }
  return false;
}

void main() {
  debug {
    enum lim = 8;
    foreach (n; 1 .. lim + 1) {
      auto graph = new int[][3^^n];
      foreach (u; 0 .. 3^^n) {
        auto as = new int[n];
        foreach (i; 0 .. n) {
          as[i] = u / 3^^i % 3;
        }
        foreach (i; 0 .. n) foreach (j; i + 1 .. n + 1) {
          auto bs = as[i .. j].dup;
          bs.sort;
          auto cs = as.dup;
          cs[i .. j] = bs[($ + 1) / 2 - 1];
          int v;
          foreach_reverse (k; 0 .. n) {
            v = v * 3 + cs[k];
          }
          graph[v] ~= u;
        }
      }
      int start;
      foreach_reverse (i; 0 .. n) {
        start = start * 3 + 1;
      }
      DList!int que;
      auto vis = new bool[3^^n];
      vis[start] = true;
      que ~= start;
      for (; !que.empty; ) {
        const u = que.front;
        que.removeFront;
        foreach (v; graph[u]) {
          if (!vis[v]) {
            vis[v] = true;
            que ~= v;
          }
        }
      }
      foreach (u; 0 .. 3^^n) {
        auto as= new int[n];
        foreach (i; 0 .. n) {
          as[i] = u / 3^^i % 3;
        }
        const res = solve(as);
        if (vis[u] != res) {
          foreach (i; 0 .. n) {
            write(as[i]);
          }
          writeln();
          writeln(vis[u], " ", res);
          assert(false);
        }
      }
    }
  }
  
  try {
    for (; ; ) {
      const numCases = readInt();
      foreach (caseId; 0 .. numCases) {
        const N = readInt();
        const K = readInt();
        auto A = new int[N];
        foreach (i; 0 .. N) {
          A[i] = readInt();
        }
        
        auto ss = new int[N];
        foreach (i; 0 .. N) {
          ss[i] = (A[i] < K) ? 0 : (A[i] == K) ? 1 : 2;
        }
        const ans = solve(ss);
        writeln(ans ? "yes" : "no");
      }
    }
  } catch (EOFException e) {
  }
}