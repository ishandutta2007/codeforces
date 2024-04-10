import std.conv, std.functional, std.stdio, std.string;
import std.algorithm, std.array, std.bigint, std.container, std.math, std.numeric, std.range, std.regex, std.typecons;
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


enum MO = 998244353L;
enum L = 300;

void ADD(ref long t, long f) {
  t += f;
  if (t >= MO) {
    t -= MO;
  }
}

int N, K;
int[] A;

long[] dp;

int numBlocks;
int[] mins;
int[] keys;
long[][] sums;

void init() {
  numBlocks = (N + 1 + L - 1) / L;
  mins = new int[numBlocks];
  keys = new int[N + 1];
  sums = new long[][](numBlocks, L + 1);
}

void addDP(int i) {
  debug {
    writeln("addDP ", i, "; ", dp[i]);
  }
  foreach (x; keys[i] .. L + 1) {
    ADD(sums[i / L][x], dp[i]);
  }
}

void rangeAdd(int a, int b, int val) {
  debug {
    writeln("  mins = ", mins);
    writeln("  keys = ", keys);
    writeln("rangeAdd ", a, " ", b, " ", val);
  }
  foreach (e; 0 .. numBlocks) {
    const l = L * e, r = min(L * (e + 1), N);
    const aa = max(a, l), bb = min(b, r);
    if (aa < bb) {
      if (aa == l && bb == r) {
        mins[e] += val;
      } else {
        foreach (i; aa .. bb) {
          keys[i] += val;
        }
        const mn = keys[l .. r].minElement;
        mins[e] += mn;
        foreach (i; l .. r) {
          keys[i] -= mn;
        }
        sums[e][] = 0;
        foreach (i; l .. r) {
          ADD(sums[e][keys[i]], dp[i]);
        }
        foreach (x; 1 .. L + 1) {
          ADD(sums[e][x], sums[e][x - 1]);
        }
      }
    }
  }
}

long getDPSum() {
  long ret;
  foreach (e; 0 .. numBlocks) {
    if (mins[e] <= K) {
      ADD(ret, sums[e][min(K - mins[e], L)]);
    }
  }
  debug {
    writeln("getDPSum = ", ret);
  }
  return ret;
}

void main() {
  try {
    for (; ; ) {
      N = readInt();
      K = readInt();
      A = new int[N];
      foreach (i; 0 .. N) {
        A[i] = readInt();
      }
      
      auto app = new int[N + 1];
      app[] = -1;
      auto prev = new int[N];
      foreach (i; 0 .. N) {
        prev[i] = app[A[i]];
        app[A[i]] = i;
      }
      
      init();
      dp = new long[N + 1];
      dp[0] = 1;
      addDP(0);
      foreach (i; 0 .. N) {
        if (prev[i] >= 0) {
          rangeAdd(prev[prev[i]] + 1, prev[i] + 1, -1);
        }
        rangeAdd(prev[i] + 1, i + 1, +1);
        dp[i + 1] = getDPSum();
        addDP(i + 1);
      }
      writeln(dp[N]);
    }
  } catch (EOFException e) {
  }
}