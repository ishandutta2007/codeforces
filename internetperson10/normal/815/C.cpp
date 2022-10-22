#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

vector<vector<vector<int>>> best[2]; // coupon, vertex, goods, k
vector<int> a1, a2;
vector<int> sub; // size of subtree
vector<vector<int>> ch;

int get(int v, int g, int m, bool c, int k=0) { // m is goods left
	if(ch[v].size() == k) {
		if(g == 0) return 0;
		else if(c) return a2[v];
		else return a1[v];
	}
	if(best[c][v][k][g] > -1) return best[c][v][k][g];
	// cout << v << ' ' << g << ' ' << m << ' ' << c << ' ' << k << "\n";
	int ans = 1000000001;
	int ne = ch[v][k]; // next to pick
	if(c) {
		for(int i = max(0, g - (m - sub[ne])); i <= min(sub[ne], g-1); i++) {
			ans = min(ans, get(ne, i, sub[ne], c) + get(v, g-i, m-sub[ne], c, k+1));
		}
	}
	else {
		for(int i = max(0, g - (m - sub[ne])); i <= min(sub[ne], g); i++) {
			ans = min(ans, get(ne, i, sub[ne], c) + get(v, g-i, m-sub[ne], c, k+1));
		}
	}
	// cout << v << ' ' << g << ' ' << c << ' ' << k << ' ' << ans << '\n';
	if((k == 0) && c) ans = min(ans, get(v, g, m, false));
	return best[c][v][k][g] = ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, d;
	cin >> n >> d;
	sub.resize(n);
	ch.resize(n);
	for(int i = 0; i < n; i++) {
		int c1, c2;
		int p;
		cin >> c1 >> c2;
		a1.push_back(c1); a2.push_back(c1-c2);
		if(i > 0) {
			cin >> p;
			p--;
			ch[p].push_back(i);
		}
	}
	for(int i = n-1; i >= 0; i--) {
		sub[i]++;
		for(int j : ch[i]) sub[i] += sub[j];
	}
	for(int z = 0; z < 2; z++) {
		best[z].resize(n);
		for(int i = 0; i < n; i++) {
			best[z][i].resize(ch[i].size());
			int init = sub[i];
			for(int j = 0; j < ch[i].size(); j++) {
				best[z][i][j].resize(init+1, -1);
				init -= sub[ch[i][j]];
			}
		}
	}
	// cout << "Yay\n";
	int l = 0, r = n+1;
	while(l != r-1) {
		int mid = (l+r)/2;
		if(get(0, mid, n, true) > d) r = mid;
		else l = mid;
	}
	cout << l << '\n';
}