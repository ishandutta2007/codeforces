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


bool solve(const(long) A, const(long) B) {
  if (!(A <= B)) {
    return false;
  }
  int[] xs, ys;
  foreach (e; 0 .. bsr(A)) if ((A >> e) & 1) xs ~= e;
  foreach (e; 0 .. bsr(B)) if ((B >> e) & 1) ys ~= e;
  const xsLen = cast(int)(xs.length);
  const ysLen = cast(int)(ys.length);
  if (!(xsLen >= ysLen)) {
    return false;
  }
  foreach (i; 0 .. ysLen) {
    if (!(xs[i] <= ys[i])) {
      return false;
    }
  }
  return true;
}

void main() {
  debug {
    enum V = 1 << 8;
    auto d = new bool[][](V, V);
    foreach (u; 1 .. V) {
      d[u][u] = true;
    }
    foreach (u; 1 .. V) {
      foreach (v; 1 .. V - u) {
        if ((u & v) == v) {
          d[u][u + v] = true;
        }
      }
    }
    foreach (w; 1 .. V) foreach (u; 1 .. V) if (d[u][w]) foreach (v; 1 .. V) if (d[w][v]) {
      d[u][v] = true;
    }
    foreach (u; 1 .. V) foreach (v; 1 .. V) {
      const res = solve(u, v);
      assert(d[u][v] == res, format("%s %s: %s %s", u, v, d[u][v], res));
    }
  }
  
  try {
    for (; ; ) {
      const numCases = readInt();
      foreach (caseId; 0 .. numCases) {
        const A = readLong();
        const B = readLong();
        const ans = solve(A, B);
        writeln(ans ? "YES" : "NO");
      }
    }
  } catch (EOFException e) {
  }
}