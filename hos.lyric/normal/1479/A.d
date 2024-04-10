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
int[] A;

int[] cache;

int Ask(int i) {
  if (cache[i] == -1) {
    writefln("? %s", i);
    stdout.flush;
    debug {
      cache[i] = A[i];
    } else {
      cache[i] = readInt();
    }
  }
  return cache[i];
}

void Answer(int i) {
  writefln("! %s", i);
  stdout.flush;
}

void main() {
  N = readInt();
  debug {
    A = new int[N + 2];
    A[0] = A[N + 1] = N + 1;
    foreach (i; 1 .. N + 1) {
      A[i] = readInt();
    }
  }
  
  cache = new int[N + 2];
  cache[] = -1;
  cache[0] = cache[N + 1] = N + 1;
  
  int lo = 0, hi = N + 1;
  for (; lo + 2 < hi; ) {
    const mid = (lo + hi) / 2;
    const a = Ask(mid);
    const b = Ask(mid + 1);
    (a < b) ? (hi = mid + 1) : (lo = mid);
  }
  assert(lo + 2 == hi);
  Answer(lo + 1);
}