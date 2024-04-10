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

int[][] graph;
int[] vis;
bool dfs(int u) {
  vis[u] = 1;
  foreach (v; graph[u]) {
    if (vis[v] == 0) {
      if (!dfs(v)) {
        return false;
      }
    } else if (vis[v] == 1) {
      return false;
    }
  }
  vis[u] = 2;
  return true;
}

bool solve() {
  auto xss = new int[][N + 1];
  foreach (i; 0 .. N) {
    xss[A[i]] ~= i;
  }
  auto lens = new int[N + 1];
  foreach (a; 1 .. N + 1) {
    lens[a] = cast(int)(xss[a].length);
  }
  
  int am;
  foreach (a; 1 .. N + 1) {
    if (lens[am] < lens[a]) {
      am = a;
    }
  }
  debug {
    writeln("am = ", am);
  }
  
  auto ids = new int[N];
  ids[] = -1;
  foreach (i; 0 .. N) if (B[i] != am) {
    ids[i] = xss[B[i]][--lens[B[i]]];
  }
  debug {
    writeln("ids = ", ids);
  }
  
  auto used = new bool[N];
  graph = new int[][N + 1];
  foreach (i; 0 .. N) if (A[i] == am) {
    int[] js;
    for (int j = i; ; ) {
      j = ids[j];
      if (j == -1) {
        break;
      }
      js ~= j;
      used[j] = true;
    }
    debug {
      writeln("js = ", js);
      writeln("A js = ", js.map!(j => A[j]));
    }
    const jsLen = cast(int)(js.length);
    foreach (k; 0 .. jsLen - 1) {
      graph[A[js[k]]] ~= A[js[k + 1]];
    }
  }
  foreach (i; 0 .. N) if (A[i] != am) {
    if (!used[i]) {
      return false;
    }
  }
  
  vis = new int[N + 1];
  foreach (a; 1 .. N + 1) if (vis[a] == 0) {
    if (!dfs(a)) {
      return false;
    }
  }
  
  return true;
}

void main() {
  try {
    for (; ; ) {
      const numCases = readInt;
      foreach (caseId; 0 .. numCases) {
        N = readInt;
        A = new int[N]; foreach (i; 0 .. N) A[i] = readInt;
        B = new int[N]; foreach (i; 0 .. N) B[i] = readInt;
        
        const ans = solve;
        writeln(ans ? "AC" : "WA");
      }
    }
  } catch (EOFException e) {
  }
}