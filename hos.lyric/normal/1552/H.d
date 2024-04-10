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

debug {
  enum N = 10;
} else {
  enum N = 200;
}

int Ask(Pt[] pts) {
  if (pts.empty) {
    debug {
      writeln("Ask([])");
      stdout.flush;
    }
    return 0;
  }
  const ptsLen = cast(int)(pts.length);
  writeln("? ", ptsLen);
  foreach (i; 0 .. ptsLen) {
    if (i > 0) write(" ");
    write(pts[i].x, " ", pts[i].y);
  }
  writeln;
  stdout.flush;
  const res = readInt();
  return res;
}
void Answer(int p) {
  writeln("! ", p);
  stdout.flush;
}

void main() {
  auto xss = new int[long][N^^2 + 1];
  foreach (x; 1 .. N + 1) foreach (y; 1 .. N + 1) {
    auto rss = new int[][3];
    int e;
    foreach_reverse (f; 0 .. 3) {
      const m = 1 << (e | 1 << f);
      foreach (xx; [x / m, (x + m - 1) / m]) {
        rss[f] ~= xx * y;
      }
      rss[f] = rss[f].sort.uniq.array;
      if (x % m == 0) {
        e |= 1 << f;
      }
    }
    foreach (r0; rss[0])
    foreach (r1; rss[1])
    foreach (r2; rss[2])
    {
      const key = cast(long)(r0) | cast(long)(r1) << 16 | cast(long)(r2) << 32;
      if (key in xss[x * y] && xss[x * y][key] != y) {
        writefln("%s %s: %s %s; %s", x, y, e, rss, xss[x * y][key]);
        assert(false);
      }
      xss[x * y][key] = x;
    }
  }
  
  Pt[] all;
  foreach (x; 1 .. N + 1) foreach (y; 1 .. N + 1) {
    all ~= Pt(x, y);
  }
  const S = Ask(all);
  
  auto rs = new int[3];
  int e;
  foreach_reverse (f; 0 .. 3) {
    const m = 1 << (e | 1 << f);
    Pt[] pts;
    foreach (x; 1 .. N + 1) {
      if (x % m == 0) {
        foreach (y; 1 .. N + 1) {
          pts ~= Pt(x, y);
        }
      }
    }
    rs[f] = Ask(pts);
    if (S == m * rs[f]) {
      e |= 1 << f;
    }
  }
  const key = cast(long)(rs[0]) | cast(long)(rs[1]) << 16 | cast(long)(rs[2]) << 32;
  assert(key in xss[S]);
  
  const ansX = xss[S][key];
  const ansY = S / ansX;
  debug {
    writefln("ansX = %s, ansY = %s", ansX, ansY);
    stdout.flush;
  }
  Answer(2 * ((ansX - 1) + (ansY - 1)));
}