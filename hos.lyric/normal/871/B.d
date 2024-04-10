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
debug {
  int[] P, B;
}

int Ask(int i, int j) {
  int ret;
  debug {
    ret = P[i] ^ B[j];
  } else {
    writefln("? %s %s", i, j);
    stdout.flush;
    ret = readInt();
  }
  return ret;
}

void main() {
  N = readInt();
  debug {
    P = new int[N];
    foreach (i; 0 .. N) {
      P[i] = readInt();
    }
    B = new int[N];
    foreach (i; 0 .. N) {
      B[P[i]] = i;
    }
  }
  
  auto X = new int[N];
  auto Y = new int[N];
  foreach (i; 0 .. N) {
    X[i] = Ask(i, 0);
  }
  foreach (j; 0 .. N) {
    Y[j] = Ask(0, j);
  }
  
  int ansCnt;
  int[] ans;
  foreach (p0; 0 .. N) {
    const b0 = X[0] ^ p0;
    auto ps = new int[N];
    foreach (i; 0 .. N) {
      ps[i] = X[i] ^ b0;
    }
    auto bs = new int[N];
    foreach (j; 0 .. N) {
      bs[j] = Y[j] ^ p0;
    }
    debug {
      writeln(p0, " ", ps, " ", bs);
    }
    bool ok = true;
    foreach (i; 0 .. N) {
      ok = ok && (0 <= ps[i] && ps[i] < N);
    }
    foreach (j; 0 .. N) {
      ok = ok && (0 <= bs[j] && bs[j] < N);
    }
    if (ok) {
      foreach (i; 0 .. N) {
        ok = ok && (bs[ps[i]] == i);
      }
    }
    if (ok) {
      ++ansCnt;
      if (ans.empty) {
        ans = ps.dup;
      }
    }
  }
  
  writeln("!");
  writeln(ansCnt);
  foreach (i; 0 .. N) {
    if (i > 0) write(" ");
    write(ans[i]);
  }
  writeln();
  stdout.flush;
}