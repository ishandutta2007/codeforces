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


immutable long MO = 1000000009;
immutable long SQRT5 = 383008016;
immutable long[] G = [ (1 + SQRT5 + MO) / 2, (1 - SQRT5 + MO) / 2 ];
immutable long[] H = [ MO - G[1], MO - G[0] ];

immutable LIM = 300005;
long[][] GG, HH;
long[][] GGSum;

int N, M;
long[] A;

long[][] adds;
long[][] sums;

long query(int s, int u, int L, int R, int a, int b, long val) {
// writeln("query ",s," ",u," ",L," ",R," ",a," ",b," ",val);
	chmax(a, L);
	chmin(b, R);
	if (a == L && b == R) {
		(adds[s][u] += val) %= MO;
	}
	if (adds[s][u] != 0) {
		if (R - L > 1) {
			(adds[s][u << 1 | 0] += adds[s][u]) %= MO;
			(adds[s][u << 1 | 1] += adds[s][u]) %= MO;
		}
		(sums[s][u] += GGSum[s][R - L] * adds[s][u]) %= MO;
		adds[s][u] = 0;
	}
	if (a >= b) {
		return 0;
	}
	if (a == L && b == R) {
		return sums[s][u];
	}
	const Mid = (L + R) / 2;
	const resL = query(s, u << 1 | 0, L, Mid, a, b, val);
	const resR = query(s, u << 1 | 1, Mid, R, a, b, val);
	sums[s][u] = (sums[s][u << 1 | 0] + GG[s][Mid - L] * sums[s][u << 1 | 1]) % MO;
	return (resL + GG[s][Mid - L] * resR) % MO;
}

void main(string[] args) {
	/*
	foreach (s; 0 .. MO) {
		if ((s * s) % MO == 5) {
			writeln(s);
			break;
		}
	}
	*/
	assert((SQRT5 * SQRT5) % MO == 5);
	assert((G[0] + G[1]) % MO == 1);
	assert((G[0] * G[1]) % MO == MO - 1);
	assert((G[0] * H[0]) % MO == 1);
	assert((G[1] * H[1]) % MO == 1);
	
	long SQRT5INV = 1;
	{
		long x = SQRT5;
		for (long e = MO - 2; e; e >>= 1, (x *= x) %= MO) if (e & 1) {
			(SQRT5INV *= x) %= MO;
		}
	}
	assert((SQRT5 * SQRT5INV) % MO == 1);
	
	GG = new long[][](2, LIM);
	HH = new long[][](2, LIM);
	foreach (s; 0 .. 2) {
		GG[s][0] = 1;
		HH[s][0] = 1;
		foreach (i; 1 .. LIM) {
			GG[s][i] = (GG[s][i - 1] * G[s]) % MO;
			HH[s][i] = (HH[s][i - 1] * H[s]) % MO;
		}
		assert((GG[s][$ - 1] * HH[s][$ - 1]) % MO == 1);
	}
	
	GGSum = new long[][](2, LIM + 1);
	foreach (s; 0 .. 2) {
		foreach (i; 0 .. LIM) {
			GGSum[s][i + 1] = (GGSum[s][i] + GG[s][i]) % MO;
		}
// writeln(GGSum[s][0..10]);
	}
	
	try {
	for (; ; ) {
		N = readInt;
		M = readInt;
		A = new long[N];
		foreach (i; 0 .. N) {
			A[i] = readLong;
		}
		
		adds = new long[][](2, N * 4);
		sums = new long[][](2, N * 4);
		foreach (i; 0 .. N) {
			query(0, 1, 0, N, i, i + 1, (((SQRT5 * HH[0][i]) % MO) * A[i]) % MO);
		}
		
		for (; M--; ) {
// foreach(a;0..N+1)foreach(b;0..N+1)if(a<b)writeln(a," ",b," : ",(SQRT5INV*(query(0,1,0,N,a,b,0)-query(1,1,0,N,a,b,0))%MO+MO)%MO);writeln;
			switch (readInt) {
				case 1: {
					const a = readInt - 1;
					const b = readInt;
					foreach (s; 0 .. 2) {
						query(s, 1, 0, N, a, b, (G[s] * HH[s][a]) % MO);
					}
				} break;
				case 2: {
					const a = readInt - 1;
					const b = readInt;
					long[] res = new long[2];
					foreach (s; 0 .. 2) {
						res[s] = query(s, 1, 0, N, a, b, 0);
					}
					long ans = (SQRT5INV * (res[0] - res[1])) % MO;
					ans = (ans % MO + MO) % MO;
					writeln(ans);
				} break;
				default: assert(false);
			}
		}
	}
	} catch (EOFException) {}
}