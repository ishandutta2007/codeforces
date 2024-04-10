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
int[] A, B, C;

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
		
		auto g = new int[][N];
		foreach (i; 0 .. M) {
			g[A[i]] ~= i;
			g[B[i]] ~= i;
		}
		
		int[] q;
		int[] d = new int[N];
		d[] = -1;
		int[] dp = new int[N];
		dp[] = int.min;
		int[] prv = new int[N];
		prv[] = -1;
		
		d[0] = 0;
		q ~= 0;
		dp[0] = 0;
		for (; !q.empty; ) {
			const u = q.front; q.popFront;
			foreach (i; g[u]) {
				const v = A[i] ^ B[i] ^ u;
				if (d[v] == -1) {
					d[v] = d[u] + 1;
					q ~= v;
				}
				if (d[v] == d[u] + 1) {
					if (dp[v] < dp[u] + C[i]) {
						dp[v] = dp[u] + C[i];
						prv[v] = i;
					}
				}
			}
		}
debug{
writeln("d = ",d);
writeln("dp = ",dp);
writeln("prv = ",prv);
}
		
		bool[] used = new bool[M];
		Pair!(int, Pair!(int, int))[] anss;
		for (int u = N - 1; u != 0; ) {
			const i = prv[u];
			used[i] = true;
			if (C[i] == 0) {
				anss ~= pair(1, pair(A[i], B[i]));
			}
			u = A[i] ^ B[i] ^ u;
		}
		foreach (i; 0 .. M) if (!used[i]) {
			if (C[i] == 1) {
				anss ~= pair(0, pair(A[i], B[i]));
			}
		}
		writeln(anss.length);
		foreach (ans; anss) {
			writeln(ans.y.x + 1, " ", ans.y.y + 1, " ", ans.x);
		}
		
	}
	} catch (EOFException) {}
}