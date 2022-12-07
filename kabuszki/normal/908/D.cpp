
//Karol Kaszuba

#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef vector<int> VI;
typedef pair<int, int> PII;
typedef double D;
typedef long double LD;
typedef vector<PII> VII;
typedef unordered_set<int> USI;
typedef unordered_set<LL> USLL;

#define FOR(i,x,y) for(auto i=(x);i<=(y);++i)
#define REP(i,x) FOR(i,0,(x)-1)
#define FORD(i,x,y) for(auto i=(x);i>=(y);--i)
#define VAR(i,c) __typeof(c) i=(c)
#define FORE(i,c) for(VAR(i,(c).begin());i!=(c).end();++i)
#define SIZE(c) (int)((c).size())
#define ALL(c) (c).begin(),(c).end()
#define PB push_back
#define EB emplace_back
#define IN insert
#define ER erase
#define MP make_pair
#define ST first
#define ND second
#define IOSYNC ios_base::sync_with_stdio(0)
#define FREOPEN(f) freopen(f, "r", stdin),freopen(f, "w", stdout)

const LL MOD = 1000000007;

LL qpot(LL a, LL b, LL m) {
	LL res = 1;
	while (b) {
		if (b % 2) res = (res * a) % m;
		a = (a * a) % m;
		b /= 2;
	}
	return res;
}

LL P[2003][2003];

void jebaj() {
	LL k, a, b;
	cin >> k >> a >> b;
	
	LL c = (a + b);
	c = qpot(c, MOD - 2, MOD);
	LL d = b;
	d = qpot(d, MOD - 2, MOD);
	
	P[1][0] = 1;
	FOR(l, 1, k) FOR(res, 0, k - 1) {
		P[l + 1][res] += (P[l][res] * a) % MOD * c;
		P[l + 1][res] %= MOD;
		
		P[l][res + l] += (P[l][res] * b) % MOD * c;
		P[l][res + l] %= MOD;
	}
	
	LL total = 0;
	LL q = 0;
	
	FOR(l, 1, k) FOR(res, 0, k - 1) {
		if (res + l == k) {
			
			LL p = P[l][res];
			
			q = (q + p) % MOD;
			
			LL dis = (p * k) % MOD;
			dis = (dis + (p * (a + b)) % MOD * d) % MOD;
			dis = (dis - p + MOD) % MOD;
			total += dis;
			total %= MOD;
		}
		if (res + l > k && res >= l) {
			
			LL p = ((P[l][res - l] * b) % MOD * c ) % MOD;
			
			q = (q + p) % MOD;
			
			LL dis = (p * (res + l)) % MOD;
			dis = (dis + (p * (a + b)) % MOD * d) % MOD;
			dis = (dis - p + MOD) % MOD;
			total += dis;
			total %= MOD;
		}
	}
	
	total = (total * qpot(q, MOD - 2, MOD)) % MOD;
	
	cout << total << "\n";
}

int main() {
	IOSYNC;
	int t;
	t = 1;
	while(t--) jebaj();
	return 0;
}