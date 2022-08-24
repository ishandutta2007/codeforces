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


bool experiment(int N, int M) {
  bool found;
  void check(int[] zs) {
    auto a = new char[][](N, N);
    foreach (x; 0 .. N) foreach (y; 0 .. N) {
      a[x][y] = '?';
    }
    foreach (z; zs) {
      const x = z / N, y = z % N;
      foreach (xx; 0 .. N) foreach (yy; 0 .. N) {
        if (x == xx || y == yy || x - y == xx - yy) {
          a[xx][yy] = '.';
        }
      }
    }
    foreach (z; zs) {
      const x = z / N, y = z % N;
      a[x][y] = '#';
    }
    bool ok = true;
    foreach (x; 0 .. N) foreach (y; 0 .. N) {
      ok = ok && (a[x][y] != '?');
    }
    if (ok) {
      found = true;
      foreach (x; 0 .. N) {
        writeln(a[x]);
      }
      writeln;
      stdout.flush;
    }
  }
  void dfs(int[] zs) {
    if (zs.length == M) {
      check(zs);
    } else {
      foreach (z; (zs.empty ? 0 : (zs[$ - 1] + 1)) .. N^^2) {
        dfs(zs ~ z);
      }
    }
  }
  dfs([]);
  return found;
}

alias Pt = Tuple!(int, "x", int, "y");

Pt[] solve(int N) {
  Pt[] ans;
  const a = (N - 1) / 3;
  foreach (i; 0 .. a + 1) {
    ans ~= Pt(i, a - i);
  }
  foreach (i; 0 .. a) {
    ans ~= Pt(N - 1 - i, N - 1 - (a - 1 - i));
  }
  if (N % 3 == 0) {
    ans ~= Pt(N - 1 - a, N - 1 - a);
  }
  return ans;
}

void judge(int N, const(Pt[]) P) {
  foreach (p; P) {
    assert(0 <= p.x); assert(p.x < N);
    assert(0 <= p.y); assert(p.y < N);
  }
  foreach (x; 0 .. N) foreach (y; 0 .. N) {
    bool ok;
    foreach (p; P) {
      ok = ok || (x == p.x || y == p.y || x - y == p.x - p.y);
    }
    assert(ok);
  }
}

void main() {
  /*
  debug {
    foreach (n; 1 .. 9 + 1) {
      for (int m = 1; ; ++m) {
        const res = experiment(n, m);
        if (res) {
          stderr.writeln(n, ": ", m);
          stderr.flush;
          break;
        }
      }
    }
    return;
  }
  //*/
  
  debug {
    foreach (n; 1 .. 20 + 1) {
      const ans = solve(n);
      // writeln(n, ": ", ans.length, " ", ans);
      writeln(n, ": ", ans.length);
      judge(n, ans);
    }
  }
  
  try {
    for (; ; ) {
      const N = readInt;
      
      auto ans = solve(N);
      writeln(ans.length);
      foreach (p; ans) {
        writeln(p.x + 1, " ", p.y + 1);
      }
    }
  } catch (EOFException e) {
  }
}