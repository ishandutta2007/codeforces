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


int M, N, S, E;
int[] A, B;

void main(string[] args) {
	try {
	for (; ; ) {
		M = readInt;
		N = readInt;
		S = readInt;
		E = readInt;
		A = new int[M];
		foreach (i; 0 .. M) {
// if(M==100_000){A[i]=1;continue;}
			A[i] = readInt;
		}
		B = new int[N];
		foreach (j; 0 .. N) {
// if(N==100_000){B[j]=1;continue;}
			B[j] = readInt;
		}
		
		int[][int] posB;
		foreach (j; 0 .. N) {
			posB[B[j]] ~= j;
		}
// writeln(posB);
		
		int ans;
		
		const L = S / E;
		int[] dp = new int[L + 1];
		dp[] = N + 1;
		dp[0] = 0;
		foreach (i; 0 .. M + 1) {
			foreach (l; 0 .. L + 1) if (dp[l] <= N) {
				if (i + dp[l] <= S - E * l) {
					chmax(ans, l);
				}
			}
			if (i == M) {
				break;
			}
			if (A[i] in posB) {
				int[] poss = posB[A[i]];
				foreach_reverse (l; 0 .. L) if (dp[l] <= N) {
					const idx = poss.lowerBound(dp[l]);
					if (idx < poss.length) {
						chmin(dp[l + 1], poss[idx] + 1);
					}
					poss = poss[0 .. idx];
				}
			}
		}
		
		writeln(ans);
		
	}
	} catch (EOFException) {}
}