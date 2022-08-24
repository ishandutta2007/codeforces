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


int M, N, K;
int[][] A;

void main(string[] args) {
	try {
	for (; ; ) {
		M = readInt;
		N = readInt;
		K = readInt;
		A = new int[][](M, N);
		foreach (x; 0 .. M) foreach (y; 0 .. N) {
			A[x][y] = readInt;
		}
		
		int ans = int.max;
		
		if (M > K) {
			foreach (sx; 0 .. M) {
				int sum;
				foreach (x; 0 .. M) {
					int cnt;
					foreach (y; 0 .. N) {
						if (A[sx][y] != A[x][y]) {
							++cnt;
						}
					}
					sum += min(cnt, N - cnt);
				}
				chmin(ans, sum);
			}
		}
		
		if (N > K) {
			foreach (sy; 0 .. N) {
				int sum;
				foreach (y; 0 .. N) {
					int cnt;
					foreach (x; 0 .. M) {
						if (A[x][sy] != A[x][y]) {
							++cnt;
						}
					}
					sum += min(cnt, M - cnt);
				}
				chmin(ans, sum);
			}
		}
		
		if (M <= K && N <= K) {
			foreach (p; 0 .. 1 << M) foreach (q; 0 .. 1 << N) {
				int cnt;
				foreach (x; 0 .. M) foreach (y; 0 .. N) {
					if (A[x][y] != (((p >> x) & 1) ^ ((q >> y) & 1))) {
						++cnt;
					}
				}
				chmin(ans, cnt);
			}
		}
		
// writeln("ans = ",ans);
		if (ans > K) {
			writeln(-1);
		} else {
			writeln(ans);
		}
		
	}
	} catch (EOFException) {}
}