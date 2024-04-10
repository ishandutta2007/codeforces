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


int root(int[] p, int[] q, int u) {
	if (p[u] < 0) {
		return u;
	} else {
		int r = root(p, q, p[u]);
		// q[u] += q[p[u]];
		q[u] ^= q[p[u]];
		return (p[u] = r);
	}
}
int conn(int[] p, int[] q, int u, int v, int c) {
debug{
writeln("  conn ",u," ",v," ",c);
}
	int ru = root(p, q, u), rv = root(p, q, v);
	// c -= q[v] - q[u];
	c ^= q[v] ^ q[u];
	if (ru == rv) return (c != 0) ? -1 : 0;
	// if (p[ru] > p[rv]) { swap(ru, rv); c *= -1; }
	if (p[ru] > p[rv]) { swap(ru, rv); }
	p[ru] += p[rv]; p[rv] = ru; q[rv] = c;
	return 1;
}

immutable MO = 1000000007L;

int N, K;
int[] X, Y;
string[] C;

long solve() {
	long ret = 1;
	foreach (s; 0 .. 2) {
		if (N == 1 && s == 1) {
			continue;
		}
		const l = (N - 1 - s) / 2 + 1;
debug{
writeln(N," ",s," ",l);
}
		int[] p = new int[l + 1];
		int[] q = new int[l + 1];
		p[] = -1;
		foreach (k; 0 .. K) if ((X[k] + Y[k]) % 2 == s) {
			const a = abs(X[k] - Y[k]);
			const b = abs(X[k] + Y[k] - (N + 1));
			const u = (a - s) / 2;
			const v = ((N - 1 - s) - b) / 2;
			assert(u <= v);
debug{
writeln(" ",u," ",v," ",C[k]);
}
			const res = conn(p, q, u, v + 1, (C[k] == "o") ? 1 : 0);
			if (res == -1) {
				return 0;
			}
		}
		int cnt = p.count!"a < 0";
		foreach (_; 0 .. cnt - 1) {
			(ret *= 2) %= MO;
		}
	}
	return ret;
}

void main(string[] args) {
	try {
	for (; ; ) {
		N = readInt;
		K = readInt;
		X = new int[K];
		Y = new int[K];
		C = new string[K];
		foreach (k; 0 .. K) {
			X[k] = readInt;
			Y[k] = readInt;
			C[k] = readToken;
		}
		const res = solve;
		writeln(res);
	}
	} catch (EOFException) {}
}