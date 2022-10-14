//#pragma GCC optimize("O2")
//#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
using ll = long long;
using vi = vector<ll>;
using pi = pair<ll, ll>;
const int maxn = 2e5 + 55;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int n, tsz, c[maxn][4], p[maxn];
vector<int> coord[2];
vector<pi> pos[maxn];
pi tree[4 * maxn];
void init() {
	tsz = 2*n;
	for (int i = 0; i < tsz; i++) {
		pos[i].pb( { tsz + 100, -1 });
		sort(rall(pos[i]));
	}
	for (int i = 0; i < tsz; i++) {
		tree[tsz + i] = pos[i].back();
	}
	for (int i = tsz; i--;) {
		tree[i] = min(tree[i << 1], tree[i << 1 | 1]);
	}
}
void pop(int i) {
	pos[i].pop_back();
	if(pos[i].empty()) pos[i].pb({tsz+100, -1});
	tree[tsz + i] = pos[i].back();
	for (i = tsz + i; i >>= 1;)
		tree[i] = min(tree[i << 1], tree[i << 1 | 1]);
}
pi get(int l, int r) {
	pi res = { tsz + 100, -1 };
	for(l+=tsz,r+=tsz+1; l < r; l>>=1, r>>=1) {
		if(l&1) res = min(res, tree[l++]);
		if(r&1) res = min(res, tree[--r]);
	}
	return res;
}
void read() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 4; j++) {
			cin >> c[i][j];
			coord[j & 1].pb(c[i][j]);
		}
	}
	for (int i = 0; i < 2; i++) {
		sort(all(coord[i]));
		coord[i].erase(unique(all(coord[i])), coord[i].end());
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 4; j++) {
			c[i][j] = lower_bound(all(coord[j & 1]), c[i][j]) - coord[j & 1].begin();
		}
	}
	for (int i = 0; i < n; i++) {
		pos[c[i][0]].pb( { c[i][1], i });
	}
}

vi go;
void bt(int v = n-1) {
	if(v == -1) return;
	bt(p[v]);
	go.pb(v+1);
}

void bfs() {
	queue<int> q;
	q.push(-1);
	init();
	for(int i = 0; i < n; i++) p[i] = -2;
	if(coord[0][0]||coord[1][0]) cout << -1, exit(0);
	while(!q.empty()) {
		int i = q.front();
		q.pop();
		int mx = i==-1?0:c[i][2], my = i==-1?0:c[i][3];
//		cout << i << " " << mx << " " << my << ":\n";
		while(true) {
			pi t = get(0, mx);
//			cout << t.first << " " << t.second << "\n";
			if(t.second==-1||t.first>my) break;
			p[t.second] = i;
//			cout <<t.second << "das" << "\n";
			pop(c[t.second][0]);
			q.push(t.second);
		}
	}
	if(p[n-1]==-2) cout << -1, exit(0);
	bt();
	cout << go.size() << "\n";
	for(auto i : go)
		cout << i << " ";
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	read();
	bfs();
}