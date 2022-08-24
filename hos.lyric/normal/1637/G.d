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


bool solve(const(int) N) {
  debug {
    writeln("N = ", N);
  }
  if (N == 2) {
    return false;
  }
  
  int[] xs, ys;
  void oper(int x, int y) {
    xs ~= x;
    ys ~= y;
  }
  
  int E;
  for (E = 0; 1 << E < N; ++E) {}
  
  auto cnt = new int[(1 << E) + 1];
  cnt[1 .. N + 1] += 1;
  foreach (e; 0 .. E) {
    foreach_reverse (f; 1 .. E + 1) {
      for (int y = 1 << e; y < 1 << (f - 1); y += (1 << (e + 1))) {
        const x = (1 << f) - y;
        const z = x + y, w = x - y;
        for (; cnt[x] > 0 && cnt[y] > 0; ) {
          oper(x, y);
          --cnt[x];
          --cnt[y];
          ++cnt[z];
          ++cnt[w];
        }
      }
    }
  }
  debug {
    writeln("cnt = ", cnt);
  }
  foreach (x; 1 .. (1 << E) + 1) {
    if (cnt[x] > 0) {
      assert(!(x & x - 1));
    }
  }
  
  foreach (e; 0 .. E) {
    const x = 1 << e;
    if (cnt[x] >= 2) {
      oper(x, x);
      --cnt[x];
      --cnt[x];
      ++cnt[x << 1];
      ++cnt[0];
      goto found;
    }
  }
  assert(false);
 found:
  debug {
    writeln("cnt = ", cnt);
  }
  foreach (e; 0 .. E) {
    const x = 1 << e;
    for (; cnt[x] > 0; ) {
      oper(x, 0);
      oper(x, x);
      --cnt[x];
      ++cnt[x << 1];
    }
  }
  oper(1 << E, 0);
  
  //*
  writeln(xs.length);
  foreach (i; 0 .. xs.length) {
    writeln(xs[i], " ", ys[i]);
  }
  //*/
  return true;
}

void main() {
  debug {
    foreach (N; 2 .. 100 + 1) {
      solve(N);
    }
  }
  
  try {
    for (; ; ) {
      const numCases = readInt;
      foreach (caseId; 0 .. numCases) {
        const N = readInt;
        
        const res = solve(N);
        if (!res) {
          writeln(-1);
        }
      }
    }
  } catch (EOFException e) {
  }
}