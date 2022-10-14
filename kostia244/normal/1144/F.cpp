#pragma GCC optimize("trapv")
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
#include<bits/extc++.h>
using namespace __gnu_pbds;
//using namespace __gnu_cxx;
#define pb push_back
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
using vi = vector<int>;
using pi = pair<ll, ll>;
using vpi = vector<pi>;
const int maxn = 3e5 + 33, mlg = 18, mod = 1e9 + 7;
int n, m;
vector<vi> g;
vi col;
void check(int v = 2, int c = 1) {
	col[v] = c;
	for(auto i : g[v]) {
		if(!col[i]) {
			check(i, c^3);
		} else if(col[i]==col[v]) {
			cout << "NO", exit(0);
		}
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	g.resize(n+1);
	col.resize(n+1);
	vpi e;
	for(int f, t, i = 0; i < m; i++) {
		cin >> f >> t;
		e.pb({f, t});
		g[f].pb(t);
		g[t].pb(f);
	}
	check();
	cout << "YES\n";
	for(auto i : e)
		cout << (col[i.first]-1);
}