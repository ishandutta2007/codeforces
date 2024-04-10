//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 2e6 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll n, x, y, t, a, ans, l, r, ps[maxn], cnt[maxn];

int main(){
	fast_io;
	
	cin >> n >> y >> x;
	
	t = y / x;
	
	for(ll i = 0; i < n; i++){
		cin >> a;
		cnt[a]++;
		ps[a] += a;
	}
	
	for(ll i = 1; i < maxn; i++){
		ps[i] += ps[i - 1];
		cnt[i] += cnt[i - 1];
	}
	
	ans = inf;
	
	for(ll i = 2; i < maxn; i++){
		a = 0;
		for(ll j = 1; i * j < maxn; j++){
			l = max(i * (j - 1), i * j - t - 1);
			r = i * j;
			a += (i * j * (cnt[r] - cnt[l]) - (ps[r] - ps[l])) * x + (cnt[l] - cnt[i * (j - 1)]) * y;
		}
		ans = min(ans, a);
	}
	
	cout << ans;
	
	return 0;
}