import core.thread;
import std.conv, std.stdio, std.string;
import std.algorithm, std.array, std.bigint, std.container, std.math, std.range;

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


int N, M, K;
int[] A, B;
long[] C;

void main(string[] args) {
	try {
	for (; ; ) {
		N = readInt;
		M = readInt;
		K = readInt;
		A = new int[M + K];
		B = new int[M + K];
		C = new long[M + K];
		foreach (i; 0 .. M + K) {
			A[i] = (i < M) ? (readInt - 1) : 0;
			B[i] = readInt - 1;
			C[i] = readLong;
		}
		
		auto G = new Pair!(long, int)[][N];
		foreach (i; 0 .. M + K) {
			G[A[i]] ~= pair(C[i], B[i]);
			G[B[i]] ~= pair(C[i], A[i]);
		}
		
		auto q = heapify!"a.x > b.x"(Array!(Pair!(long, int))());
		long[] d = new long[N];
		d[] = long.max;
		d[0] = 0;
		q.insert(Pair!(long, int)(0, 0));
		for (; !q.empty; ) {
			const c = q.front.x;
			const u = q.front.y;
			q.removeFront;
			if (d[u] == c) {
				foreach (edge; G[u]) {
					const cc = c + edge.x;
					const v = edge.y;
					if (d[v] > cc) {
						d[v] = cc;
						q.insert(Pair!(long, int)(cc, v));
					}
				}
			}
		}
// writeln("d = ",d);
		
		bool[] has = new bool[N];
		foreach (i; 0 .. M) {
			if (d[B[i]] == d[A[i]] + C[i]) {
				has[B[i]] = true;
			}
			if (d[A[i]] == d[B[i]] + C[i]) {
				has[A[i]] = true;
			}
		}
		
		int ans;
		foreach (i; M .. M + K) {
			if (d[B[i]] == d[A[i]] + C[i]) {
				if (has[B[i]]) {
					++ans;
				} else {
					has[B[i]] = true;
				}
			} else {
				++ans;
			}
		}
		writeln(ans);
	}
	} catch (EOFException) {}
}