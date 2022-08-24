import core.thread;
import std.conv, std.stdio, std.string;
import std.algorithm, std.array, std.bigint, std.container, std.math, std.range, std.regex;

//	Input
class EOFException : Throwable { this() { super("EOF"); } }
string[] tokens;
string readToken() { for (; tokens.empty; ) { if (stdin.eof) throw new EOFException; tokens = readln.split; } auto token = tokens[0]; tokens.popFront; return token; }
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


immutable long MO = 10^^9 + 7;
immutable LIM = 2 * 10^^5 + 5;

long[] inv, fac, facInv;

void prepare() {
	inv = new long[LIM];
	inv[1] = 1;
	foreach (i; 2 .. LIM) {
		inv[i] = MO - MO / i * inv[cast(size_t)(MO % i)] % MO;
	}
	fac = new long[LIM];
	facInv = new long[LIM];
	fac[0] = 1;
	facInv[0] = 1;
	foreach (i; 1 .. LIM) {
		fac[i] = fac[i - 1] * i % MO;
		facInv[i] = facInv[i - 1] * inv[i] % MO;
	}
}

long binom(int n, int k) {
	if (!(0 <= k && k <= n)) {
		return 0;
	}
	return fac[n] * facInv[k] % MO * facInv[n - k] % MO;
}

int N, K;
string S;

void main(string[] args) {
	prepare;
	
	try {
	for (; ; ) {
		N = readInt;
		K = readInt;
		S = readToken;
		
debug{
long brt;
foreach(h;0..1<<(N-1)){
 int cnt;
 foreach(i;0..N-1)if(h&1<<i)++cnt;
 if(cnt!=K)continue;
 long x;
 foreach(i;0..N){
  x=(x*10+S[i]-'0')%MO;
  // writeln(h," ",x);
  if((h&1<<i)||i==N-1){(brt+=x)%=MO;x=0;}
 }
}
writeln("brt = ",brt);
}
		
		long ans;
		long sum = 0;
		long ten = 1;
		foreach_reverse (i; 0 .. N) {
debug{
// writeln("sum = ",sum,", binom(i, K) * ten = ",binom(i, K) * ten);
}
			(ans += ((sum + binom(i, K) * ten) % MO) * (S[i] - '0')) %= MO;
			(sum += binom(i - 1, K - 1) * ten) %= MO;
			(ten *= 10) %= MO;
		}
		ans = (ans % MO + MO) % MO;
		writeln(ans);
		
	}
	} catch (EOFException) {}
}