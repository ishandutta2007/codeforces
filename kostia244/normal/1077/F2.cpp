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
int n, k, x;
vi a, rkq, dp;
void upd() {
	deque<ll> q;
	vi trkq(n+1);
	for(int i = 0; i < n; i++) {
		while(!q.empty()&&q.back()<rkq[i]) q.pop_back();
		q.push_back(rkq[i]);
		trkq[i] = q.front();
		if(i-k+1>=0&&!q.empty()&&q.front()==rkq[i-k+1])
			q.pop_front();
	}
	rkq=trkq;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> k >> x;
	a.resize(n);
	for(auto &i : a) cin >> i;
	rkq.assign(n+1, -1e16);
	for(int i = 0; i+1 < k; i++)
		rkq[i]=0;
	dp.assign(n+1, 0);
	ll ans = -1;
	for(int i = 0; i < x; i++) {
		for(int j = i; j < n; j++) {
			dp[j] = (j?rkq[j-1]:0)+a[j];
			if(j>=n-k&&i+1==x)
				ans=max(dp[j],ans);
		}
		rkq = dp;
		upd();
	}
	cout << ans;
}