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


real[][] mul(real[][] a, real[][] b) {
	const n = a.length;
	real[][] ret = new real[][](n, n);
	foreach (i; 0 .. n) {
		ret[i][] = 0.0;
	}
	foreach (i; 0 .. n) foreach (k; 0 .. n) foreach (j; 0 .. n) {
		ret[i][j] += a[i][k] * b[k][j];
	}
	return ret;
}

int N, M, K;
bool[] S;
int[] A, B;

void main(string[] args) {
	try {
	for (; ; ) {
		N = readInt;
		M = readInt;
		K = readInt;
		S = new bool[N];
		foreach (u; 0 .. N) {
			S[u] = (readInt != 0);
		}
		A = new int[M];
		B = new int[M];
		foreach (i; 0 .. M) {
			A[i] = readInt - 1;
			B[i] = readInt - 1;
		}
		
		int[] us;
		foreach (u; 0 .. N) {
			if (u == 0 || S[u]) {
				us ~= u;
			}
		}
		int[] ids = new int[N];
		ids[] = -1;
		foreach (j, u; us) {
			ids[u] = j;
		}
		
		int[][] G = new int[][N];
		foreach (i; 0 .. M) {
			G[A[i]] ~= B[i];
			G[B[i]] ~= A[i];
		}
		
		real[][] a = new real[][](N, N + us.length);
		foreach (u; 0 .. N) {
			a[u][] = 0.0;
			if (S[u]) {
				a[u][u] = 1.0;
				a[u][N + ids[u]] = 1.0;
			} else {
				a[u][u] -= G[u].length;
				foreach (v; G[u]) {
					a[u][v] += 1.0;
				}
			}
		}
// writeln(a);
		
		foreach (h; 0 .. N) {
			int im = h;
			foreach (i; h + 1 .. N) {
				if (abs(a[im][h]) < abs(a[i][h])) {
					im = i;
				}
			}
			swap(a[h], a[im]);
			a[h][h .. $] /= a[h][h];
			foreach (i; h + 1 .. N) {
				a[i][h .. $] -= a[h][h .. $] * a[i][h];
			}
		}
		foreach_reverse (h; 0 .. N) {
			foreach (i; h + 1 .. N) {
				a[h][i .. $] -= a[i][i .. $] * a[h][i];
			}
		}
// writeln(a);
		
		real[][] prob = new real[][](us.length, us.length);
		foreach (i; 0 .. us.length) foreach (j; 0 .. us.length) {
			//	from us[j] to us[i]
			prob[i][j] = 0.0;
			foreach (v; G[us[j]]) {
				prob[i][j] += a[v][N + i];
			}
			prob[i][j] /= G[us[j]].length;
		}
// writeln("prob = ",prob);
		
		real[][] y = new real[][](us.length, us.length);
		foreach (i; 0 .. us.length) {
			y[i][] = 0.0;
			y[i][i] = 1.0;
		}
		for (int e = K - 1; e; e >>= 1, prob = mul(prob, prob)) if (e & 1) {
			y = mul(y, prob);
		}
		writefln("%.10f", y[$ - 1][0]);		
	}
	} catch (EOFException) {}
}