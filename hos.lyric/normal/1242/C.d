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




void main() {
  try {
    for (; ; ) {
      const K = readInt();
      auto N = new int[K];
      auto A = new long[][K];
      foreach (u; 0 .. K) {
        N[u] = readInt();
        A[u] = new long[N[u]];
        foreach (j; 0 .. N[u]) {
          A[u][j] = readLong();
        }
      }
      
      Tuple!(int, "u", int, "j")[long] pos;
      foreach (u; 0 .. K) {
        foreach (j; 0 .. N[u]) {
          pos[A[u][j]] = tuple!("u", "j")(u, j);
        }
      }
      
      auto ss = new long[K];
      foreach (u; 0 .. K) {
        ss[u] = A[u].sum;
      }
      long s = ss.sum;
      if (s % K != 0) {
        writeln("No");
        continue;
      }
      s /= K;
      debug {
        writeln("s = ", s);
      }
      
      auto cycs = new Tuple!(int[], long[])[1 << K];
      foreach (t; 0 .. K) {
        foreach (i; 0 .. N[t]) {
          int used;
          int[] us;
          long[] as;
          for (int u = t, j = i; ; ) {
            used |= 1 << u;
            us ~= u;
            as ~= A[u][j];
            // ss[u] - A[u][j] + A[v][k] = s
            const a = s - ss[u] + A[u][j];
            if (!(a in pos)) {
              goto failed;
            }
            const vk = pos[a];
            const v = vk.u;
            const k = vk.j;
            if (used & 1 << v) {
              if (!(t == v && i == k)) {
                goto failed;
              }
              debug {
                writeln("cyc ", used, " ", us, " ", as);
              }
              cycs[used] = tuple(us, as);
              break;
            }
            u = v;
            j = k;
          }
         failed:
        }
      }
      
      auto prev = new int[1 << K];
      prev[0] = -1;
      foreach (p; 1 .. 1 << K) {
        for (int q = p; q; --q &= p) {
          if (cycs[q][0] && prev[p ^ q]) {
            prev[p] = q;
          }
        }
      }
      if (prev[$ - 1]) {
        auto ansC = new long[K];
        auto ansP = new int[K];
        for (int p = (1 << K) - 1; p; ) {
          const q = prev[p];
          const us = cycs[q][0];
          const as = cycs[q][1];
          const len = cast(int)(us.length);
          foreach (h; 0 .. len) {
            ansC[us[h]] = as[h];
            ansP[us[(h + 1) % len]] = us[h];
          }
          p ^= q;
        }
        writeln("Yes");
        foreach (u; 0 .. K) {
          writeln(ansC[u], " ", ansP[u] + 1);
        }
      } else {
        writeln("No");
      }
    }
  } catch (EOFException e) {
  }
}