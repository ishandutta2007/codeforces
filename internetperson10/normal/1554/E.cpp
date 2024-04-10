#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

const ll MOD = 998244353;

vector<vector<int>> adj, divs;
vector<int> ans, divv, primes, anses;

int dfs(int n, int k, int par = -1) {
	int gets = 0;
	for(int d : adj[n]) {
		if(d == par) continue;
		int g = dfs(d, k, n);
		if(g == -1) {
			if(par == -1) return 0;
			return -1;
		}
		gets += g;
	}
	if(par == -1) {
		if(!(gets%k)) return 1;
		if(!((gets+1)%k)) return 1;
		return 0;
	}
	if(!(gets%k)) return 1;
	if(!((gets+1)%k)) return 0;
	return -1;
}

void rec(int n, int k=1) {
	if(n == divs.size()) {
		if(k > 1) divv.push_back(k);
		return;
	}
	for(int d : divs[n]) {
		rec(n+1, k*d);
	}
}

void get_div(int n) {
	int i = 0;
	for(int p : primes) {
		if(!(n%p)) {
			divs.push_back(vector<int>());
			int k = 1;
			divs[i].push_back(k);
			while(!(n%p)) {	
				k *= p;
				divs[i].push_back(k);
				n /= p;
			}
			i++;
		}
	}
	if(n > 1) {
		divs.push_back(vector<int>());
		divs[i].push_back(1);
		divs[i].push_back(n);
	}
	rec(0);
	sort(divv.begin(), divv.end());
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	for(int i = 2; i < 400; i++) {
		bool sad = false;
		for(int p : primes) {
			if(!(i%p)) {
				sad = true;
				break;
			}
		}
		if(!sad) {
			primes.push_back(i);
			// cout << i << '\n';
		}
	}
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		adj.resize(n);
		anses.resize(n+1);
		ll pow2 = 1;
		for(int i = 0; i < n-1; i++) {
			int x, y;
			cin >> x >> y;
			x--; y--;
			adj[x].push_back(y);
			adj[y].push_back(x);
			pow2 *= 2;
			pow2 %= MOD;
		}
		get_div(n-1);
		for(int i = 0; i < divv.size(); i++) {
			int c = dfs(0, divv[i]);
			ans.push_back(c);
			pow2 -= c;
		}
		for(int i = ans.size()-1; i >= 0; i--) {
			for(int j = i-1; j >= 0; j--) {
				if(!(divv[i]%divv[j]) && ans[i] && ans[j]) {
					pow2++;
					ans[j] = 0;
				}
			}
		}
		pow2 += MOD;
		pow2 %= MOD;
		for(int i = 0; i < ans.size(); i++) {
			anses[divv[i]] = ans[i];
		}
		cout << pow2 << ' ';
		for(int i = 2; i <= n; i++) {
			cout << anses[i] << ' ';
		}
		cout << '\n';
		vector<vector<int>>().swap(adj);
		vector<vector<int>>().swap(divs);
		vector<int>().swap(ans);
		vector<int>().swap(divv);
		vector<int>().swap(anses);
	}
}