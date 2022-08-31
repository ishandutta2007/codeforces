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


struct ModInt(int M_) {
  import std.conv : to;
  alias M = M_;
  int x;
  this(ModInt a) { x = a.x; }
  this(long a) { x = cast(int)(a % M); if (x < 0) x += M; }
  ref ModInt opAssign(long a) { return (this = ModInt(a)); }
  ref ModInt opOpAssign(string op)(ModInt a) {
    static if (op == "+") { x += a.x; if (x >= M) x -= M; }
    else static if (op == "-") { x -= a.x; if (x < 0) x += M; }
    else static if (op == "*") { x = cast(int)((cast(long)(x) * a.x) % M); }
    else static if (op == "/") { this *= a.inv(); }
    else static assert(false);
    return this;
  }
  ref ModInt opOpAssign(string op)(long a) {
    static if (op == "^^") {
      if (a < 0) return (this = inv()^^(-a));
      ModInt t2 = this, te = ModInt(1);
      for (long e = a; e > 0; e >>= 1) {
        if (e & 1) te *= t2;
        t2 *= t2;
      }
      x = cast(int)(te.x);
      return this;
    } else return mixin("this " ~ op ~ "= ModInt(a)");
  }
  ModInt inv() const {
    int a = x, b = M, y = 1, z = 0, t;
    for (; ; ) {
      t = a / b; a -= t * b;
      if (a == 0) {
        assert(b == 1 || b == -1);
        return ModInt(b * z);
      }
      y -= t * z;
      t = b / a; b -= t * a;
      if (b == 0) {
        assert(a == 1 || a == -1);
        return ModInt(a * y);
      }
      z -= t * y;
    }
  }
  ModInt opUnary(string op: "-")() const { return ModInt(-x); }
  ModInt opBinary(string op, T)(T a) const {
    return mixin("ModInt(this) " ~ op ~ "= a");
  }
  ModInt opBinaryRight(string op)(long a) const {
    return mixin("ModInt(a) " ~ op ~ "= this");
  }
  bool opCast(T: bool)() const { return (x != 0); }
  string toString() const { return x.to!string; }
}

enum MO = 1000000007;
alias Mint = ModInt!MO;

enum LIM = 10^^5 + 10;
Mint[] inv, fac, invFac;
void prepare() {
  inv = new Mint[LIM];
  fac = new Mint[LIM];
  invFac = new Mint[LIM];
  inv[1] = 1;
  foreach (i; 2 .. LIM) {
    inv[i] = -(Mint.M / i) * inv[cast(size_t)(Mint.M % i)];
  }
  fac[0] = invFac[0] = 1;
  foreach (i; 1 .. LIM) {
    fac[i] = fac[i - 1] * i;
    invFac[i] = invFac[i - 1] * inv[i];
  }
}
Mint binom(long n, long k) {
  if (0 <= k && k <= n) {
    assert(n < LIM);
    return fac[cast(size_t)(n)] * invFac[cast(size_t)(k)] * invFac[cast(size_t)(n - k)];
  } else {
    return Mint(0);
  }
}


int root(int[] uf, int u) {
  return (uf[u] < 0) ? u : (uf[u] = uf.root(uf[u]));
}
bool connect(int[] uf, int u, int v) {
  u = uf.root(u);
  v = uf.root(v);
  if (u == v) return false;
  if (uf[u] > uf[v]) swap(u, v);
  uf[u] += uf[v];
  uf[v] = u;
  return true;
}


