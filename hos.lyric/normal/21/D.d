import core.thread;
import std.conv, std.stdio, std.string;
import std.algorithm, std.array, std.bigint, std.container, std.math, std.range, std.regex;

//	Input
class EOFException : Throwable { this() { super("EOF"); } }
string[] tokens;
string readToken() { for (; tokens.empty; ) { tokens = readln.split; if (stdin.eof) throw new EOFException; } auto token = tokens[0]; tokens.popFront; return token; }
int readInt() { return to!int(readToken); }
long readLong() { return to!long(readToken); }
real readReal() { return to!real(readToken); }

//	chmin/chmax
void chmin(T)(ref T t, in T f) { if (t > f) t = f; }
void chmax(T)(ref T t, in T f) { if (t < f) t = f; }

//	Pair
struct Pair(S, T) {
	S x; T y;
	int opCmp(    const Pair p) const { return (x < p.x) ? -1 : (x > p.x) ? +1 : (y < p.y) ? -1 : (y > p.y) ? +1 : 0; }
	int opCmp(ref const Pair p) const { return (x < p.x) ? -1 : (x > p.x) ? +1 : (y < p.y) ? -1 : (y > p.y) ? +1 : 0; }
	string toString() const { return "(" ~ to!string(x) ~ ", " ~ to!string(y) ~ ")"; }
}
auto pair(S, T)(inout(S) x, inout(T) y) { return Pair!(S, T)(x, y); }

//	Array
int binarySearch(T)(in T[] as, in bool delegate(T) test) { int low = -1, upp = as.length; for (; low + 1 < upp; ) { int mid = (low + upp) >> 1; (test(as[mid]) ? low : upp) = mid; } return upp; }
int lowerBound(T)(in T[] as, in T val) { return as.binarySearch((T a) { return (a <  val); }); }
int upperBound(T)(in T[] as, in T val) { return as.binarySearch((T a) { return (a <= val); }); }
T[] unique(T)(in T[] as) { T[] bs; foreach (a; as) if (bs.empty || bs[$ - 1] != a) bs ~= a; return bs; }


int root(int[] uf, int u) {
	return (uf[u] < 0) ? u : (uf[u] = uf.root(uf[u]));
}
bool conn(int[] uf, int u, int v) {
	u = uf.root(u);
	v = uf.root(v);
	if (u == v) return 0;
	if (uf[u] > uf[v]) swap(u, v);
	uf[u] += uf[v];
	uf[v] = u;
	return 1;
}

immutable INF = 1_000_000_000;

int N, M;
int[] A, B, C;

int[][] D;

void main(string[] args) {
	try {
	for (; ; ) {
		N = readInt;
		M = readInt;
		A = new int[M];
		B = new int[M];
		C = new int[M];
		foreach (i; 0 .. M) {
			A[i] = readInt - 1;
			B[i] = readInt - 1;
			C[i] = readInt;
		}
		
		int[] uf = new int[N];
		uf[] = -1;
		foreach (i; 0 .. M) {
			uf.conn(A[i], B[i]);
		}
		bool ok = true;
		foreach (i; 0 .. M) {
			if (uf.root(0) != uf.root(A[i])) {
				ok = false;
				break;
			}
		}
		if (!ok) {
			writeln(-1);
			continue;
		}
		
		int[] deg = new int[N];
		foreach (i; 0 .. M) {
			++deg[A[i]];
			++deg[B[i]];
		}
		
		int[][] D = new int[][](N, N);
		foreach (u; 0 .. N) {
			D[u][] = INF;
			// D[u][u] = 0;
		}
		foreach (i; 0 .. M) {
			chmin(D[A[i]][B[i]], C[i]);
			chmin(D[B[i]][A[i]], C[i]);
		}
		foreach (w; 0 .. N) foreach (u; 0 .. N) foreach (v; 0 .. N) {
			chmin(D[u][v], D[u][w] + D[w][v]);
		}
		
		int start;
		foreach (u; 0 .. N) {
			if (deg[u] % 2 == 0) {
				start |= 1 << u;
			}
		}
		
		int[] dp = new int[1 << N];
		dp[] = INF;
		dp[start] = 0;
		foreach (p; 0 .. 1 << N) {
			foreach (u; 0 .. N) foreach (v; 0 .. N) if (u != v && !(p & 1 << u) && !(p & 1 << v)) {
				chmin(dp[p | 1 << u | 1 << v], dp[p] + D[u][v]);
			}
		}
		
		const ans = reduce!"a + b"(0, C) + dp[(1 << N) - 1];
		if (ans >= INF) {
			writeln(-1);
		} else {
			writeln(ans);
		}
	}
	} catch (EOFException) {}
}