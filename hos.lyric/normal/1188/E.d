import std.conv, std.functional, std.range, std.stdio, std.string;
import std.algorithm, std.array, std.bigint, std.complex, std.container, std.math, std.numeric, std.regex, std.typecons;
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


enum long MO = 998244353;
enum LIM = 3 * 10^^6;

long[] inv, fac, invFac;
void prepare() {
  inv = new long[LIM];
  fac = new long[LIM];
  invFac = new long[LIM];
  inv[1] = 1;
  foreach (i; 2 .. LIM) {
    inv[i] = MO - ((MO / i) * inv[cast(size_t)(MO % i)]) % MO;
  }
  fac[0] = invFac[0] = 1;
  foreach (i; 1 .. LIM) {
    fac[i] = (fac[i - 1] * i) % MO;
    invFac[i] = (invFac[i - 1] * inv[i]) % MO;
  }
}
long binom(long n, long k) {
  if (0 <= k && k <= n) {
    assert(n < LIM);
    return fac[cast(size_t)(n)] * invFac[cast(size_t)(k)] % MO * invFac[cast(size_t)(n - k)] % MO;
  } else {
    return 0;
  }
}


int K;
int[] A;

void main() {
  prepare();
  
  //*
  debug {
    {
      enum s = [0, 1, 2, 2, 2];
      K = cast(int)(s.length);
      enum lim = s.sum + 1;
      auto vis = new bool[lim^^K];
      int encode(int[] u) {
        int ret;
        foreach (i; 0 .. K) ret += u[i] * lim^^i;
        return ret;
      }
      DList!(int[]) q;
      vis[encode(s)] = true;
      q.insertBack(s);
      for (; !q.empty; ) {
        const u = q.front;
        q.removeFront;
        foreach (i; 0 .. K) {
          auto v = u.dup;
          v[] -= 1;
          v[i] += K;
          if (v.all!"a >= 0") {
            if (!vis[encode(v)]) {
              vis[encode(v)] = true;
              q.insertBack(v);
            }
          }
        }
      }
      int cntAll;
      int cnt;
      foreach (key; 0 .. lim^^K) {
        auto u = iota(K).map!(i => (key / lim^^i % lim)).array;
        bool ok = (s.sum == u.sum);
        foreach (i; 1 .. K) {
          ok = ok && (((u[i] - u[0]) - (s[i] - s[0])) % K == 0);
        }
        if (ok) {
          ++cntAll;
        }
        if (vis[encode(u)]) {
          ++cnt;
          writeln(u);
        }
      }
      writeln(cntAll, " ", cnt);
    }
  }
  //*/
  
  try {
    for (; ; ) {
      K = readInt();
      A = new int[K];
      foreach (i; 0 .. K) {
        A[i] = readInt();
      }
      
      long ans;
      
      A.sort;
      bool ok = true;
      /*
      foreach (i; 0 .. K) {
        if (A[i] > i) {
          break;
        }
        if (A[i] < i) {
          ans = i;
          ok = false;
          break;
        }
      }
      */
      foreach (i; 0 .. K) {
        if (A[i] < i) {
          A[i + 1 .. $] = A[i];
          break;
        }
      }
      
      if (ok) {
        int s;
        auto f = new int[K];
        foreach (i; 0 .. K) {
          s += A[i] / K;
          ++f[A[i] % K];
        }
        foreach (i; 0 .. K) {
          if (s >= 0) {
            // multi-choose s times from K
            ans += binom(K + s - 1, K - 1);
            ans %= MO;
          }
          s -= 1;
          s += f[K - 1 - i];
        }
      }
      ans = (ans % MO + MO) % MO;
      writeln(ans);
    }
  } catch (EOFException e) {
  }
}