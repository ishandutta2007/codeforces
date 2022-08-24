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


int N, M;
int[] A, B;

int[][] G;

int zeit;
int[] dis, low, parE, dep;
int[][] backEdges;
int[] cntTotal;
int[][] cnt;

void dfs(int u, int ip, int d) {
debug{
writeln("dfs ",u," ",ip," ",d);
}
	dis[u] = low[u] = zeit++;
	parE[u] = ip;
	dep[u] = d;
	foreach (i; G[u]) if (i != ip) {
		const v = A[i] ^ B[i] ^ u;
		if (dis[v] == -1) {
			dfs(v, i, d + 1);
			chmin(low[u], low[v]);
		} else if (dep[u] > dep[v]) {
debug{
writeln("  back edge ",u," ",v);
}
			//	back edge uv
			//	0: bad 1: good
			const s = (dep[u] - dep[v]) % 2;
			backEdges[s] ~= i;
			++cntTotal[s];
			++cnt[u][s];
			--cnt[v][s];
			chmin(low[u], dis[v]);
		}
	}
}

int[] ans;

void solve(int u) {
	foreach (i; G[u]) if (i != parE[u]) {
		const v = A[i] ^ B[i] ^ u;
		if (i == parE[v]) {
			solve(v);
			cnt[u][] += cnt[v][];
		}
	}
	if (parE[u] != -1) {
		//	try removing parE[u]
		if (cntTotal[0] - cnt[u][0] == 0 && (cnt[u][0] == 0 || cnt[u][1] == 0)) {
			ans ~= parE[u];
		}
	}
}

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
		
		G = new int[][N];
		foreach (i; 0 .. M) {
			G[A[i]] ~= i;
			G[B[i]] ~= i;
		}
		
		zeit = 0;
		dis = new int[N];
		low = new int[N];
		parE = new int[N];
		dep = new int[N];
		backEdges = new int[][2];
		cntTotal = new int[2];
		cnt = new int[][](N, 2);
		dis[] = -1;
		foreach (u; 0 .. N) {
			if (dis[u] == -1) {
				dfs(u, -1, 0);
			}
		}
debug{
writeln("dis = ",dis);
writeln("low = ",low);
writeln("parE = ",parE);
writeln("dep = ",dep);
writeln("backEdges = ",backEdges);
writeln("cntTotal = ",cntTotal);
writeln("cnt = ",cnt);
}
		
		ans.clear;
		
		//	removing a tree edge
		foreach (u; 0 .. N) {
			if (parE[u] == -1) {
				solve(u);
			}
		}
debug{
writeln("cnt (summed) = ",cnt);
}
		
		//	removing a back edge
		if (cntTotal[0] == 0) {
			ans ~= backEdges[0];
			ans ~= backEdges[1];
		} if (cntTotal[0] == 1) {
			ans ~= backEdges[0];
		}
		
		ans.sort();
		writeln(ans.length);
		foreach (idx, i; ans) {
			if (idx > 0) {
				write(" ");
			}
			write(i + 1);
		}
		writeln;
	}
	} catch (EOFException) {}
}