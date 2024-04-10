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


Int gojo(Int)(Int a, Int b, out Int x, out Int y) {
  if (b != 0) { Int g = gojo(b, a % b, y, x); y -= (a / b) * x; return g; }
  x = 1; y = 0; return a;
}

void main() {
  try {
    for (; ; ) {
      const T = readLong();
      const N = readInt();
      auto A = new long[N];
      foreach (i; 0 .. N) {
        A[i] = readLong();
      }
      
      auto X = new long[N + 1];
      foreach (i; 0 .. N) {
        X[i + 1] = X[i] + A[(i + 1) % N];
      }
      const M = X[N];
      debug {
        writeln("X = ", X);
      }
      
      long z0, z1;
      const D = gojo(M, T, z0, z1);
      
      alias Entry = Tuple!(long, "val", int, "i");
      auto es = new Entry[N];
      foreach (i; 0 .. N) {
        es[i] = Entry(X[i] % D, i);
      }
      es.sort;
      
      auto ans = new long[N];
      for (int j = 0, k; j < N; j = k) {
        for (k = j; k < N && es[j].val == es[k].val; ++k) {}
        debug {
          writeln(es[j .. k]);
        }
        const r = es[j].val;
        auto fs = new Entry[k - j];
        foreach (l; 0 .. k - j) {
          const i = es[j + l].i;
          /*
            X[i] == r + M a (mod T)
            X[i] + T b = r + M a
            (M / D) a - (T / D) b = (X[i] - r) / D
            (M / D) z0 + (T / D) z1 = 1
          */
          long a = (z0 * (((X[i] - r) / D) % (T / D))) % (T / D);
          if (a < 0) {
            a += T / D;
          }
          fs[l] = Entry(a, i);
        }
        fs.sort!"(a.val != b.val) ? (a.val < b.val) : (a.i > b.i)";
        debug {
          writeln("  fs = ", fs);
        }
        foreach (l; 0 .. k - j - 1) {
          ans[fs[l].i] = fs[l + 1].val - fs[l].val;
        }
        ans[fs[k - j - 1].i] = T / D + fs[0].val - fs[k - j - 1].val;
      }
      foreach (i; 0 .. N) {
        if (i > 0) write(" ");
        write(ans[i]);
      }
      writeln;
      
      debug {
        auto app = new bool[cast(int)(T)];
        auto brt = new long[N];
        foreach (h; 0 .. T) {
          foreach (i; 0 .. N) {
            const x = (X[i] + M * h) % T;
            if (!app[cast(int)(x)]) {
              app[cast(int)(x)] = true;
              ++brt[i];
            }
          }
        }
        writeln("brt = ", brt);
      }
    }
  } catch (EOFException e) {
  }
}