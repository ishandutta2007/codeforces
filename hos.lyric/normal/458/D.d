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


real[] logFac;
real[][] bn;

int N, M, K;

void main(string[] args) {
	logFac = new real[200005];
	logFac[0] = 0.0;
	foreach (i; 1 .. logFac.length) {
		logFac[i] = logFac[i - 1] + log(cast(real)(i));
	}
	bn = new real[][](605, 605);
	foreach (i; 0 .. bn.length) {
		bn[i][0] = bn[i][i] = 1.0;
		foreach (j; 1 .. i) {
			bn[i][j] = bn[i - 1][j - 1] + bn[i - 1][j];
		}
	}
	
	try {
	for (; ; ) {
		N = readInt;
		M = readInt;
		K = readInt;
		
		real[][] ps = new real[][](N + 1, N + 1);
		foreach (x; 0 .. N + 1) foreach (y; 0 .. N + 1) {
			const need = N * N - (N - x) * (N - y);
			if (K >= need) {
				//	C(M - need, K - need) / C(M, K)
				ps[x][y] = exp(logFac[M - need] - logFac[K - need] - logFac[M] + logFac[K]);
			} else {
				ps[x][y] = 0.0;
			}
		}
debug{
writeln("ps = ",ps);
}
		
		/*
		foreach_reverse (x; 0 .. N + 1) foreach (xx; x + 1 .. N + 1) {
			foreach (y; 0 .. N + 1) {
				ps[x][y] -= bn[N - x][N - xx] * ps[xx][y];
			}
		}
		foreach_reverse (y; 0 .. N + 1) foreach (yy; y + 1 .. N + 1) {
			foreach (x; 0 .. N + 1) {
				ps[x][y] -= bn[N - y][N - yy] * ps[x][yy];
			}
		}
debug{
writeln("ps = ",ps);
}
		*/
		real[] qs = new real[N * 2 + 1];
		qs[] = 0.0;
		foreach (x; 0 .. N + 1) foreach (y; 0 .. N + 1) {
			qs[x + y] += bn[N][x] * bn[N][y] * ps[x][y];
		}
debug{
writeln("qs = ",qs);
}
		real ans = 0.0;
		real val = 1.0;
		foreach (z; 0 .. N * 2 + 1) {
			ans += qs[z] * val;
			// val *= 2.0;
		}
		if (ans > 1e99) {
			writeln("1e99");
		} else {
			writefln("%.10f", ans);
		}
	}
	} catch (EOFException) {}
}