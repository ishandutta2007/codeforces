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
// void chmax(T)(ref T t, in T f) { if (t < f) t = f; }
void chmax(T)(ref T t, T f) { if (t < f) t = f; }

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


int N;
int[] A, B;

int[][] G;

BigInt[] dpP, dp0, dp1;

void solve(int u, int p) {
	foreach (v; G[u]) if (v != p) {
		solve(v, u);
	}
	
	int numChildren;
	foreach (v; G[u]) if (v != p) {
		++numChildren;
	}
	
	dpP[u] = 1;
	foreach (v; G[u]) if (v != p) {
		dpP[u] *= dp0[v];
	}
	
	auto crt = new BigInt[numChildren + 1];
	crt[0] = 1;
	foreach (v; G[u]) if (v != p) {
		auto nxt = new BigInt[numChildren + 1];
		foreach (x; 0 .. numChildren + 1) {
			//	disconnect
			{
				chmax(nxt[x], crt[x] * dp0[v]);
			}
			//	connect
			if (x < numChildren) {
				chmax(nxt[x + 1], crt[x] * dpP[v]);
			}
		}
		crt = nxt;
	}
	
	foreach (x; 0 .. numChildren + 1) {
		chmax(dp0[u], (1 + x) * crt[x]);
	}
	//	connect with one
	foreach (v; G[u]) if (v != p) {
		chmax(dp0[u], dpP[u] / dp0[v] * dp1[v]);
	}
	
	foreach (x; 0 .. numChildren + 1) {
		chmax(dp1[u], (2 + x) * crt[x]);
	}
}

void main(string[] args) {
	try {
	for (; ; ) {
		N = readInt;
		A = new int[N - 1];
		B = new int[N - 1];
		foreach (i; 0 .. N - 1) {
			A[i] = readInt - 1;
			B[i] = readInt - 1;
		}
		
		G = new int[][N];
		foreach (i; 0 .. N - 1) {
			G[A[i]] ~= B[i];
			G[B[i]] ~= A[i];
		}
		
		dpP = new BigInt[N];
		dp0 = new BigInt[N];
		dp1 = new BigInt[N];
		solve(0, -1);
debug{
writeln("dpP = ",dpP);
writeln("dp0 = ",dp0);
writeln("dp1 = ",dp1);
}
		
		writeln(dp0[0]);
		
	}
	} catch (EOFException) {}
}