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


int N, K;
int[] A, B;

int[][] G;
int[] ipar;
int[][] vs;
int[] sz;
int[][][] dp;
int[][][] prv;

void solve(int u, int ip) {
	ipar[u] = ip;
	sz[u] = 1;
	foreach (i; G[u]) if (i != ip) {
		const v = A[i] ^ B[i] ^ u;
		vs[u] ~= v;
		solve(v, i);
		sz[u] += sz[v];
	}
	dp[u] = new int[][](vs[u].length + 1, sz[u] + 1);
	prv[u] = new int[][](vs[u].length + 1, sz[u] + 1);
	foreach (j; 0 .. vs[u].length + 1) {
		dp[u][j][] = N;
	}
	dp[u][0][1] = 0;
	foreach (j, v; vs[u]) {
		foreach (x; 0 .. sz[u] + 1) if (dp[u][j][x] < N) {
			//	connect
			foreach (y; 0 .. sz[v] + 1) if (x + y <= sz[u]) {
				if (dp[u][j + 1][x + y] > dp[u][j][x] + dp[v][$ - 1][y]) {
					dp[u][j + 1][x + y] = dp[u][j][x] + dp[v][$ - 1][y];
					prv[u][j + 1][x + y] = y;
				}
			}
			//	cut
			if (dp[u][j + 1][x] > dp[u][j][x] + 1) {
				dp[u][j + 1][x] = dp[u][j][x] + 1;
				prv[u][j + 1][x] = -2;
			}
		}
	}
}

int[] ans;
void recover(int u, int k) {
debug{
writeln("recover ",u," ",k);stdout.flush;
}
	assert(k <= sz[u]);
	int j = vs[u].length;
	int x = k;
	foreach_reverse (i; G[u]) if (i != ipar[u]) {
		const v = A[i] ^ B[i] ^ u;
		const y = prv[u][j][x];
		if (y == -2) {
			ans ~= i;
			--j;
		} else {
			recover(v, y);
			--j;
			x -= y;
		}
	}
	assert(j == 0);
	assert(x == 1);
}

void main(string[] args) {
	try {
	for (; ; ) {
		N = readInt;
		K = readInt;
		A = new int[N - 1];
		B = new int[N - 1];
		foreach (i; 0 .. N - 1) {
			A[i] = readInt - 1;
			B[i] = readInt - 1;
		}
		
		G = new int[][N];
		foreach (i; 0 .. N - 1) {
			G[A[i]] ~= i;
			G[B[i]] ~= i;
		}
		ipar = new int[N];
		ipar[] = -1;
		vs = new int[][N];
		sz = new int[N];
		dp = new int[][][N];
		prv = new int[][][N];
		solve(0, -1);
debug{
writeln("ipar = ",ipar);
writeln("vs = ",vs);
writeln("sz = ",sz);
writeln("dp = ",dp);
}
		int opt = dp[0][$ - 1][K];
		int um = 0;
		foreach (u; 1 .. N) {
			if (K <= sz[u]) {
				if (opt > 1 + dp[u][$ - 1][K]) {
					opt = 1 + dp[u][$ - 1][K];
					um = u;
				}
			}
		}
		
		ans.clear;
		if (um != 0) {
			ans ~= ipar[um];
		}
		recover(um, K);
debug{
writeln("ans = ",ans);
}
		writeln(ans.length);
		ans[] += 1;
		writeln(ans.to!string.removechars("[],"));
	}
	} catch (EOFException) {}
}