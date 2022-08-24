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

void bAdd(T)(T[] bit, int pos, T val)
in {
  assert(0 <= pos && pos < bit.length, "bAdd: 0 <= pos < |bit| must hold");
}
do {
  for (int x = pos; x < bit.length; x |= x + 1) {
    bit[x] += val;
  }
}

// sum of [0, pos)
T bSum(T)(T[] bit, int pos)
in {
  assert(0 <= pos && pos <= bit.length, "bSum: 0 <= pos <= |bit| must hold");
}
do {
  T ret = 0;
  for (int x = pos - 1; x >= 0; x = (x & (x + 1)) - 1) {
    ret += bit[x];
  }
  return ret;
}


struct Rat {
  long p, q;
  this(long p, long q = 1) {
    if (q < 0) { p = -p; q = -q; }
    const g = std.numeric.gcd(abs(p), q);
    this.p = p / g;
    this.q = q / g;
  }
  bool opEquals(Rat a) const { return (p * a.q == a.p * q); }
  long opCmp(Rat a) const { return p * a.q - a.p * q; }
  string toString() const { return p.to!string ~ "/" ~ q.to!string; }
}


void main() {
  try {
    for (; ; ) {
      const N = readInt();
      const W = readLong();
      auto X = new long[N];
      auto V = new long[N];
      foreach (i; 0 .. N) {
        X[i] = readLong();
        V[i] = readLong();
      }
      
      alias Entry = Tuple!(Rat, "t", int, "id");
      auto eas = new Entry[N];
      auto ebs = new Entry[N];
      foreach (i; 0 .. N) {
        eas[i] = Entry(Rat(X[i], V[i] - W), i);
        ebs[i] = Entry(Rat(X[i], V[i] + W), i);
      }
      eas.sort;
      ebs.sort;
      debug {
        writeln("eas = ", eas);
        writeln("ebs = ", ebs);
      }
      
      int A, B;
      auto as = new int[N];
      auto bs = new int[N];
      for (int i = 0, j; i < N; i = j) {
        for (j = i; j < N && eas[i].t == eas[j].t; ++j) {
          as[eas[j].id] = A;
        }
        ++A;
      }
      for (int i = 0, j; i < N; i = j) {
        for (j = i; j < N && ebs[i].t == ebs[j].t; ++j) {
          bs[ebs[j].id] = B;
        }
        ++B;
      }
      debug {
        writeln("as = ", as);
        writeln("bs = ", bs);
      }
      
      auto iss = new int[][A];
      foreach (i; 0 .. N) {
        iss[as[i]] ~= i;
      }
      
      long ans;
      auto bit = new int[B];
      foreach (a; 0 .. A) {
        // count same a
        const num = cast(long)(iss[a].length);
        ans += num * (num - 1) / 2;
        // count different a
        foreach (i; iss[a]) {
          ans += bit.bSum(B) - bit.bSum(bs[i]);
        }
        // add
        foreach (i; iss[a]) {
          bit.bAdd(bs[i], 1);
        }
      }
      writeln(ans);
    }
  } catch (EOFException e) {
  }
}