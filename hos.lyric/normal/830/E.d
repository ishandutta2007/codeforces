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


/*
  x "--- x t"
  x (x t) - (x t)^2 = x^2 (t - t^2) <= (1/4) x^2  (max at t = 1/2)
  
  x "--- x t --- *"
  x (x t) - (x t)^2 + (1/4) (x t)^2 = x^2 (t - (3/4) t^2) <= (1/3) x^2  (max at t = 2/3)
  
  x "--- x t --- * --- *"
  x (x t) - (x t)^2 + (1/3) (x t)^2 = x^2 (t - (2/3) t^2) <= (3/8) x^2  (max at t = 3/4)
  
  x "--- * --- * ... --- *"
  (1/2 - 1/(2(k+1))) x^2 at (k/(k+1)) x, ..., (1/(k+1)) x
  
  deg = 3
  -x^2 + \sum_{j=1}^3 (1/2 - 1/(2(k_j+1))) x^2
  = (1/2) (1 - \sum_{j=1}^3 1/(k_j+1)) x^2
  
  1/2 + 1/3 + 1/6
  1/2 + 1/4 + 1/4
  1/3 + 1/3 + 1/3
*/
void main() {
  try {
    for (; ; ) {
      const numCases = readInt();
      foreach (caseId; 0 .. numCases) {
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
          G[A[i]] ~= i;
          G[B[i]] ~= i;
        }
        auto uf = new int[N];
        uf[] = -1;
        foreach (i; 0 .. M) {
          uf.connect(A[i], B[i]);
        }
        auto uss = new int[][N];
        foreach (u; 0 .. N) {
          uss[uf.root(u)] ~= u;
        }
        auto iss = new int[][N];
        foreach (i; 0 .. M) {
          iss[uf.root(A[i])] ~= i;
        }
        
        auto ans = new long[N];
        foreach (r; 0 .. N) {
          if (uf[r] < 0) {
            if (cast(int)(iss[r].length) >= -uf[r]) {
              foreach (u; uss[r]) {
                ans[u] = 1;
              }
            } else {
              const us4 = uss[r].filter!(u => (G[u].length >= 4)).array;
              if (us4.length >= 1) {
                foreach (u; uss[r]) {
                  ans[u] = 1;
                }
                ans[us4[0]] = 2;
              } else {
                const us3 = uss[r].filter!(u => (G[u].length >= 3)).array;
                if (us3.length >= 2) {
                  int dfs(int u, int p) {
                    int ret = 1;
                    foreach (i; G[u]) {
                      const v = A[i] ^ B[i] ^ u;
                      if (v != p) {
                        const res = dfs(v, u);
                        if (res == 2) {
                          ret = 2;
                        }
                      }
                    }
                    if (u == us3[1]) {
                      ret = 2;
                    }
                    return ans[u] = ret;
                  }
                  dfs(us3[0], -1);
                } else if (us3.length >= 1) {
                  auto vss = new int[][3];
                  foreach (j; 0 .. 3) {
                    const i0 = G[us3[0]][j];
                    for (int p = us3[0], u = A[i0] ^ B[i0] ^ us3[0]; ; ) {
                      vss[j] ~= u;
                      if (G[u].length == 1) {
                        break;
                      }
                      foreach (i; G[u]) {
                        const v = A[i] ^ B[i] ^ u;
                        if (v != p) {
                          p = u;
                          u = v;
                          break;
                        }
                      }
                    }
                  }
                  vss.sort!"a.length < b.length";
                  debug {
                    writeln("vss = ", vss);
                  }
                  foreach (ks; [[1, 2, 5], [1, 3, 3], [2, 2, 2]]) {
                    bool ok = true;
                    foreach (j; 0 .. 3) {
                      ok = ok && (vss[j].length >= ks[j]);
                    }
                    if (ok) {
                      ans[us3[0]] = 12;
                      foreach (j; 0 .. 3) {
                        foreach (l; 0 .. ks[j]) {
                          ans[vss[j][l]] = 12 / (ks[j] + 1) * (ks[j] - l);
                        }
                      }
                      break;
                    }
                  }
                }
              }
            }
          }
        }
        
        long score;
        foreach (u; 0 .. N) {
          score -= ans[u]^^2;
        }
        foreach (i; 0 .. M) {
          score += ans[A[i]] * ans[B[i]];
        }
        debug {
          writeln("score = ", score);
        }
        if (score >= 0 && ans.sum > 0) {
          writeln("YES");
          foreach (u; 0 .. N) {
            if (u > 0) write(" ");
            write(ans[u]);
          }
          writeln;
        } else {
          writeln("NO");
        }
      }
    }
  } catch (EOFException e) {
  }
}