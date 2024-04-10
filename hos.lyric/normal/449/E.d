import core.thread;
import std.conv, std.stdio, std.string;
import std.algorithm, std.array, std.bigint, std.math, std.range;

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

long gcd(long a, long b) {
	return (b != 0) ? gcd(b, a % b) : a;
}

immutable LIM = 1000005;

/*
long[] phi;
long gcdSum(long n) {
	long ret;
	for (long d = 1; d * d <= n; ++d) if (n % d == 0) {
		ret += d * phi[cast(size_t)(n / d)];
		if (d != n / d) {
			ret += (n / d) * phi[cast(size_t)(d)];
		}
	}
	return ret;
}
*/

void main(string[] args) {
	long[] phi = new long[LIM];
	foreach (i; 1 .. LIM) phi[i] = i;
	foreach (i; 1 .. LIM) for (int j = i * 2; j < LIM; j += i) phi[j] -= phi[i];
// writeln("phi = ",phi[0..30]);
	long[] gcdSums = new long[LIM];
	foreach (i; 1 .. LIM) for (int j = i; j < LIM; j += i) {
		gcdSums[j] += i * phi[j / i];
	}
	
	Mint[] k1 = new Mint[LIM + 1];
	Mint[] k2 = new Mint[LIM + 1];
	Mint[] k3 = new Mint[LIM + 1];
	Mint[] k4 = new Mint[LIM + 1];
	foreach (k; 0 .. LIM) {
		k1[k + 1] = k1[k] + Mint(k) ^^ 1;
		k2[k + 1] = k2[k] + Mint(k) ^^ 2;
		k3[k + 1] = k3[k] + Mint(k) ^^ 3;
		k4[k + 1] = k4[k] + Mint(k) ^^ 4;
	}
// writeln("k1 = ",k1[0..10]);
// writeln("k2 = ",k2[0..10]);
// writeln("k3 = ",k3[0..10]);
// writeln("k4 = ",k4[0..10]);
	Mint[] k0a = new Mint[LIM + 1];
	Mint[] k1a = new Mint[LIM + 1];
	Mint[] k2a = new Mint[LIM + 1];
	foreach (k; 0 .. LIM) {
		k0a[k + 1] = k0a[k] + Mint(k) ^^ 0 * k2[k];
		k1a[k + 1] = k1a[k] + Mint(k) ^^ 1 * k2[k];
		k2a[k + 1] = k2a[k] + Mint(k) ^^ 2 * k2[k];
	}
// writeln("k0a = ",k0a[0..10]);
// writeln("k1a = ",k1a[0..10]);
// writeln("k2a = ",k2a[0..10]);
	Mint[] k0g = new Mint[LIM + 1];
	Mint[] k1g = new Mint[LIM + 1];
	Mint[] k2g = new Mint[LIM + 1];
	foreach (k; 0 .. LIM) {
		// const g = gcdSum(k);
// if(k<10)writeln("gcdSum(",k,") = ",g);
		const g = gcdSums[k] - k;
		k0g[k + 1] = k0g[k] + Mint(k) ^^ 0 * g;
		k1g[k + 1] = k1g[k] + Mint(k) ^^ 1 * g;
		k2g[k + 1] = k2g[k] + Mint(k) ^^ 2 * g;
	}
// writeln("k0g = ",k0g[0..10]);
// writeln("k1g = ",k1g[0..10]);
// writeln("k2g = ",k2g[0..10]);
	
	// try {
	for (int TC = readInt; TC--; ) {
		const M = readLong;
		const N = readLong;
		
		const L = min(M, N);
		
		/*
		long brt;
		foreach (k; 1 .. L + 1) {
			brt += (M - k + 1) * (N - k + 1) * k ^^ 2;
		}
		foreach (a; 1 .. L) foreach (b; 1 .. L) if (a + b <= L) {
			brt += (M - (a + b) + 1) * (N - (a + b) + 1) * (a ^^ 2 + b ^^ 2 - 2 * (a + b - gcd(a, b)));
		}
		writeln("brt = ", brt);
		//*/
		
		const m = Mint(M);
		const n = Mint(N);
		const l = cast(size_t)(L);
		Mint ans;
		
		ans += (m + 1) * (n + 1) * k2[l + 1];
		ans -= (m + 1) * k3[l + 1];
		ans -= (n + 1) * k3[l + 1];
		ans += k4[l + 1];
		
		ans += (m + 1) * (n + 1) * 2 * k0a[l + 1];
		ans -= (m + 1) * 2 * k1a[l + 1];
		ans -= (n + 1) * 2 * k1a[l + 1];
		ans += Mint(1) * 2 * k2a[l + 1];
		
		ans -= (m + 1) * (n + 1) * 2 * (k2[l + 1] - k1[l + 1]);
		ans += (m + 1) * 2 * (k3[l + 1] - k2[l + 1]);
		ans += (n + 1) * 2 * (k3[l + 1] - k2[l + 1]);
		ans -= Mint(1) * 2 * (k4[l + 1] - k3[l + 1]);
		
		ans += (m + 1) * (n + 1) * 2 * k0g[l + 1];
		ans -= (m + 1) * 2 * k1g[l + 1];
		ans -= (n + 1) * 2 * k1g[l + 1];
		ans += Mint(1) * 2 * k2g[l + 1];
		
		writeln(ans);
		
	}
	// } catch (EOFException) {}
}