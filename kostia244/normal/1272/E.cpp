#define _GLIBCXX_DEBUG
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
using ll = long long;
using vi = vector<ll>;
using pi = pair<ll, ll>;
ll n, a[1<<18], dp[1<<18];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	queue<int> q;
	vector<vi> g(n+1);
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for(int i = 1; i <= n; i++) {
		dp[i] = -1;
		if(i-a[i]>0&&((a[i-a[i]]^a[i])&1)) dp[i] = 1;
		if(i+a[i]<=n&&((a[i+a[i]]^a[i])&1)) dp[i] = 1;
		if(i-a[i]>0&&!((a[i-a[i]]^a[i])&1)) g[i-a[i]].pb(i);
		if(i+a[i]<=n&&!((a[i+a[i]]^a[i])&1)) g[i+a[i]].pb(i);
		if(dp[i]>0) {
			q.push(i);
		}
	}
	while(!q.empty()) {
		int i;
		i = q.front();
//		cout << i << " :";
		q.pop();
		for(auto j : g[i]) if(dp[j] == -1) dp[j] = dp[i]+1, q.push(j);
//		cout << "\n";
	}
	for(int i = 1; i <= n; i++) cout << dp[i] << " ";
}