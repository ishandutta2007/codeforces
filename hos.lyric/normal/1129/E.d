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


int N;

version(LOCAL) {
  int[] A, B;
  int[][] D;
}

void Init() {
  version(LOCAL) {
    N = readInt();
    A = new int[N - 1];
    B = new int[N - 1];
    foreach (i; 0 .. N - 1) {
      A[i] = readInt() - 1;
      B[i] = readInt() - 1;
    }
    D = new int[][](N, N);
    foreach (u; 0 .. N) {
      D[u][] = N;
      D[u][u] = 0;
    }
    foreach (i; 0 .. N - 1) {
      D[A[i]][B[i]] = 1;
      D[B[i]][A[i]] = 1;
    }
    foreach (w; 0 .. N) foreach (u; 0 .. N) foreach (v; 0 .. N) {
      chmin(D[u][v], D[u][w] + D[w][v]);
    }
  } else {
    N = readInt();
  }
}

int Ask(int[] S, int[] T, int v) {
  int ret;
  version(LOCAL) {
    foreach (s; S) foreach (t; T) {
      if (D[s][t] == D[s][v] + D[v][t]) {
        ++ret;
      }
    }
  } else {
    writeln(S.length);
    writeln(S.map!(u => u + 1).to!string.replaceAll(regex(`[\[\],]`), ""));
    writeln(T.length);
    writeln(T.map!(u => u + 1).to!string.replaceAll(regex(`[\[\],]`), ""));
    writeln(v + 1);
    stdout.flush;
    ret = readInt();
  }
  return ret;
}

void Answer(int[] a, int[] b) {
  writeln("ANSWER");
  foreach (i; 0 .. N - 1) {
    writeln(a[i] + 1, " ", b[i] + 1);
  }
  stdout.flush;
}

void main() {
  Init();
  
  int rt = 0;
  auto sz = new int[N];
  sz[rt] = N;
  foreach (u; 0 .. N) {
    if (u != rt) {
      int[] T;
      foreach (v; 0 .. N) {
        if (v != rt) {
          T ~= v;
        }
      }
      sz[u] = Ask([rt], T, u);
    }
  }
  debug {
    writeln("sz = ", sz);
  }
  
  auto us = iota(N).array;
  us.sort!((u, v) => (sz[u] < sz[v]));
  int[] ansA, ansB;
  int[] des;
  foreach (j; 0 .. N) {
    for (int s = sz[us[j]] - 1; s > 0; ) {
      int lo = 0, hi = cast(int)(des.length);
      for (; lo + 1 < hi; ) {
        const mid = (lo + hi) / 2;
        ((Ask([rt], des[0 .. mid], us[j]) > 0) ? hi : lo) = mid;
      }
      ansA ~= us[j];
      ansB ~= des[lo];
      s -= sz[des[lo]];
      des = des[0 .. lo] ~ des[hi .. $];
    }
    des ~= us[j];
  }
  Answer(ansA, ansB);
}