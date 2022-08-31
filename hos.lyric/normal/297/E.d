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


void bitAdd(long[] bit, int pos, long val) {
	for (int x = pos; x < bit.length; x |= x + 1) {
		bit[x] += val;
	}
}
long bitSum(long[] bit, int pos) {
	long ret;
	for (int x = pos - 1; x >= 0; x = (x & (x + 1)) - 1) {
		ret += bit[x];
	}
	return ret;
}

int N;
int[] A, B;

void main(string[] args) {
	try {
	for (; ; ) {
		N = readInt;
		A = new int[N];
		B = new int[N];
		foreach (i; 0 .. N) {
			A[i] = readInt - 1;
			B[i] = readInt - 1;
		}
		
		int[] fr = new int[N * 2 * 2];
		foreach (i; 0 .. N) {
			fr[A[i]] = B[i];
			fr[B[i]] = A[i];
		}
		foreach (x; 0 .. N * 2) {
			for (; fr[x] > x; ) {
				fr[x] -= N * 2;
			}
		}
		foreach (x; N * 2 .. N * 2 * 2) {
			fr[x] = fr[x - N * 2] + N * 2;
		}
debug{
writeln("fr = ",fr);
}
		
		long[] ss = new long[N * 2];
		long total;
		long[] bit = new long[N * 2 * 2];
		foreach (x; 0 .. N * 2 * 2) {
			if (0 <= fr[x] && fr[x] < N * 2) {
				ss[fr[x]] = total - bit.bitSum(fr[x]);
			}
			if (0 <= fr[x]) {
				++total;
				bit.bitAdd(fr[x], +1);
			}
		}
debug{
writeln("ss = ",ss);
}
		const long n = N;
		long f0, f1, f2, f3;
		foreach (i; 0 .. N) {
			const sA = ss[A[i]];
			const sB = ss[B[i]];
			const t = n - 1 - sA - sB;
debug{
writeln(sA," ",sB," ",t);
}
			f0 += sA * sB;
			f1 += sA * (sA - 1) / 2 + sB * (sB - 1) / 2;
			f2 += (sA + sB) * t;
			f3 += t * (t - 1) / 2;
		}
debug{
writeln("f = ",f0," ",f1," ",f2," ",f3);
}
		
		/*
			f0 = a
			f1 = 2 a + 3 b + c
			f2 = 2 c + 2 d
			f3 = d + 3 e
		*/
assert(f0+f1+f2+f3==n*(n-1)*(n-2)/6*3);
		assert(f2 % 2 == 0);
		long ans = f1 - f0 * 2 + f3 - f2 / 2;
		assert(ans % 3 == 0);
		ans /= 3;
		writeln(ans);
	}
	} catch (EOFException) {}
}