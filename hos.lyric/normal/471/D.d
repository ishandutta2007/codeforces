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


int M, N;
int[] A, B;
int[] P, Q;

void main(string[] args) {
	try {
	for (; ; ) {
		M = readInt;
		N = readInt;
		A = new int[M];
		foreach (i; 0 .. M) {
			A[i] = readInt;
		}
		B = new int[N];
		foreach (i; 0 .. N) {
			B[i] = readInt;
		}
		
		if (N == 1) {
			writeln(M);
		} else {
			P = new int[M - 1];
			foreach (i; 0 .. M - 1) {
				P[i] = A[i + 1] - A[i];
			}
			Q = new int[N - 1];
			foreach (i; 0 .. N - 1) {
				Q[i] = B[i + 1] - B[i];
			}
debug{
writeln("P = ",P);
writeln("Q = ",Q);
}
			int[] fail = new int[Q.length + 1];
			int j = fail[0] = -1;
			foreach (i; 0 .. Q.length) {
				for (; j >= 0 && Q[j] != Q[i]; j = fail[j]) {}
				fail[i + 1] = ++j;
			}
debug{
writeln("fail = ",fail);
}
			int ans;
			j = 0;
			foreach (i; 0 .. P.length) {
				for (; j >= 0 && Q[j] != P[i]; j = fail[j]) {}
				if (++j == Q.length) {
					++ans;
					j = fail[j];
				}
			}
			writeln(ans);
		}
	}
	} catch (EOFException) {}
}