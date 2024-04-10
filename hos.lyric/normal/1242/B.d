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

enum INF = 10^^9;

int segN;
Tuple!(int, int)[] seg;

void update(int a, int val) {
  seg[a += segN][0] += val;
  for (; a >>= 1; ) {
    seg[a] = min(seg[a << 1], seg[a << 1 | 1]);
  }
}

void main() {
  try {
    for (; ; ) {
      const N = readInt();
      const M = readInt();
      auto A = new int[M];
      auto B = new int[M];
      foreach (i; 0 .. M) {
        A[i] = readInt() - 1;
        B[i] = readInt() - 1;
      }
      
      auto G = new int[][N];
      foreach (i; 0 .. M) {
        G[A[i]] ~= B[i];
        G[B[i]] ~= A[i];
      }
      
      for (segN = 1; segN < N; segN <<= 1) {}
      seg.length = segN << 1;
      seg[] = tuple(INF, -1);
      foreach (u; 0 .. N) {
        seg[segN + u] = tuple(0, u);
      }
      foreach_reverse (a; 1 .. segN) {
        seg[a] = min(seg[a << 1], seg[a << 1 | 1]);
      }
      
      int ans;
      foreach (h; 0 .. N) {
        const u = seg[1][1];
        debug {
          writeln("u = ", u);
        }
        if (seg[1][0] == h) {
          debug {
            writeln("  new comp");
          }
          ++ans;
        }
        update(u, INF);
        foreach (v; G[u]) {
          update(v, 1);
        }
      }
      --ans;
      writeln(ans);
    }
  } catch (EOFException e) {
  }
}