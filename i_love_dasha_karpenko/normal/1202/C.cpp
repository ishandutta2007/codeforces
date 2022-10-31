#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define po(x) (1<<x)
#define schnell ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL)
#define forn(i,n) for(ll i = 1;i<=n;i++)
typedef long long ll;
typedef long double ld;
#define DIM 200007
#define DIM2 10007
#define MODULO 998244353  
#define MAXN 1000000
const long long INF = 10E16;
const ll mask = po(9) - 1;
const ll base = 100000000000;
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
struct node {
	ll fi, sc, th;
};
ll t;
ll H[DIM], V[DIM],pref[2][DIM][2],suf[2][DIM][2];
int main() {

	schnell;
	cin >> t;
	forn(e, t) {
		string s;
		cin >> s;
		ll n= s.length();
		s = '0' + s;
		for (ll i = 1; i <= n; i++) {
			H[i] = H[i - 1];
			V[i] = V[i - 1];
			if (s[i] == 'W')H[i]++;
			if (s[i] == 'S')H[i]--;
			if (s[i] == 'D')V[i]++;
			if (s[i] == 'A')V[i]--;
			pref[0][i][1] = max(pref[0][i - 1][1], H[i]);
			pref[0][i][0] = min(pref[0][i - 1][0], H[i]);
			pref[1][i][0] = min(pref[1][i - 1][0], V[i]);
			pref[1][i][1] = max(pref[1][i - 1][1], V[i]);
		}
		suf[0][n][1] = H[n];
		suf[0][n][0] = H[n];
		suf[1][n][1] = V[n];
		suf[1][n][0] = V[n];
		for (ll i = n-1; i >= 1; i--) {
			suf[0][i][1] = max(suf[0][i + 1][1], H[i]);
			suf[0][i][0] = min(suf[0][i + 1][0], H[i]);
			suf[1][i][0] = min(suf[1][i + 1][0], V[i]);
			suf[1][i][1] = max(suf[1][i + 1][1], V[i]);
		}
		ll res = (pref[0][n][1] + pref[0][n][0] * -1 + 1) * (pref[1][n][1] + pref[1][n][0] * -1 + 1);
			
		for (ll i = 1; i < n; i++) {
			// W
			res = min(res,
			(max(pref[0][i][1],max( suf[0][i + 1][1] + 1,H[i]+1)) + min(pref[0][i][0], suf[0][i + 1][0] + 1) * -1 + 1) *
			(max(pref[1][i][1], suf[1][i + 1][1]) + min(pref[1][i][0], suf[1][i + 1][0]) * -1 + 1));
			// S
			res = min(res,
			(max(pref[0][i][1], suf[0][i + 1][1] - 1) + min(pref[0][i][0], min(H[i]-1,suf[0][i + 1][0] - 1)) * -1 + 1) *
			(max(pref[1][i][1], suf[1][i + 1][1]) + min(pref[1][i][0], suf[1][i + 1][0]) * -1 + 1));
			//D
			res = min(res,
			(max(pref[0][i][1], suf[0][i + 1][1]) + min(pref[0][i][0], suf[0][i + 1][0]) * -1 + 1) *
			(max(pref[1][i][1], max(V[i]+1,suf[1][i + 1][1]+1)) + min(pref[1][i][0], suf[1][i + 1][0]+1) * -1 + 1));
			//A
			res = min(res,
			(max(pref[0][i][1], suf[0][i + 1][1]) + min(pref[0][i][0], suf[0][i + 1][0]) * -1 + 1) *
			(max(pref[1][i][1], suf[1][i + 1][1] - 1) + min(pref[1][i][0],min(V[i]-1, suf[1][i + 1][0] - 1)) * -1 + 1));
		}
		cout << res << endl;
	}
	
	return 0;
}