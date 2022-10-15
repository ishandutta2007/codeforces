#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/STACK:128000000")
#define _USE_MATH_DEFINES
#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<algorithm>
#include<cmath>
#include<set>
#include<queue>
#include<sstream>
#include<utility>
#include<map>
#include<ctime>
#include<cstdio>
#include<cassert>

#define show(x) cerr << x
#define debug(x) show(#x << ": " << (x) << endl)
 
using namespace std; 
 
typedef long long ll; 
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
const long double PI = 3.14159265358979323846;  
const long double gammama = 0.57721566490153286060;
//const long double eps = 1e-5;
const int INF = 1000 * 1000 * 1000;
const ll LLINF = (ll)8 * 1000 * 1000 * 1000 * 1000 * 1000 * 1000;
const int N = 100 * 1000 + 1;
const ll MOD = 1000 * 1000 * 1000 + 7;


int n;
vector<vector<int> > g;
vector<int> x;
vector<ll> d1, d0;

ll power(ll x, ll n) {
	ll res = 1;
	while(n) {
		if (n & 1)
			res = (res * x) % MOD;
		x = (x * x) % MOD;
		n /= 2;
	}
	return res;
}

ll inv(ll x) {
	return power(x % MOD, MOD - 2);
}

void dfs(int pos, int pr = -1) {
	ll sum = 1;
	vector<int> ind;
	for (int i = 0; i < g[pos].size(); ++i) {
		int to = g[pos][i];
		if (to == pr)
			continue;
		dfs(to, pos);
		sum = (sum * (d0[to] + d1[to])) % MOD;
		if (((d0[to] + d1[to]) % MOD) == 0)
			ind.push_back(to);
	}
	if (x[pos] == 1) {
		d1[pos] = sum;
		return;
	}
	d0[pos] = sum;
	if (ind.size() >= 2) {
		d1[pos] = 0;
		return;
	}
	if (ind.size() == 1) {
		ll cur = 1;
		for (int i = 0; i < g[pos].size(); ++i) {
			int to = g[pos][i];
			if (to == pr)
				continue;
			if (to == ind[0])
				cur = (cur * d1[to]) % MOD;
			else
				cur = (cur * (d0[to] + d1[to])) % MOD;
		}
		d1[pos] = cur;
	}
	for (int i = 0; i < g[pos].size(); ++i) {
		int to = g[pos][i];
		if (to == pr)
			continue;
		d1[pos] = d1[pos] + (((d1[to] * sum) % MOD) * inv(d1[to] + d0[to])) % MOD;
	}
	d1[pos] %= MOD;	
}

void solve() {
	cin >> n;
	g.resize(n);
	x.resize(n);
	for (int i = 0; i < n - 1; ++i) {
		int p;
		cin >> p;
		g[i + 1].push_back(p);
		g[p].push_back(i + 1);
	}
	for (int i = 0; i < n; ++i)
		cin >> x[i];
	d1.assign(n, 0);
	d0.assign(n, 0);
	dfs(0);
	cout << d1[0] << endl;
}


//#define LOCAL

int main() {
	ios_base::sync_with_stdio(0);
#ifdef LOCAL
	freopen("input.txt", "rt", stdin);
	//freopen("output.txt", "wt", stdout);
#endif
	solve();
	
	
#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif	
	return 0;
}