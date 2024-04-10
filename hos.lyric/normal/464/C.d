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


immutable long MO = 1000000007;
immutable L = 10;

string S;
int N;
string[] A;

void main(string[] args) {
	try {
	for (; ; ) {
		S = readToken;
		N = readInt;
		A = new string[N];
		foreach (i; 0 .. N) {
			A[i] = readToken;
		}
		
		long[][] vals = new long[][](N + 1, L);
		long[][] muls = new long[][](N + 1, L);
		foreach (x; 0 .. L) {
			vals[N][x] = x;
			muls[N][x] = L;
		}
		
		foreach_reverse (i; 0 .. N) {
			foreach (x; 0 .. L) {
				if (x == A[i][0] - '0') {
					vals[i][x] = 0;
					muls[i][x] = 1;
					foreach (c; A[i][3 .. $]) {
						const int y = c - '0';
						vals[i][x] = (vals[i][x] * muls[i + 1][y] + vals[i + 1][y]) % MO;
						muls[i][x] = (muls[i][x] * muls[i + 1][y]) % MO;
					}
				} else {
					vals[i][x] = vals[i + 1][x];
					muls[i][x] = muls[i + 1][x];
				}
			}
		}
		
		long ans;
		foreach (c; S) {
			const int y = c - '0';
			ans = (ans * muls[0][y] + vals[0][y]) % MO;
		}
		writeln(ans);
	}
	} catch (EOFException) {}
}