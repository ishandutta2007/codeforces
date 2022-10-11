#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 2e5 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll q, n, p[maxn], ps[maxn], x, a, y, b, k, z, l, r, mid;

ll cal(ll t){
	ll t1, t2, t3, s, ans, t0;
	t1 = t / z;
	t2 = t / a - t1;
	t3 = t / b - t1;
	pll per[3];
	per[0] = {t1, x + y};
	per[1] = {t2, x};
	per[2] = {t3, y};
	sort(per, per + 3);
	ans = 0;
	do{
		t0 = 0;
		s = 0;
		for(ll i = 0; i < 3; i++){
			s += (ps[per[i].F + t0] - ps[t0]) * per[i].S;
			t0 += per[i].F;
		}
		ans = max(ans, s);
	}while(next_permutation(per, per + 3));
	return ans;
}

int main(){
	fast_io;
	
	cin >> q;
	
	while(q--){
		cin >> n;
		for(ll i = 1; i <= n; i++){
			cin >> p[i];
			p[i] /= 100;
		}
		sort(p + 1, p + n + 1, greater<ll>());
		fill(ps, ps + maxn, 0);
		for(ll i = 1; i <= n; i++){
			ps[i] = ps[i - 1] + p[i];
		}
		cin >> x >> a;
		cin >> y >> b;
		cin >> k;
		z = (a * b) / __gcd(a, b);
		l = 0;
		r = n;
		if(cal(n) < k){
			cout << -1 << endl;
			continue;
		}
		while(r - l > 1){
			mid = (l + r) / 2;
			if(cal(mid) >= k){
				r = mid;
			}
			else{
				l = mid;
			}
		}
		cout << r << endl;
	}
	
	return 0;
}