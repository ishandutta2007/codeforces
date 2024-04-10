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


immutable V = 4;
immutable LIM_DIST = 10;
immutable LIM_E = 60;
immutable INF = 1_000_000_000_000_000_000;

long[][] mul(long[][] a, long[][] b) {
	long[][] ret = new long[][](V, V);
	foreach (u; 0 .. V) {
		ret[u][] = INF;
	}
	foreach (u; 0 .. V) foreach (w; 0 .. V) foreach (v; 0 .. V) {
		chmin(ret[u][v], a[u][w] + b[w][v]);
	}
	return ret;
}

long N;
string T;

void main(string[] args) {
	try {
	for (; ; ) {
		N = readLong;
		T = readToken;
		
		long[][] D = new long[][](V, V);
		foreach (u; 0 .. V) {
			D[u][] = LIM_DIST;
		}
		foreach (d; 1 .. LIM_DIST) {
			bool[int][][] apps = new bool[int][][](V, V);
			foreach (i; 0 .. T.length) if (i + d < T.length) {
				int enc;
				foreach (j; i + 1 .. i + d) {
					enc = enc * 4 + (T[j] - 'A');
				}
				apps[T[i] - 'A'][T[i + d] - 'A'][enc] = true;
			}
			foreach (u; 0 .. V) foreach (v; 0 .. V) {
				if (apps[u][v].length < 4 ^^ (d - 1)) {
					chmin(D[u][v], cast(long)(d));
				}
			}
		}
debug{
writeln("D = ",D);
}
		
		//	ds[e] = D^(2^e)
		long[][][] ds = new long[][][LIM_E];
		ds[0] = D;
		foreach (e; 1 .. LIM_E) {
			ds[e] = mul(ds[e - 1], ds[e - 1]);
		}
		
		long ans;
		long[][] crt = new long[][](V, V);
		foreach (u; 0 .. V) {
			crt[u][] = INF;
			crt[u][u] = 0;
		}
		foreach_reverse (e; 0 .. LIM_E) {
			long[][] nxt = mul(crt, ds[e]);
			const opt = nxt.map!"a.reduce!min".reduce!min;
			if (opt < N) {
				ans |= 1L << e;
				crt = nxt;
			}
		}
		++ans;
		writeln(ans);
	}
	} catch (EOFException) {}
}