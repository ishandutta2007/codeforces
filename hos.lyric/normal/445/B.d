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
		uf[] = -1;
		foreach (i; 0 .. M) {
			uf.conn(A[i], B[i]);
		}
		
		long ans = 1;
		foreach (u; 0 .. N) {
			if (!(uf[u] < 0)) {
				ans *= 2;
			}
		}
		writeln(ans);
	}
	} catch (EOFException) {}
}