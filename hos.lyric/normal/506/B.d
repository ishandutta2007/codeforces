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
auto pair(S, T)(inout(S) x,       T  y) { return Pair!(S, T)(x, y); }

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
	if (u == v) return false;
	if (uf[u] > uf[v]) swap(u, v);
	uf[u] += uf[v];
	uf[v] = u;
	return true;
}

Pair!(int, int[]) scc(int[][] g0, int[][] g1) {
	int n = g0.length;
	int compN;
	int[] compIds = new int[n];
	void dfs(int[][] g, int u, int a, int b, ref int[] st) {
		if (compIds[u] == a) {
			compIds[u] = b;
			foreach (v; g[u]) dfs(g, v, a, b, st);
			st ~= u;
		}
	}
	int[] stack, dump;
	foreach (u; 0 .. n) {
		dfs(g0, u, 0, -1, stack);
	}
	for (; !stack.empty; ) {
		int u = stack[$ - 1];
		if (compIds[u] == -1) {
			dfs(g1, u, -1, compN, dump);
			++compN;
		}
		stack.popBack;
	}
	return pair(compN, compIds);
}

int N, M;
int[] A, B;

void main(string[] args) {
	try {
	for (; ; ) {
		N = readInt;
		M = readInt;
		A = new int[M];
		B = new int[M];
		foreach (i; 0 .. M) {
			A[i] = readInt - 1;
			B[i] = readInt - 1;
		}
		
		int[] uf = new int[N];
		fill(uf, -1);
		foreach (i; 0 .. M) {
			uf.conn(A[i], B[i]);
		}
		int[][] uComps = new int[][N];
		foreach (u; 0 .. N) {
			uComps[uf.root(u)] ~= u;
		}
		
		int[][] g0 = new int[][N];
		int[][] g1 = new int[][N];
		foreach (i; 0 .. M) {
			g0[A[i]] ~= B[i];
			g1[B[i]] ~= A[i];
		}
		int[] compIds = scc(g0, g1).y;
		
		int ans;
		foreach (uComp; uComps) if (!uComp.empty) {
			const int sz = uComp.length;
			int[] ids = new int[sz];
			foreach (j; 0 .. sz) {
				ids[j] = compIds[uComp[j]];
			}
			ids.sort();
			bool ok = true;
			foreach (j; 1 .. sz) {
				ok = ok && (ids[j - 1] != ids[j]);
			}
			ans += ok ? (sz - 1) : sz;
		}
		writeln(ans);
	}
	} catch (EOFException) {}
}