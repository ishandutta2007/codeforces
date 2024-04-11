#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;
using ll = long long;
using vi = vector<ll>;
const int maxn = 1e5 + 55;
const int mod = 1e9 + 7;
int n, a[201000], l[201000], r[201000], ans = 0;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	stack<int> x;
	vector<pair<ll, ll>> ans;
	for(int i = 1; i <= n; i++) {
		while(!x.empty() && a[x.top()]>=a[i]) x.pop();
		l[i] = x.empty()?1:x.top()+1;
		x.push(i);
	}
	while(!x.empty()) x.pop();
	for(int i = n; i; i--) {
		while(!x.empty() && a[x.top()]>=a[i]) x.pop();
		r[i] = x.empty()?n:x.top()-1;
		x.push(i);
	}
	for(int i = 1; i <= n; i++) {
		ans.pb({r[i]-l[i]+1, a[i]});
	}
	sort(rall(ans));
	ll j =0, cur[201000];
	cur[n] = 0;
	for(int l = n; l>0; l--) {
		while(j < ans.size() && ans[j].first>=l) {
//			cout << ans[j].first << " " << ans[j].second << "\n";
			cur[l] = max(cur[l], ans[j].second);
			j++;
		}
		cur[l-1] = cur[l];
	}
	for(int i = 1; i <= n; i++) cout << cur[i] << " ";
}