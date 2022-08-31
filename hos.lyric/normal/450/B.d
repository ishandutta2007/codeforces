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


immutable long MO = 1000000007;

struct Mint {
	long v;
	this(long v = 0) {
		if ((this.v = v % MO) < 0) this.v += MO;
	}
	Mint opUnary(string op)() {
		static if (op == "-" || op == "+") {
			return mixin(op ~ "v");
		} else static if (op == "++" || op == "--") {
			return this = mixin(op ~ "v");
		}
	}
	Mint opBinary(string op)(const Mint a) const {
		static if (op == "+" || op == "-" || op == "*") {
			return Mint(mixin("v" ~ op ~ "a.v"));
		} else static if (op == "/") {
			assert(a.v != 0);
			return this * a ^^ (MO - 2);
		}
	}
	Mint opBinary(string op)(long a) const {
		static if (op == "^^") {
			Mint ret = 1, x = this;
			for (; a; a >>= 1, x *= x) if (a & 1) ret *= x;
			return ret;
		} else {
			return mixin("this" ~ op ~ "Mint(a)");
		}
	}
	Mint opAssign(long v) {
		return this = Mint(v);
	}
	Mint opOpAssign(string op)(const Mint a) {
		static if (op == "+" || op == "-" || op == "*" || op == "/") {
			return this = mixin("this" ~ op ~ "a");
		}
	}
	Mint opOpAssign(string op)(long a) {
		return this = mixin("this" ~ op ~ "a");
	}
	string toString() const {
		return v.to!string;
	}
	unittest {
		Mint a = -1;
		assert(a.v == MO - 1);
		++a;
		assert(a.v == 0);
		--a;
		assert(a.v == MO - 1);
		Mint b = 1_000_000_000;
		b += 1_000_000_000;
		assert(b.v == 2_000_000_000 % MO);
		b = 2;
		b -= 4;
		assert(b.v == MO - 2);
		b = 1_000_000_000;
		b *= 1_000_000_000;
		assert(b.v == 1_000_000_000_000_000_000 % MO);
		Mint c = -10;
		c /= 14;
		c *= 7;
		assert(c.v == MO - 5);
	}
}

//	mod (q^2 - q + 1)
Mint[] mul(Mint[] a, Mint[] b) {
	const x = a[0] * b[0];
	const y = a[1] * b[1];
	const z = (a[0] + a[1]) * (b[0] + b[1]);
	return [ x - y, z - x ];
}

long X, Y, N;

void main(string[] args) {
	try {
	for (; ; ) {
		X = readLong;
		Y = readLong;
		N = readLong;
		
		auto x = [ Mint(0), Mint(1) ];
		auto y = [ Mint(1), Mint(0) ];
		for (long e = N - 1; e; e >>= 1, x = mul(x, x)) if (e & 1) {
			y = mul(y, x);
		}
		
		Mint ans;
		ans += y[0] * X;
		ans += y[1] * Y;
		writeln(ans);
		
	}
	} catch (EOFException) {}
}