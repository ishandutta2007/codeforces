#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>
#define all(c) ((c).begin()), ((c).end())
#define sz(x) ((int)(x).size())

#ifdef LOCAL
#include <print.h>
#else
#define trace(...) // remove in interactive
#define endl '\n'
#endif

const int N = 200005;
int ind[N];
int cnt = 0;
vector<int> At[N];
vector<int> adj[N];
int sizes[N];

int dfs(int s, int p){
	sizes[s] = 1;
	int bigc = -1;

	for(int v: adj[s]) if(v != p){
		sizes[s] = max(sizes[s], dfs(v, s) + 1);
		if(bigc == -1 || sizes[v] > sizes[bigc]) bigc = v;
	}
	// trace(s, bigc);
	if(bigc == -1){
		ind[s] = ++cnt;
		At[cnt].resize(2);
		At[cnt][1] = 1;
		return 1;
	}
	ind[s] = ind[bigc];
	// trace(At[ind[s]]);
	At[ind[s]].back()--;
	At[ind[s]].push_back(1);
	At[ind[s]][0]++;
	// trace(At[ind[s]]);
	for(int v: adj[s]) if(v != p && v != bigc){
		for(int r = 0; r < sz(At[ind[v]]); r++) At[ind[s]][r] += At[ind[v]][r];
	}
	return sizes[s];
}

ll getMax(int k, int n){
	int opt = n / 2;
	if(k >= opt) return (opt * 1LL * (n - opt));
	return k * 1LL * (n - k);
}

int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); // Remove in interactive problems
	int n,k; cin >> n >> k;
	for(int i = 1; i < n; i++){
		int u, v; cin >> u >> v;
		u--; v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	dfs(0, 0);
	// trace(At[ind[0]]);
	int p = At[ind[0]].size() - 1, r = 0;
	ll ans = -getMax(n, n);
	int rem = n;
	while(r <= k && p >= 0){
		for(int x = 0; x < At[ind[0]][p]; x++){
			rem -= p;
			r++;
			if(r > k) break;
			// trace(r, rem);
			ans = max(ans, r * 1LL * (n - r) - getMax(rem, n));
		}
		p--;
	}
	cout << ans << endl;
}