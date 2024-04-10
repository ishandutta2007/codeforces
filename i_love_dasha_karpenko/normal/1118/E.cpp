#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define po(x) (1<<x)
#define schnell ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL)
#define forn(i,n) for(ll i = 1;i<=n;i++)
typedef long long  ll;
typedef long double ld;
#define DIM 507
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
ll n, k;
vector<pp> ans;
int main() {
	schnell;
	cin >> n >> k;
	ll cn = 1;
	pp pos = { 1,2 };
	while (cn <= n) {
		
		ans.pb(pos);
		ans.pb({ pos.sc,pos.fi });
		pos.sc++;
		if (pos.sc > k) {
			pos.fi++;
			pos.sc = pos.fi + 1;
		}
		cn += 2;
		if (pos.fi == k)break;
		
	}
	if (ans.size() < n) {
		cout << "NO" << endl;
	}
	else {
		cout << "YES" << endl;
		for (ll i = 0; i < n; i++) {
			cout << ans[i].fi << ' ' << ans[i].sc << endl;
		}
	}
	return 0;
}