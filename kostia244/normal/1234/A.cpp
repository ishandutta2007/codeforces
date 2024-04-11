#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
using vi = vector<ll>;
const ll mod = 998244353ll;

void solve() {
	int n;
	cin >> n;
	ll t, s= 0;
	for(int i = 0; i < n; i++) cin >> t, s+=t;
	s = (s+n-1)/n;
	cout << s << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--) solve();
}