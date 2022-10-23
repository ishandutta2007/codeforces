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
int[] B;
int K;
int[] A;

void solve() {
  auto minL = new int[N + 1];
  auto maxR = new int[N + 1];
  minL[0] = N + 2;
  foreach (i; 0 .. N) {
    minL[i + 1] = min(minL[i], B[i]);
  }
  maxR[N] = -1;
  foreach_reverse (i; 0 .. N) {
    maxR[i] = max(B[i], maxR[i + 1]);
  }
  {
    int[] ks;
    foreach (k; 0 .. N + 1) {
      if (minL[k] > k && k >= maxR[k]) {
        ks ~= k;
      }
    }
    debug {
      writeln("ks = ", ks);
    }
    assert(ks.length == 1);
    K = ks[0];
  }
  
  auto graph = new int[][N + 2];
  foreach (i; 0 .. N) {
    graph[B[i]] ~= i + 1;
  }
  auto us = [0, N + 1];
  for (int j = 0; j < us.length; ++j) {
    graph[us[j]].sort!((v, w) => (graph[v].length < graph[w].length));
    foreach (v; graph[us[j]]) {
      us ~= v;
    }
  }
  assert(us.length == N + 2);
  A = us[2 .. $];
}

void main() {
  try {
    for (; ; ) {
      const numCases = readInt;
      foreach (caseId; 0 .. numCases) {
        N = readInt;
        B = new int[N];
        foreach (i; 0 .. N) {
          B[i] = readInt;
        }
        
        solve;
        
        writeln(K);
        foreach (i; 0 .. N) {
          if (i) write(" ");
          write(A[i]);
        }
        writeln;
      }
    }
  } catch (EOFException e) {
  }
}