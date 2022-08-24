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


uint xrand() {
  static uint x = 314159265, y = 358979323, z = 846264338, w = 327950288;
  uint t = x ^ x << 11; x = y; y = z; z = w; return w = w ^ w >> 19 ^ t ^ t >> 8;
}


// floor(sqrt(a))
long floorSqrt(long a) {
  import core.bitop : bsr;
  import std.algorithm : min;
  long b = a, x = 0, y = 0;
  for (int e = bsr(a) & ~1; e >= 0; e -= 2) {
    x <<= 1;
    y <<= 1;
    if (b >= (y | 1) << e) {
      b -= (y | 1) << e;
      x |= 1;
      y += 2;
    }
  }
  return x;
}


int N, S, X;
debug {
  int[] V, E;
}

alias List = Tuple!(int, "value", int, "next");
List Ask(int i) {
  List ret;
  debug {
    ret.value = V[i];
    ret.next = E[i];
  } else {
    writeln("? ", i + 1);
    stdout.flush;
    ret.value = readInt();
    ret.next = readInt() - 1;
  }
  debug {
    writeln("Ask ", i, " = ", ret);
  }
  return ret;
}

void Answer(int v) {
  writeln("! ", v);
  stdout.flush;
  import core.stdc.stdlib;
  exit(0);
}

void main() {
  N = readInt();
  S = readInt() - 1;
  X = readInt();
  debug {
    V = new int[N];
    E = new int[N];
    foreach (i; 0 .. N) {
      V[i] = readInt();
      E[i] = readInt() - 1;
    }
  }
  
  auto list = new List[N];
  list[] = List(-58, -58);
  
  list[S] = Ask(S);
  if (list[S].value >= X) {
    Answer(list[S].value);
  }
  
  int[] perm = iota(N).array;
  foreach (j; 0 .. N) {
    swap(perm[xrand() % (j + 1)], perm[j]);
  }
  
  int im = S;
  const m = cast(int)(floorSqrt(N));
  foreach (j; 0 .. m) {
    const i = perm[j];
    list[i] = Ask(i);
    if (list[i].value < X) {
      if (list[im].value < list[i].value) {
        im = i;
      }
    }
  }
  
  for (int i = im; ; ) {
    i = list[i].next;
    if (i < 0) {
      Answer(-1);
    }
    list[i] = Ask(i);
    if (list[i].value >= X) {
      Answer(list[i].value);
    }
  }
}