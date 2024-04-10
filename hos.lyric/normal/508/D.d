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
	if (u == v) return false;
	if (uf[u] > uf[v]) swap(u, v);
	uf[u] += uf[v];
	uf[v] = u;
	return true;
}


immutable V = 62 * 62;

int tr(char c) {
	return ('0' <= c && c <= '9') ? (0 + (c - '0')) : ('A' <= c && c <= 'Z') ? (10 + (c - 'A')) : (36 + (c - 'a'));
}
int tr(string s) {
	return tr(s[0]) * 62 + tr(s[1]);
}
char rt(int x) {
	return cast(char)((0 <= x && x < 10) ? ('0' + (x - 0)) : (10 <= x && x < 36) ? ('A' + (x - 10)) : ('a' + (x - 36)));
}

int E;
string[] S;

int[][] adj;
int[] path;

void dfs(int u) {
	foreach (v; 0 .. V) {
		if (adj[u][v]) {
			--adj[u][v];
			dfs(v);
		}
	}
	path ~= u;
}

bool solve() {
	adj = new int[][](V, V);
	foreach (s; S) {
		const u = tr(s[0 .. 2]);
		const v = tr(s[1 .. 3]);
		++adj[u][v];
	}
	
	int[] deg = new int[V];
	foreach (u; 0 .. V) foreach (v; 0 .. V) {
		deg[u] += adj[u][v];
		deg[v] -= adj[u][v];
	}
	int sum;
	foreach (u; 0 .. V) {
		if (deg[u] > 0) {
			sum += deg[u];
		}
	}
	if (sum > 1) {
		return false;
	}
	
	int[] uf = new int[V];
	uf[] = -1;
	foreach (u; 0 .. V) foreach (v; 0 .. V) {
		if (adj[u][v]) {
			uf.conn(u, v);
		}
	}
	int r = -1;
	foreach (u; 0 .. V) foreach (v; 0 .. V) {
		if (adj[u][v]) {
			if (r == -1) {
				r = uf.root(u);
			}
			if (r != uf.root(u)) {
				return false;
			}
		}
	}
	
	assert(r != -1);
	int src = r;
	foreach (u; 0 .. V) {
		if (deg[u] > 0) {
			src = u;
			break;
		}
	}
	path = new int[0];
	dfs(src);
	path.reverse;
	return true;
}

void main(string[] args) {
	try {
	for (; ; ) {
		E = readInt;
		S = new string[E];
		foreach (e; 0 .. E) {
			S[e] = readToken;
		}
		
		const res = solve;
		if (res) {
			writeln("YES");
debug{
writeln("path = ",path);
}
			string ans;
			ans ~= rt(path[0] / 62);
			foreach (u; path) {
				ans ~= rt(u % 62);
			}
			writeln(ans);
		} else {
			writeln("NO");
		}
		
	}
	} catch (EOFException) {}
}