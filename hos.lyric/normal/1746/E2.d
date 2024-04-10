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


enum INF = 10^^9;
enum W = 1;

alias Result = Tuple!(int, "cost", int, "a0", int, "b0");
Result[long] cache;
Result calc(int a, int b) {
  const key = cast(long)(a) << 20 | b;
  auto ptr = key in cache;
  if (ptr) return *ptr;
  Result ret = Result(INF, -1, -1);
  
  if (a + b <= 2) {
    ret.cost = 0;
  } else if (b == 0) {
    // ask a0
    foreach (a0; (a / 2 - W) .. (a / 2 + W) + 1) if (0 < a0 && a0 < a) {
      const a1 = a - a0;
      if (chmin(ret.cost, 1 + max(calc(a0, a1).cost, calc(a1, a0).cost))) {
        ret.a0 = a0;
      }
    }
  } else if (b == 1) {
    // ask b
    ret.cost = 1 + max(calc(b, a).cost, calc(a, 0).cost);
  } else {
    // ask a0, b0
    foreach (a0; (a / 2 - W) .. (a / 2 + W) + 1) if (0 <= a0 && a0 <= a) {
      foreach (b0; (b / 2 - W) .. (b / 2 + W) + 1) if (0 < b0 && b0 < b) {
        const a1 = a - a0;
        const b1 = b - b0;
        if (chmin(ret.cost, 1 + max(calc(a0 + b0, a1).cost, calc(a1 + b1, a0).cost))) {
          ret.a0 = a0;
          ret.b0 = b0;
        }
      }
    }
  }
  debug {
    if (a + b <= 5) {
      writeln(a, " ", b, ": ", ret);
    }
  }
  
  return cache[key] = ret;
}


bool Ask(const(int[]) xs) {
  writef("? %s", xs.length);
  foreach (x; xs) {
    write(" ", x);
  }
  writeln;
  stdout.flush;
  const res = readToken;
  return (res == "YES");
}
void Answer(const(int[]) xs) {
  foreach (x; xs) {
    writefln("! %s", x);
    stdout.flush;
    const res = readToken;
    if (res == ":)") {
      return;
    }
  }
  assert(false);
}

void main() {
  debug {
    foreach (e; 1 .. 5 + 1) {
      const n = 10^^e;
      const res = calc(n, 0);
      writefln("n = %s: |cache| = %s; %s", n, cache.length, res);
      stdout.flush;
    }
  }
  
  const N = readInt;
  int[] xs = iota(1, N + 1).array, ys;
  for (; ; ) {
    debug {
      writeln(xs, " ", ys);
    }
    const a = cast(int)(xs.length);
    const b = cast(int)(ys.length);
    const res = calc(a, b);
    if (a + b <= 2) {
      break;
    } else if (b == 0) {
      int[] xs0 = xs[0 .. res.a0], xs1 = xs[res.a0 .. a];
      if (Ask(xs0)) {
        xs = xs0;
        ys = xs1;
      } else {
        xs = xs1;
        ys = xs0;
      }
    } else if (b == 1) {
      if (Ask(ys)) {
        swap(xs, ys);
      } else {
        ys = [];
      }
    } else {
      int[] xs0 = xs[0 .. res.a0], xs1 = xs[res.a0 .. a];
      int[] ys0 = ys[0 .. res.b0], ys1 = ys[res.b0 .. b];
      if (Ask(xs0 ~ ys0)) {
        xs = xs0 ~ ys0;
        ys = xs1;
      } else {
        xs = xs1 ~ ys1;
        ys = xs0;
      }
    }
  }
  Answer(xs ~ ys);
}