void main() {
  prepare;
  try {
    for (; ; ) {
      const N = readInt();
      const K = readInt();
      auto X = new int[K];
      auto Y = new int[K];
      auto W = new Mint[K];
      foreach (k; 0 .. K) {
        X[k] = readInt() - 1;
        Y[k] = readInt() - 1;
        W[k] = readInt() - 1;
      }
      
      auto uf = new int[N + N];
      uf[] = -1;
      foreach (k; 0 .. K) {
        uf.connect(X[k], N + Y[k]);
      }
      auto kss = new int[][N + N];
      foreach (k; 0 .. K) {
        kss[uf.root(X[k])] ~= k;
      }
      
      auto CRT = new Mint[K + 1];
      CRT[0] = 1;
      foreach (r; 0 .. N + N) {
        if (!kss[r].empty) {
          int[] xs, ys;
          foreach (k; kss[r]) {
            xs ~= X[k];
            ys ~= Y[k];
          }
          xs = xs.sort.uniq.array;
          ys = ys.sort.uniq.array;
          int xsLen = cast(int)(xs.length);
          int ysLen = cast(int)(ys.length);
          int[] as, bs;
          Mint[] cs;
          foreach (k; kss[r]) {
            as ~= xs.lowerBound(X[k]);
            bs ~= ys.lowerBound(Y[k]);
            cs ~= W[k];
          }
          const m = cast(int)(cs.length);
          debug {
            writeln(as, " ", bs, " ", cs);
          }
          
          // xsLen + ysLen + (# of non-tree-edges) = m + 1
          auto here = new Mint[m + 1];
          if (min(xsLen, ysLen) <= (m + 1) / 3 - 1) {
            if (xsLen > ysLen) {
              swap(xsLen, ysLen);
              swap(xs, ys);
              swap(as, bs);
            }
            auto iss = new int[][ysLen];
            foreach (i; 0 .. m) {
              iss[bs[i]] ~= i;
            }
            auto dp = new Mint[][](xsLen + 1, 1 << xsLen);
            dp[0][0] = 1;
            foreach (b; 0 .. ysLen) {
              foreach_reverse (j; 0 .. xsLen) {
                foreach (p; 0 .. 1 << xsLen) {
                  foreach (i; iss[b]) {
                    if (!(p & 1 << as[i])) {
                      dp[j + 1][p | 1 << as[i]] += dp[j][p] * cs[i];
                    }
                  }
                }
              }
            }
            foreach (j; 0 .. xsLen + 1) {
              here[j] += dp[j].sum;
            }
          } else {
            const n = xsLen + ysLen;
            bs[] += xsLen;
            auto g = new int[][n];
            auto uf0 = new int[n];
            uf0[] = -1;
            int[] ntes;
            foreach (i; 0 .. m) {
              if (uf0.connect(as[i], bs[i])) {
                g[as[i]] ~= i;
                g[bs[i]] ~= i;
              } else {
                ntes ~= i;
              }
            }
            const ntesLen = cast(int)(ntes.length);
            debug {
              writeln("ntes = ", ntes);
            }
            
            auto sz = new int[n];
            void dfsSz(int u, int p) {
              sz[u] = 1;
              foreach (i; g[u]) {
                const v = as[i] ^ bs[i] ^ u;
                if (v != p) {
                  dfsSz(v, u);
                  sz[u] += sz[v];
                }
              }
            }
            dfsSz(0, -1);
            
            foreach (p; 0 .. 1 << ntesLen) {
              auto used = new bool[n];
              bool ok = true;
              foreach (h; 0 .. ntesLen) {
                if (p & 1 << h) {
                  const i = ntes[h];
                  ok = ok && !used[as[i]] && !used[bs[i]];
                  used[as[i]] = used[bs[i]] = true;
                }
              }
              if (ok) {
                debug {
                  writeln("  p = ", p);
                  writeln("  used = ", used);
                }
                Mint[][] dfs(int u, int p) {
                  auto crt = new Mint[][](sz[u] + 1, 2);
                  crt[0][0] = 1;
                  foreach (i; g[u]) {
                    const v = as[i] ^ bs[i] ^ u;
                    if (v != p) {
                      const res = dfs(v, u);
                      auto nxt = new Mint[][](sz[u] + 1, 2);
                      foreach (j; 0 .. sz[u] + 1) {
                        foreach (dj; 0 .. sz[v] + 1) {
                          if (j + dj <= sz[u]) {
                            nxt[j + dj][0] += crt[j][0] * res[dj][0];
                            nxt[j + dj][1] += crt[j][1] * res[dj][0];
                            if (j + dj + 1 <= sz[u]) {
                              nxt[j + dj + 1][1] += crt[j][0] * res[dj][1] * cs[i];
                            }
                          }
                        }
                      }
                      crt = nxt;
                    }
                  }
                  if (used[u]) {
                    foreach (j; 0 .. sz[u] + 1) {
                      crt[j][1] = 0;
                    }
                  } else {
                    foreach (j; 0 .. sz[u] + 1) {
                      const tmp = crt[j][0];
                      crt[j][0] += crt[j][1];
                      crt[j][1] = tmp;
                    }
                  }
                  debug {
                    writeln("    ", u, ": ", crt);
                  }
                  return crt;
                }
                const res = dfs(0, -1);
                int ofsNum;
                Mint ofsProd = 1;
                foreach (h; 0 .. ntesLen) {
                  if (p & 1 << h) {
                    const i = ntes[h];
                    ofsNum += 1;
                    ofsProd *= cs[i];
                  }
                }
                foreach (j; 0 .. sz[0] + 1) {
                  if (ofsNum + j <= m) {
                    here[ofsNum + j] += ofsProd * res[j][0];
                  }
                }
              }
            }
          }
          
          auto NXT = new Mint[K + 1];
          foreach (j; 0 .. K + 1) {
            foreach (dj; 0 .. m + 1) {
              if (j + dj <= K) {
                NXT[j + dj] += CRT[j] * here[dj];
              }
            }
          }
          CRT = NXT;
        }
      }
      
      Mint ans;
      foreach (j; 0 .. K + 1) {
        if (N - j >= 0) {
          ans += fac[N - j] * CRT[j];
        }
      }
      writeln(ans);
    }
  } catch (EOFException e) {
  }
}