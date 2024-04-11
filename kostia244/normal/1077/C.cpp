#pragma GCC optimize ("unroll-loops")
#pragma GCC optimize ("O3")
#include<bits/stdc++.h>
#include<bits/extc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
using namespace std;
using namespace __gnu_pbds;
using ll = long long;
using vi = vector<ll>;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	vi a;
	a.resize(n);
	ll sm = 0;
	map<ll, ll> cnt;
	for (auto &i : a)
		cin >> i, cnt[i]++, sm += i;
//	int ans = 0;
	vi ans;
	for(int i = 0; i < n; i++) {
		cnt[a[i]]--;
		if((sm-a[i])%2 == 0 && cnt[(sm-a[i])/2])
			ans.pb(i+1);
		cnt[a[i]]++;
	}
	cout << ans.size() << "\n";
	for(auto i : ans) cout << i << " ";
}