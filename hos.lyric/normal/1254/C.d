import std.conv, std.functional, std.range, std.stdio, std.string;
import std.algorithm, std.array, std.bigint, std.bitmanip, std.complex, std.container, std.math, std.numeric, std.regex, std.typecons;
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
  long[] X, Y;
}

long Ask(int t, int i, int j, int k) {
  long ret;
  debug {
    ret = (X[j] - X[i]) * (Y[k] - Y[i]) - (Y[j] - Y[i]) * (X[k] - X[i]);
    if (t == 1) {
      ret = abs(ret);
    } else {
      ret = sgn(ret);
    }
  } else {
    writeln(t, " ", i + 1, " ", j + 1, " ", k + 1);
    stdout.flush;
    ret = readLong();
  }
  return ret;
}

void main() {
  N = readInt();
  debug {
    X = new long[N];
    Y = new long[N];
    foreach (i; 0 .. N) {
      X[i] = readLong();
      Y[i] = readLong();
    }
  }
  
  auto as = new long[N];
  foreach (i; 2 .. N) {
    as[i] = Ask(1, 0, 1, i);
    as[i] *= Ask(2, 0, 1, i);
  }
  debug {
    writeln("as = ", as);
  }
  
  int[] ans;
  ans ~= 0;
  {
    int im;
    foreach (i; 2 .. N) {
      if (as[im] > as[i]) {
        im = i;
      }
    }
    if (im != 0) {
      int[] ims, ips;
      foreach (i; 2 .. N) {
        if (as[i] < 0 && i != im) {
          const res = Ask(2, 0, im, i);
          (res < 0) ? (ims ~= i) : (ips ~= i);
        }
      }
      ims.sort!((i, j) => (as[i] > as[j]));
      ips.sort!((i, j) => (as[i] < as[j]));
      foreach (i; ims) ans ~= i;
      ans ~= im;
      foreach (i; ips) ans ~= i;
    }
  }
  ans ~= 1;
  {
    int im;
    foreach (i; 2 .. N) {
      if (as[im] < as[i]) {
        im = i;
      }
    }
    if (im != 0) {
      int[] ims, ips;
      foreach (i; 2 .. N) {
        if (as[i] > 0 && i != im) {
          const res = Ask(2, 0, im, i);
          (res < 0) ? (ims ~= i) : (ips ~= i);
        }
      }
      ims.sort!((i, j) => (as[i] < as[j]));
      ips.sort!((i, j) => (as[i] > as[j]));
      foreach (i; ims) ans ~= i;
      ans ~= im;
      foreach (i; ips) ans ~= i;
    }
  }
  
  write(0);
  foreach (i; ans) {
    write(" ", i + 1);
  }
  writeln();
  stdout.flush;
}