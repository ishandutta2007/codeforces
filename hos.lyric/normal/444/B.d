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


class Generator {
	int n;
	int d;
	long x;
	int[] a, b;
	this(int n, int d, long x) {
		this.n = n;
		this.d = d;
		this.x = x;
		a = new int[n];
		b = new int[n];
	}
	//x is 64-bit variable;
	long getNextX() {
		x = (x * 37 + 10007) % 1000000007;
		return x;
	}
	void initAB() {
		int i;
		for(i = 0; i < n; i = i + 1){
			a[i] = i + 1;
		}
		for(i = 0; i < n; i = i + 1){
			swap(a[i], a[cast(size_t)(getNextX() % (i + 1))]);
		}
		for(i = 0; i < n; i = i + 1){
			if (i < d)
				b[i] = 1;
			else
				b[i] = 0;
		}
		for(i = 0; i < n; i = i + 1){
			swap(b[i], b[cast(size_t)(getNextX() % (i + 1))]);
		}
	}
}

immutable NUM_BIG = 1000;

int N, D;
long X;
int[] A, B;

void main(string[] args) {
	try {
	for (; ; ) {
		N = readInt;
		D = readInt;
		X = readLong;
		auto gen = new Generator(N, D, X);
		gen.initAB;
		A = gen.a;
		B = gen.b;
debug{
writeln("A = ",A);
writeln("B = ",B);
}
		
		int[] js;
		foreach (j; 0 .. N) if (B[j]) {
			js ~= j;
		}
		
		int[] ans = new int[N];
		foreach (i; 0 .. N) if (A[i] >= N - NUM_BIG) {
			foreach (j; js) {
				if (i + j >= N) {
					break;
				}
				chmax(ans[i + j], A[i]);
			}
		}
		
		foreach (k; 0 .. N) if (!ans[k]) {
			foreach (j; js) {
				if (j > k) {
					break;
				}
				chmax(ans[k], A[k - j]);
			}
		}
		
		foreach (k; 0 .. N) {
			writeln(ans[k]);
		}
	}
	} catch (EOFException) {}
}