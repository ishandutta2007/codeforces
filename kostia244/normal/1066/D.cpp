#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
using namespace std;
using ll = long long;
using vi = vector<ll>;
const ll mod = 1000000007ll;
ll n, m, k;
vi a;

bool can(int x) {
	if(n-x < 0) return 0;
	ll bxid = 0, lft = k;
	for(int i = n-x; bxid < m && i < n; i++) {
		if(lft >= a[i])
			lft -= a[i];
		else {
			lft = k;
			bxid++;
			lft -= a[i];
			if(lft < 0)
				return 0;
		}
	}
	return bxid < m;
}

int main() {
	ios::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	cin >> n >> m >> k;
	a.resize(n);
	for(auto &i : a) cin >> i;
	ll ans = 0;
	for(ll i = 1<<17; i; i>>=1)
		if(can(ans+i)) ans+=i;
	cout << ans;
}