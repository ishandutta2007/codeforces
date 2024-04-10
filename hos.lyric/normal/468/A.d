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


void add(int a, int b) { writefln("%d + %d = %d", a, b, a + b); }
void sub(int a, int b) { writefln("%d - %d = %d", a, b, a - b); }
void mul(int a, int b) { writefln("%d * %d = %d", a, b, a * b); }

int N;

void main(string[] args) {
	try {
	for (; ; ) {
		N = readInt;
		
		if (N <= 3) {
			writeln("NO");
		} else {
			writeln("YES");
			if (N == 5) {
				mul(5, 4);
				add(20, 3);
				add(23, 2);
				sub(25, 1);
			} else if (N % 2 == 0) {
				mul(4, 3);
				mul(12, 2);
				for (int i = N; i >= 6; i -= 2) {
					sub(i, i - 1);
				}
				foreach (_; 0 .. 1 + (N - 4) / 2) {
					mul(24, 1);
				}
			} else {
				mul(6, 4);
				sub(7, 5);
				sub(2, 1);
				sub(3, 2);
				for (int i = N; i >= 9; i -= 2) {
					sub(i, i - 1);
				}
				foreach (_; 0 .. 2 + (N - 7) / 2) {
					mul(24, 1);
				}
			}
		}
	}
	} catch (EOFException) {}
}