
//Karol Kaszuba

#include <bits/stdc++.h>

using namespace std;
#define int long long

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

const int MOD = 1000000009;

int qpot(int a, int b) {
	int res = 1;
	while (b) {
		if (b % 2) res = (res * a) % MOD;
		a = (a * a) % MOD;
		b /= 2;
	}
	return res;
}

int licz(int n, int a, int b, int k, int i) {
	int res = qpot(b, i) * qpot(a, MOD - 1 - i - 1);
	res %= MOD;
	int A = qpot(a, k);
	int B = qpot(b, k);
	
	n = (n + 1) / k;
	
	if (A == B) {
		int ple = qpot(A, n);
		ple = (ple * n) % MOD;
		return (ple * res) % MOD;
	}
	
	int ple = qpot(A, n + 1) - qpot(B, n + 1) + MOD;
	ple %= MOD;
	ple *= qpot((A - B + MOD) % MOD, MOD - 2);
	ple %= MOD;
	ple -= qpot(B, n);
	ple += MOD;
	ple %= MOD;
	return (ple * res) % MOD;
}

void jebaj() {
	int n, a, b, k;
	cin >> n >> a >> b >> k;
	string s;
	cin >> s;
	int res = 0;
	REP(i, k) {
		res += licz(n, a, b, k, i) * (s[i] == '+' ? 1 : -1);
		cerr << licz(n,a,b,k,i) << "\n";
	}
	res %= MOD;
	res += MOD;
	res %= MOD;
	cout << res << "\n";
	
}

#undef int
int main() {
	IOSYNC;
	int t;
	t = 1;
	while(t--) jebaj();
	return 0;
}