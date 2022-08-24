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




void main() {
  const N = readInt;
  const M = readInt;
  
  alias Edge = Tuple!(long, "c", int, "i");
  auto es = new Edge[M];
  foreach (i; 0 .. M) {
    auto cs = new char[M];
    cs[] = '0';
    cs[i] = '1';
    writefln("? %s", cs);
    stdout.flush;
    es[i].c = readLong;
    es[i].i = i;
  }
  es.sort;
  
  long ans;
  {
    auto cs = new char[M];
    cs[] = '0';
    long bef;
    foreach (e; es) {
      const i = e.i;
      cs[i] = '1';
      writefln("? %s", cs);
      stdout.flush;
      const res = readLong;
      if (bef + e.c == res) {
        ans += e.c;
        bef = res;
      } else {
        cs[i] = '0';
      }
    }
  }
  
  writefln("! %s", ans);
  stdout.flush;
}