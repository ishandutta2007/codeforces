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


alias Pt = Tuple!(int, "x", int, "y");

void main() {
  const N = readInt();
  
  Pt[] ps, qs;
  foreach (x; 1 .. N + 1) foreach (y; 1 .. N + 1) {
    if ((x + y) % 2 == 0) {
      ps ~= Pt(x, y);
    } else {
      qs ~= Pt(x, y);
    }
  }
  const psLen = cast(int)(ps.length);
  const qsLen = cast(int)(qs.length);
  int posP, posQ;
  
  foreach (_; 0 .. N^^2) {
    const A = readInt();
    int b;
    Pt p;
    if (A != 1 && posP < psLen) {
      b = 1;
      p = ps[posP++];
    } else if (A != 2 && posQ < qsLen) {
      b = 2;
      p = qs[posQ++];
    } else if (A != 3 && posP < psLen) {
      b = 3;
      p = ps[posP++];
    } else if (A != 3 && posQ < qsLen) {
      b = 3;
      p = qs[posQ++];
    } else {
      assert(false);
    }
    writefln("%s %s %s", b, p.x, p.y);
    stdout.flush;
  }
}