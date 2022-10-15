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

#define show(x) cerr << x
#define debug(x) show(#x << ": " << (x) << endl)
 
using namespace std;  
 
typedef long long ll; 
typedef unsigned long long ull; 

typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;

const long double PI = 3.14159265358979323846;  
const long double gammama = 0.57721566490153286060;
//const long double eps = 1e-5;
const int INF = 2 * 1000 * 1000 * 1000 + 10;
const ll LLINF = (ll)4 * 1000 * 1000 * 1000 * 1000 * 1000 * 10;
const int N = 1000 * 1000 * 1000 + 100;
const int mod = 1000 * 1000 * 1000 + 9;

vector<ll> r;
vector<vector<pll> > g;

int dejkstra(int st) {
	int n = g.size();
	vector<ll> d = r;
	d[st] = 0;
	priority_queue<pll> q;
	q.push(pll(0, st));
	for (int i = 1; i < n; ++i) {
		if (d[i] < LLINF)
			q.push(pll(-d[i], i));
	}
	vector<int> used(n, true);
	used[st] = 0;
	while(!q.empty()) {
		pll tt = q.top();
		q.pop();
		int v = tt.second;
		ll di = -tt.first;
		if (di != d[v])
			continue;
		for (int i = 0; i < g[v].size(); ++i) {
			int to = g[v][i].first;
			ll len = g[v][i].second;
			if (d[to] > di + len) {
				d[to] = di + len;
				q.push(pll(-d[to], to));
				used[to] = false;
			}
			else {
				if (d[to] == di + len) 
					used[to] = false;
			}
		}
	}
	int res = 0;
	for (int i = 0; i < n; ++i)
		if (used[i])
			++res;
	return res;
}


int main() {
	//ios_base::sync_with_stdio(0);
    //freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ll n, m, k;
	cin >> n >> m >> k;
	g.resize(n);
	for (int i = 0; i < m; ++i) {
		ll a, b, c;
		cin >> a >> b >> c;
		--a, --b;
		g[a].push_back(pll(b, c));
		g[b].push_back(pll(a, c));
	}
	r.assign(n, LLINF);
	//vector<pll> railroad(k);
	for (int i = 0; i < k ;++i) {
		ll s, y;
		cin >> s >> y;
		--s;
		r[s] = min(r[s], y);
	}
	//sort(railroad.begin(), railroad.end());
	cout << k - dejkstra(0) << endl;
		
    return 0;
}