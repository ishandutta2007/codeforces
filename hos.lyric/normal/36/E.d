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

immutable N = 10005;
int M;
int[] A, B;

int[][] G;
int[] deg;

bool[] used;
int[] path;
void dfs(int u) {
	foreach (i; G[u]) {
		if (!used[i]) {
			used[i] = true;
			dfs(A[i] ^ B[i] ^ u);
			path ~= i;
		}
	}
}

int[] eulerianPath(int[] us) {
	int[] odds;
	foreach (u; us) {
		if (deg[u] % 2 != 0) {
			odds ~= u;
		}
	}
	switch (odds.length) {
		case 0: {
			path.clear;
			dfs(us[0]);
			return path;
		} break;
		case 2: {
			path.clear;
			dfs(odds[0]);
			return path;
		} break;
		default: {
			return null;
		}
	}
}

int[][] solve() {
	G = new int[][N];
	deg = new int[N];
	foreach (i; 0 .. M) {
		G[A[i]] ~= i;
		G[B[i]] ~= i;
		++deg[A[i]];
		++deg[B[i]];
	}
	used = new bool[M];
	
	if (M < 2) {
		return null;
	}
	
	int[] uf = new int[N];
	uf[] = -1;
	foreach (i; 0 .. M) {
		uf.conn(A[i], B[i]);
	}
	int[][] us = new int[][N];
	foreach (u; 0 .. N) {
		us[uf.root(u)] ~= u;
	}
	int[][] edges = new int[][N];
	foreach (i; 0 .. M) {
		edges[uf.root(A[i])] ~= i;
	}
	const numCompos = edges.count!"!a.empty";
	if (numCompos == 1) {
		int[] odds;
		foreach (u; 0 .. N) {
			if (deg[u] % 2 != 0) {
				odds ~= u;
			}
		}
		switch (odds.length) {
			case 0: {
				path.clear;
				dfs(A[0]);
				return [ path[0 .. 1], path[1 .. $] ];
			} break;
			case 2: {
				path.clear;
				dfs(odds[0]);
				return [ path[0 .. 1], path[1 .. $] ];
			} break;
			case 4: {
				A ~= odds[0];
				B ~= odds[1];
				G[A[M]] ~= M;
				G[B[M]] ~= M;
				used ~= false;
				path.clear;
				dfs(odds[2]);
				const int idx = path.length - path.find(M).length;
				return [ path[0 .. idx], path[idx + 1 .. $] ];
			} break;
			default: {
				return null;
			}
		}
	} else if (numCompos == 2) {
		int[][] ret;
		foreach (r; 0 .. N) if (!edges[r].empty) {
			if (auto res = us[r].eulerianPath) {
				ret ~= res;
			} else {
				return null;
			}
		}
		return ret;
	} else {
		return null;
	}
}

void main(string[] args) {
	auto inp = File("input.txt", "r");
	auto outp = File("output.txt", "w");
	for (string line; (line = inp.readln) != null; ) {
		M = line.chomp.to!int;
		A = new int[M];
		B = new int[M];
		foreach (i; 0 .. M) {
			auto tks = inp.readln.split;
			A[i] = tks[0].to!int;
			B[i] = tks[1].to!int;
		}
debug{
writeln("A = ",A);
writeln("B = ",B);
}
		
		if (auto res = solve) {
debug{
writeln("res = ",res);
}
			foreach (path; res) {
				outp.writeln(path.length);
				path[] += 1;
				outp.writeln(path.to!string.removechars("[],"));
			}
		} else {
			outp.writeln(-1);
		}
	}
}