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


enum INF = 10^^9 + 58;

void main() {
  try {
    for (; ; ) {
      const N = readInt();
      const M = readInt() * 2;
      auto A = new int[M];
      auto B = new int[M];
      auto L = new int[M];
      auto R = new int[M];
      for (int i = 0; i < M; i += 2) {
        A[i] = B[i ^ 1] = readInt() - 1;
        B[i] = A[i ^ 1] = readInt() - 1;
        L[i] = L[i ^ 1] = readInt();
        R[i] = R[i ^ 1] = readInt();
      }
      
      auto G = new int[][N];
      foreach (i; 0 .. M) {
        G[A[i]] ~= i;
      }
      
      auto deg = new int[N];
      foreach (u; 0 .. N) {
        deg[u] = cast(int)(G[u].length);
        G[u].sort!((i0, i1) => (L[i0] < L[i1]));
      }
      auto itr = new int[][](N, 2);
      auto lasts = new int[][](N, 2);
      foreach (u; 0 .. N) {
        lasts[u][] = -INF;
      }
      
      alias Node = Tuple!(int, "c", int, "i");
      BinaryHeap!(Array!Node, "a.c > b.c") que;
      auto dist = new int[][](M, 2);
      foreach (i; 0 .. M) {
        dist[i][] = INF;
      }
      
      void update(int u, int s, int lb, int ub) {
        debug {
          writefln("%s %s [%s, %s]", u, s, lb, ub);
        }
        chmax(lb, lasts[u][s] + 2);
        if (s != (ub & 1)) {
          --ub;
        }
        if (lb <= ub) {
          for (int i; itr[u][s] < deg[u] && L[i = G[u][itr[u][s]]] <= ub; ++itr[u][s]) {
            int cc = max(lb, L[i]);
            if (s != (cc & 1)) {
              ++cc;
            }
            if (cc <= ub && cc <= R[i]) {
              if (chmin(dist[i][cc & 1], cc)) {
                que.insert(Node(cc, i));
              }
            }
          }
          lasts[u][s] = ub;
        }
      }
      
      update(0, 0, 0, 0);
      for (; !que.empty; ) {
        const c = que.front.c;
        const i = que.front.i;
        que.removeFront;
        if (dist[i][c & 1] == c) {
          update(B[i], (c + 1) & 1, c + 1, R[i]);
        }
      }
      debug {
        writeln("dist = ", dist);
      }
      
      int ans = INF;
      if (0 == N - 1) {
        chmin(ans, 0);
      }
      foreach (i; G[N - 1]) {
        foreach (s; 0 .. 2) {
          const cc = dist[i ^ 1][s] + 1;
          if (cc <= R[i ^ 1]) {
            chmin(ans, cc);
          }
        }
      }
      writeln((ans >= INF) ? -1 : ans);
    }
  } catch (EOFException e) {
  }
}