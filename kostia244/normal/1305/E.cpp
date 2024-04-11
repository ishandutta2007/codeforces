#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
using namespace std;
using ll = long long;
using vi = vector<ll>;
using pi = pair<int, int>;
const int maxn = 2e3 + 55;//, mod = 1e9 + 7;
ll n, m;
vi a = {1, 2};
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	if(n==1) {
		if(!m) cout << 1;
		else cout << -1;
		return 0;
	}
	if(n==2) {
		if(!m) cout << "1 2";
		else cout << -1;
		return 0;
	}
	ll x = 3;
	while(m>0) {
		if(m>=((x-1)/2)) {
			m -= (x-1)/2;
			a.pb(x++);
			continue;
		}
		x--;
		a.pb(x+x-2*m+1);
		break;
	}
	if(a.size()>n) return cout << -1, 0;
	int t = 1000001;
	while(a.size()<n) a.pb(t), t += 110000;
	for(auto i : a) cout << i << " ";
}