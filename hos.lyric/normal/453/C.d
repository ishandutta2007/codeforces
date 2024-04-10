import core.thread;
import std.conv, std.stdio, std.string;
import std.algorithm, std.array, std.bigint, std.math, std.range;

//	Input
class EOFException : Throwable { this() { super("EOF"); } }
string[] tokens;
string readToken() { for (; tokens.empty; ) { tokens = readln.split; if (stdin.eof) throw new EOFException; } auto token = tokens[0]; tokens.popFront; return token; }
int readInt() { return to!int(readToken); }
long readLong() { return to!long(readToken); }
real readReal() { return to!real(readToken); }

//	chmin/chmax
void chmin(T)(ref T t, const T f) { if (t > f) t = f; }
void chmax(T)(ref T t, const T f) { if (t < f) t = f; }

//	Pair
struct Pair(S, T) {
	S x; T y;
	int opCmp(ref const Pair p) const { return (x < p.x) ? -1 : (x > p.x) ? +1 : (y < p.y) ? -1 : (y > p.y) ? +1 : 0; }
	string toString() const { return "(" ~ to!string(x) ~ ", " ~ to!string(y) ~ ")"; }
}
auto pair(S, T)(S x, T y) { return Pair!(S, T)(x, y); }

//	Array
int binarySearch(T)(T[] as, bool delegate(T) test) { int low = -1, upp = as.length; for (; low + 1 < upp; ) { int mid = (low + upp) >> 1; (test(as[mid]) ? low : upp) = mid; } return upp; }
int lowerBound(T)(T[] as, T val) { return as.binarySearch((T a) { return (a <  val); }); }
int upperBound(T)(T[] as, T val) { return as.binarySearch((T a) { return (a <= val); }); }
T[] unique(T)(T[] as) { T[] bs; foreach (a; as) if (bs.empty || bs[$ - 1] != a) bs ~= a; return bs; }


int N, M;
int[][] G;
int[] X;

int[] par;
void dfs(int u, int p) {
	par[u] = p;
	foreach (v; G[u]) if (v != p) {
		if (par[v] == -2) {
			dfs(v, u);
		}
	}
}

int[] ans;
int[] cnt;
void solve(int u, int p) {
	ans ~= u;
	cnt[u] ^= 1;
	foreach (v; G[u]) if (u == par[v]) {
		solve(v, u);
		ans ~= u;
		cnt[u] ^= 1;
	}
	if (cnt[u] != X[u]) {
		if (p != -1) {
			ans ~= p;
			cnt[p] ^= 1;
			ans ~= u;
			cnt[u] ^= 1;
		} else {
			assert(ans[$ - 1] == u);
			ans.popBack;
			cnt[u] ^= 1;
		}
	}
}

void main(string[] args) {
	try {
	for (; ; ) {
		N = readInt;
		M = readInt;
		G = new int[][N];
		foreach (i; 0 .. M) {
			const u = readInt - 1;
			const v = readInt - 1;
			G[u] ~= v;
			G[v] ~= u;
		}
		X = new int[N];
		foreach (u; 0 .. N) {
			X[u] = readInt;
		}
		
		int src = -1;
		foreach (u; 0 .. N) {
			if (X[u]) {
				src = u;
				break;
			}
		}
		if (src == -1) {
			writeln("0");
			continue;
		}
		
		par = new int[N];
		par[] = -2;
		dfs(src, -1);
		
		bool ok = true;
		foreach (u; 0 .. N) {
			if (X[u]) {
				if (par[u] == -2) {
					ok = false;
					break;
				}
			}
		}
		if (!ok) {
			writeln("-1");
			continue;
		}
		
		ans = new int[0];
		cnt = new int[N];
		solve(src, -1);
		writeln(ans.length);
		foreach (j, u; ans) {
			if (j > 0) write(" ");
			write(u + 1);
		}
		writeln;
		
	}
	} catch (EOFException) {}
}