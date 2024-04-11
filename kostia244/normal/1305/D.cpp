#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
using namespace std;
using ll = long long;
using vi = vector<ll>;
using pi = pair<int, int>;
const int maxn = 2e3 + 55;//, mod = 1e9 + 7;
int n;
queue<int> l;
vector<set<int>> g;
int q(int u, int v) {
	int w;
	cout << "? " << u << " " << v << endl;
	cin >> w;
	return w;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	g.resize(n+1);
	for(int f, t, i = 1; i < n; i++) {
		cin >> f >> t;
		g[f].insert(t);
		g[t].insert(f);
	}
	for(int i = 1; i <= n; i++) {
		if(g[i].size()==1) l.push(i);
	}
	while(true) {
		if(l.size()==1) return cout << "! " << l.front() << endl, 0;
		int a = l.front();
		l.pop();
		int b = l.front();
		l.pop();
		int c = q(a, b);
		if(c==a||c==b) return cout << "! " << c << endl, 0;
		int pa = *g[a].begin();
		int pb = *g[b].begin();
		g[pb].erase(b);
		g[pa].erase(a);
		if(g[pa].size()<=1) l.push(pa);
		if(pb!=pa&&g[pb].size()<=1) l.push(pb);
	}
}