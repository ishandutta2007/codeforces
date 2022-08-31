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


uint xrand() {
  static uint x = 314159265, y = 358979323, z = 846264338, w = 327950288;
  uint t = x ^ x << 11; x = y; y = z; z = w; return w = w ^ w >> 19 ^ t ^ t >> 8;
}


int N, M;
int[] A, B, W;

alias Edge = Tuple!(int, "i", int, "v");
Edge[][][] G;

int[][] uss, iss;
int[] see;
bool[] used;
void dfs(int w, int u) {
  for (; see[u] < G[w][u].length; ) {
    const i = G[w][u][see[u]].i;
    const v = G[w][u][see[u]].v;
    ++see[u];
    if (!used[i]) {
      used[i] = true;
      debug {
        // writefln("euler(%s); %s -> %s", w, u, v);
      }
      dfs(w, v);
      iss[w] ~= i;
    }
  }
  uss[w] ~= u;
}


void main() {
  try {
    for (; ; ) {
      N = readInt();
      M = readInt();
      A = new int[M];
      B = new int[M];
      W = new int[M];
      foreach (i; 0 .. M) {
        A[i] = readInt() - 1;
        B[i] = readInt() - 1;
        W[i] = readInt();
      }
      
      auto deg = new int[][](3, N);
      foreach (i; 0 .. M) {
        ++deg[W[i]][A[i]];
        ++deg[W[i]][B[i]];
      }
      
      G = new Edge[][][](3, N + 1);
      foreach (i; 0 .. M) {
        G[W[i]][A[i]] ~= Edge(i, B[i]);
        G[W[i]][B[i]] ~= Edge(i, A[i]);
      }
      foreach (w; [1, 2]) {
        foreach (u; 0 .. N) {
          if (deg[w][u] & 1) {
            G[w][u] ~= Edge(M + u, N);
            G[w][N] ~= Edge(M + u, u);
          }
        }
      }
      
      uss = new int[][](3);
      iss = new int[][](3);
      foreach (w; [1, 2]) {
        see = new int[N + 1];
        used = new bool[M + N];
        foreach_reverse (u; 0 .. N + 1) {
          dfs(w, u);
          iss[w] ~= -1;
        }
        debug {
          writefln("uss[%s] = %s", w, uss[w]);
          writefln("iss[%s] = %s", w, iss[w]);
        }
      }
      
      alias Entry = Tuple!(int, "to", int, "j", int, "k");
      auto ess = new Entry[][](3, N);
      foreach (w; [1, 2]) {
        ess[w][] = Entry(-1, -1, -1);
        const len = cast(int)(iss[w].length);
        for (int j = 0, k; j < len; j = k) {
          for (k = j + 1; k < len && uss[w][k] != N; ++k) {}
          if (k == len) {
            break;
          }
          const u = uss[w][j + 1];
          const v = uss[w][k - 1];
          debug {
            writefln("waf %s; %s -> %s", w, u, v);
          }
          ess[w][u] = Entry(v, j + 1, k - 1);
          ess[w][v] = Entry(u, k - 1, j + 1);
        }
      }
      
      auto ans = new char[M];
      ans[] = '?';
      foreach (w; [1, 2]) {
        const len = cast(int)(iss[w].length);
        foreach (j; 0 .. len - 1) {
          const i = iss[w][j];
          const u = uss[w][j];
          const v = uss[w][j + 1];
          if (0 <= i && i < M) {
            if (u == A[i] && v == B[i]) {
              ans[i] = '1';
            } else if (u == B[i] && v == A[i]) {
              ans[i] = '2';
            } else {
              assert(false);
            }
          }
        }
      }
      void flip(int w, int j, int k) {
        debug {
          writefln("flip %s [%s, %s]", w, j, k);
        }
        if (j > k) {
          swap(j, k);
        }
        foreach (l; j .. k) {
          const i = iss[w][l];
          if (0 <= i && i < M) {
            ans[i] ^= '1' ^ '2';
          }
        }
      }
      
      auto vis = new bool[N];
      foreach (r; 0 .. N) if (!vis[r]) {
        foreach (w0; [1, 2]) {
          for (int w = w0, u = r; ; ) {
            vis[u] = true;
            const v = ess[w][u].to;
            const j = ess[w][u].j;
            const k = ess[w][u].k;
            if (!~v) {
              break;
            }
            ess[w][u] = ess[w][v] = Entry(-1, -1, -1);
            debug {
              writefln("%s %s; %s; %s -> %s [%s, %s]", r, w0, w, u, v, j, k);
            }
            if ((w0 == 1) != (j < k)) {
              flip(w, j, k);
            }
            if (v == r) {
              break;
            }
            w ^= 1 ^ 2;
            u = v;
          }
        }
      }
      
      const score = deg[1].count!((a) => (a % 2 != 0));
      writeln(score);
      writeln(ans);
      
      auto vals = new int[N];
      foreach (i; 0 .. M) {
        final switch (ans[i]) {
          case '1': vals[A[i]] += W[i]; vals[B[i]] -= W[i]; break;
          case '2': vals[B[i]] += W[i]; vals[A[i]] -= W[i]; break;
        }
      }
      debug {
        writeln("vals = ", vals);
      }
      assert(score == vals.count!((a) => abs(a) == 1));
    }
  } catch (EOFException e) {
  }
}