#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
using namespace std;
int k;
vector<int> a[20], ui[1<<15], uv[1<<15], m;
map<int, int> id;
long long p[1<<15], c[20], f[20], S[20], x;
void rec(int msk) {
	if(!msk) return;
	vector<int> Ui = ui[p[msk]], Uv = uv[p[msk]];
	for(int j = Ui.size()-1, i = 0; i < Ui.size(); i++, j = (j+1)%Ui.size()) {
		c[Ui[i]] = Uv[i];
		f[Ui[i]] = Ui[j];
	}
	rec(msk^p[msk]);
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> k;
	for(int t, i = 0; i < k; i++) {
		cin >> t;
		a[i].resize(t);
		for(int &j : a[i]) cin >> j, id[j] = i, x += j, S[i] += j;
	}
	if(x%k) return cout << "No", 0;
	x /= k;
	for(int i = 0; i < k; i++) {
		for(int v : a[i]) {
			vector<int> vis(k, 0), val, cyc;
			int j = i, u = 0, ov = v;
			while(!vis[j]) {
				vis[j] = 1;
				cyc.push_back(j);
				val.push_back(v);
				u |= 1<<j;
				v = x - (S[j]-v);
				if(!id.count(v)) {cyc.clear(); break;}
				j = id[v];
			}
			if(cyc.empty() || cyc[0] != j || v != ov) continue;
			ui[u] = cyc;
			uv[u] = val;
			m.push_back(u);
		} 
	}
	sort(all(m));
	m.erase(unique(all(m)), m.end());
	int j, inv;
	p[0] = -1;
	for(auto i : m) {
		j = inv = (1<<k)-i-1;
		while(true) {
			if(p[j]) p[j|i] = i;
			if(j) j = (j-1)&inv;
			else break;
		}
	}
	if(!p[(1<<k)-1]) return cout << "No\n", 0;
	rec((1<<k) - 1);
	for(int i = 0; i < k; i++) S[i] -= c[i], S[f[i]] += c[i];
	for(int i = 0; i < k; i++) if(S[i] != x) return cout << "No", 0;
	cout << "Yes\n";
	for(int i = 0; i < k; i++) cout << c[i] << " " << f[i]+1 << '\n';
}