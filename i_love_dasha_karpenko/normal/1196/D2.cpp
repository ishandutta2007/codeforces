#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define po(x) (1<<x)
#define schnell ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL)
#define forn(i,n) for(ll i = 1;i<=n;i++)
typedef int ll;
typedef long double ld;
#define DIM 200007
#define DIM2 10007
#define MODULO 998244353 
#define MAXN 1000000
#define DIM2 31
const long long INF = 10E16;
const ll mask = po(9) - 1;
struct pp {
	ll fi, sc;
	bool operator < (const pp& b)const {
		if (fi == b.fi)return sc < b.sc;
		return fi < b.fi;
	}
	bool operator > (const pp& b)const {
		if (fi == b.fi)return sc > b.sc;
		return fi > b.fi;
	}
	bool operator == (const pp& b)const {
		if (fi == b.fi && sc == b.sc)return 1;
		return 0;
	}
};
ll q,R[DIM],G[DIM],B[DIM],n,k;
ll r(ll x) {
	if (x < k-1)return INF;
	ll cf = k % 3;
	if (cf == 0)return R[x] - R[x - k];
	if (cf == 1)return R[x]-B[x - k];
	if (cf == 2)return R[x]-G[x - k];
}
ll g(ll x) {
	if (x < k-1)return INF;
	ll cf = k % 3;
	if (cf == 0)return G[x]-G[x - k];
	if (cf == 1)return G[x]-R[x - k];
	if (cf == 2)return G[x]-B[x - k];
}
ll b(ll x) {
	if (x < k-1)return INF;
	ll cf = k % 3;
	if (cf == 0)return B[x] -B[x - k];
	if (cf == 1)return B[x] -G[x - k];
	if (cf == 2)return B[x] -R[x - k];
}
int main() {
	schnell;
	cin >> q;
	forn(h, q) {
		cin >> n >> k;
		string s; cin >> s;
		for (ll i = 0; i < n; i++) {
			R[i] = 0;
			G[i] = 0;
			B[i] = 0;
		}
		ll res = INF;
		for (ll i = 0; i < n; i++) {
			R[i] = B[i - 1]+1;
			G[i] = R[i - 1]+1;
			B[i] = G[i - 1]+1;
			if (s[i] == 'R')R[i]--;
			if (s[i] == 'B')B[i]--;
			if (s[i] == 'G')G[i]--;
			ll cof = min(r(i), min(b(i), g(i)));
			res = min(res, cof);
		}
		cout << res << endl;
	}
	return 0;
}