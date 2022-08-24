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


bool isPrime(long n) {
	if (n < 2) {
		return false;
	}
	for (long d = 2; d * d <= n; ++d) {
		if (n % d == 0) {
			return false;
		}
	}
	return true;
}

long[] gs;

bool isPrimitive(long p, long g) {
	gs = new long[0];
	gs ~= 1;
	foreach (i; 1 .. p - 1) {
		gs ~= (gs[$ - 1] * g) % p;
	}
	foreach (i; 1 .. p - 1) {
		if (gs[cast(size_t)(i)] == 1) {
			return false;
		}
	}
	return true;
}

long N;

void main(string[] args) {
	try {
	for (; ; ) {
		N = readLong;
		
		if (N == 1) {
			writeln("YES");
			writeln(1);
		} else if (N == 2) {
			writeln("YES");
			writeln(1);
			writeln(2);
		} else if (N == 4) {
			writeln("YES");
			writeln(1);
			writeln(3);
			writeln(2);
			writeln(4);
		} else if (isPrime(N)) {
			for (long g = 2; ; ++g) {
				if (isPrimitive(N, g)) {
debug{
writeln("gs = ",gs);
}
					writeln("YES");
					writeln(1);
					foreach (i; 0 .. (N - 3) / 2) {
debug{
// writeln("g^",1+2*i);
// writeln("g^",N-3-2*i);
}
						writeln(gs[cast(size_t)(1 + 2 * i)]);
						writeln(gs[cast(size_t)(N - 3 - 2 * i)]);
					}
debug{
// writeln("g^",N-2);
}
					writeln(gs[cast(size_t)(N - 2)]);
					writeln(N);
					break;
				}
			}
		} else {
			writeln("NO");
		}
	}
	} catch (EOFException) {}
}