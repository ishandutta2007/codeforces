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


alias Input = Tuple!(long, "w", long, "h", long, "c");

int N;
Input[] inputs;

long solve() {
  inputs.sort;
  debug {
    writeln("inputs = ", inputs);
  }
  
  int K = 0, L = -1;
  for (int i = 0, j; i < N; i = j) {
    for (j = i; j < N && inputs[i].w == inputs[j].w; ++j) {}
    ++K;
    if (L == -1) {
      L = j - i;
    }
    if (L != j - i) {
      debug {
        writeln("not rect");
      }
      return 0;
    }
  }
  debug {
    writeln("K = ", K, ", L = ", L);
  }
  
  auto ws = new long[K];
  auto hs = new long[L];
  foreach (e; 0 .. K) ws[e] = inputs[e * L + 0].w;
  foreach (f; 0 .. L) hs[f] = inputs[0 * L + f].h;
  foreach (e; 0 .. K) foreach (f; 0 .. L) {
    if (ws[e] != inputs[e * L + f].w) {
      debug {
        writeln("not rect (w)");
      }
      return 0;
    }
    if (hs[f] != inputs[e * L + f].h) {
      debug {
        writeln("not rect (h)");
      }
      return 0;
    }
  }
  
  auto xs = new long[K];
  auto ys = new long[L];
  foreach (e; 0 .. K) xs[e] = inputs[e * L + 0].c;
  foreach (f; 0 .. L) ys[f] = inputs[0 * L + f].c;
  const gx = xs.reduce!gcd;
  const gy = ys.reduce!gcd;
  xs[] /= gx;
  ys[] /= gy;
  debug {
    writeln("xs = ", xs);
    writeln("ys = ", ys);
  }
  
  long r = inputs[0 * L + 0].c / xs[0] / ys[0];
  foreach (e; 0 .. K) foreach (f; 0 .. L) {
    if (0 != inputs[e * L + f].c % xs[e]) {
      debug {
        writeln("not divisible by x");
      }
      return 0;
    }
    if (0 != inputs[e * L + f].c / xs[e] % ys[f]) {
      debug {
        writeln("not divisible by y");
      }
      return 0;
    }
    if (r != inputs[e * L + f].c / xs[e] / ys[f]) {
      debug {
        writeln("incorrect rate");
      }
    }
  }
  debug {
    writeln("r = ", r);
  }
  long ans;
  for (long d = 1; d^^2 <= r; ++d) {
    if (r % d == 0) {
      ++ans;
      if (d != r / d) {
        ++ans;
      }
    }
  }
  return ans;
}

void main() {
  try {
    for (; ; ) {
      N = readInt();
      inputs = new Input[N];
      foreach (i; 0 .. N) {
        inputs[i].w = readLong();
        inputs[i].h = readLong();
        inputs[i].c = readLong();
      }
      
      const res = solve();
      writeln(res);
    }
  } catch (EOFException e) {
  }
}