#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define speed ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define ll long long
#define pb push_back
#define mp make_pair
#define f first
#define pill pair<ll, ll>
#define s second
#define ld long double
using namespace std;

const ll N = 4e5 + 10;
const ll mod = 998244353;
const ll big = 1e4;
const double eps = 1e-8;

ll t;
ll n, z;
ll a[N];
ll dp[N];
ll l[N], r[N];
ll L[N], R[N];
vector<ll> g[N], G[N];

void calc() {
	stack<pill> z;
	for(int i = 1; i <= n; i++) {
		while(z.size() && z.top().f >= a[i])
			z.pop();
		if(z.size()) L[i] = z.top().s + 1;
		else L[i] = 1;			
		z.push(mp(a[i], i));
	}
	while(z.size())z.pop();
	for(int i = n; i >= 1; i--) {
		while(z.size() && z.top().f >= a[i])
			z.pop();
		if(z.size()) R[i] = z.top().s - 1;
		else R[i] = n;
		z.push(mp(a[i], i));
	}
	while(z.size())z.pop();
	for(int i = 1; i <= n; i++) {
		while(z.size() && z.top().f <= a[i])
			z.pop();
		if(z.size()) l[i] = z.top().s + 1;
		else l[i] = 1;			
		z.push(mp(a[i], i));
	}
	while(z.size())z.pop();
	for(int i = n; i >= 1; i--) {
		while(z.size() && z.top().f <= a[i])
			z.pop();
		if(z.size()) r[i] = z.top().s - 1;
		else r[i] = n;
		z.push(mp(a[i], i));
	}
	while(z.size())z.pop();
		

}

int main() {
	speed;
	cin >> t;	
	while(t--) {
		cin >> n;
		for(int i = 1; i <= n; i++) {
			cin >> a[i];
		}
		dp[n] = 0;
		calc();
		ll pos = 1;
		for(int i = 1; i <= n; i++) {
			g[l[i]].pb(i);
			G[L[i]].pb(i);			
		}
		set<ll> za2, za1;
		ll ans = 0;	
		while(pos < n) {
			for(auto u : g[pos])
				za1.insert(u);
			for(auto u : G[pos])
				za2.insert(u);
			auto it = za1.upper_bound(R[pos]);
			auto it2 = za2.upper_bound(r[pos]);			
			ll Re = 0;
			if(za1.size() && it != za1.begin())Re = *prev(it);
			ll re = 0;
			if(za2.size() && it2 != za2.begin())re = *prev(it2);
		
			ll ri = max(re, Re);
			for(int j = pos + 1; j < ri; j++) {
				for(auto u : g[j])
					za1.insert(u);
				for(auto u : G[j])
					za2.insert(u);	
			}
			ans++;
			pos = ri;
		}
		cout << ans << '\n';
		for(int i = 1; i <= n; i++)
			g[i].clear(), G[i].clear();
	}
}
/*
3
1 0
3 0
5 0

*/