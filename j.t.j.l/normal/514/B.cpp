#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

const int MM = 1e9 + 7;
const double eps = 1e-8;
const int MAXN = 2e3 + 10;
const int MAXM = 2e6 + 10;

int n, m;
char s[MAXM];
int a[MAXM];
int f[MAXN][MAXN];

set<PII> mp;

ll x, y;

ll gcd(ll p, ll q){
	return q ? gcd(q, p % q) : p;
}

ll absll(ll x){
	return x < 0 ? -x : x;
}

void read(){
	scanf("%d%lld%lld", &n, &x, &y);
	mp.clear();
	for(int i = 1; i <= n; i++){
		ll p, q;
		scanf("%lld%lld", &p, &q);
		p -= x, q -= y;
		if (p < 0){
			p = -p, q = -q;
		}
		if (p == 0)
			q = absll(q);
		ll r = gcd(p, absll(q));
		p /= r, q /= r;
		mp.insert(PII(p, q));
	}
	printf("%u\n", mp.size());
}

void solve(){

}

void printans(){

}
	

int main(){
	int T = 1;
//	cin >> T;
	while(T--){
		read();
		solve();
		printans();
	}
	return 0;
}