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


immutable EPS = 1e-10;
immutable INF = 1e+10;
int sig(in real r) { return (r < -EPS) ? -1 : (r > +EPS) ? +1 : 0; }
real arg(in creal a) { return atan2(a.im, a.re); }
real dot(in creal a, in creal b) { return a.re * b.re + a.im * b.im; }
real det(in creal a, in creal b) { return a.re * b.im - a.im * b.re; }
real tri(in creal a, in creal b, in creal c) { return (b - a).det(c - a); }

creal circumcenter(in creal a, in creal b, in creal c) {
	const bc = c - b, ca = a - c, ab = b - a;
	return (b + c - bc * 1i * ca.dot(ab) / ca.det(ab)) / 2.0;
}


creal[] check(creal p, creal q, creal r) {
// writeln("check ",p," ",q," ",r);
	creal s = q * 2.0 - r;
	if (sig(tri(p, q, s)) == 0) {
		return null;
	}
	creal[] as = new creal[4];
	as[1] = circumcenter(p, q, s);
	as[0] = p * 2.0 - as[1];
	as[2] = q * 2.0 - as[1];
	as[3] = r * 2.0 - as[2];
// writeln("  as = ",as);
	foreach (i; 0 .. 4) {
		if (sig(abs(as[(i + 1) % 4] - as[i])) == 0) {
			return null;
		}
	}
	real area = 0.0;
	foreach (i; 0 .. 4) {
		area += as[i].det(as[(i + 1) % 4]);
	}
	if (area < 0) {
		as[1 .. $].reverse;
	}
// writeln("  as = ",as);
	foreach (i; 0 .. 4) {
		if (sig((as[(i + 2) % 4] - as[(i + 1) % 4]).det(as[i] - as[(i + 1) % 4])) <= 0) {
			return null;
		}
	}
// writeln("  as = ",as);
	return as;
}

creal[] P;

creal[] solve() {
// writeln(P);
	if (auto res = check(P[1], P[0], P[2])) return res;
	if (auto res = check(P[0], P[1], P[2])) return res;
	if (auto res = check(P[0], P[2], P[1])) return res;
	return null;
}

void main(string[] args) {
	// try {
	for (int TC = readInt; TC--; ) {
		P = new creal[3];
		foreach (i; 0 .. 3) {
			const x = readReal;
			const y = readReal;
			P[i] = x + y * 1i;
		}
		
		const res = solve;
		if (res) {
			writeln("YES");
			foreach (i; 0 .. 4) {
				if (i > 0) {
					write(" ");
				}
				writef("%.9f %.9f", res[i].re, res[i].im);
			}
			writeln;
		} else {
			writeln("NO");
			writeln;
		}
	}
	// } catch (EOFException) {}
}