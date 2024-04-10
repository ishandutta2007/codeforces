#include <bits/stdc++.h>
using namespace std;
#define fo(i,a,b) for(int i=(a);i<(b);i++)
#define MOD 1000000007
#define PB push_back
typedef long long ll;

int N, br[20][200200], d[20][200200], lev[200200];
vector<int> in, adj[200200], myc[200200], ans;
bool dead[200200];
vector<multiset<int>> m[200200];
multiset<int> sub, best[200200], outofall;

int go (int l, int i, int p=-1) {
	in.PB(i);
	for (int j : adj[i]) if (j != p && !dead[j]) {
		d[l][i] += go(l, j, i);
	}
	return ++d[l][i];
}

void dfs (int l, int i, int p) {
	//sub.insert(d[l][i]);
	for (int j : adj[i]) if (j != p && !dead[j]) {
		br[l][j] = br[l][i];
		d[l][j] = d[l][i] + 1;
		dfs(l, j, i);
	}
}

void rec (int l, int i) {
	in.clear(), go(l, i);
	int C = -1;
	for (int k : in) {
		int mx = d[l][i] - d[l][k];
		for (int j : adj[k]) if (d[l][j] < d[l][k]) {
			mx = max(mx, d[l][j]);
		}
		if (mx <= d[l][i]/2) { C = k; break; }
	}
	//printf("at level %d, %d is centroid\n", l, C);
	lev[C] = l;
	for (int k : in) {
		myc[k].PB(C);
	}
	for (int k : in) {
		d[l][k] = 0;
	}
	for (int j : adj[C]) if (!dead[j]) {
		sub.clear(), d[l][j] = 1;
		br[l][j] = (int) m[C].size();
		dfs(l, j, C), m[C].PB(sub);
	}

	dead[C] = 1;
	for (int j : adj[C]) if (!dead[j]) {
		rec(l+1, j);
	}
}

int main () {
	scanf("%d", &N);
	fo(i, 2, N+1) {
		int p; scanf("%d", &p);
		adj[i].PB(p), adj[p].PB(i);
	}
	rec(0, 1);
	fo(i, 1, N+1) {
		for (int c : myc[i]) {
			if ((int) best[c].size() >= 2) {
				auto it = --best[c].end();
				int t = *it + *prev(it);
				if (outofall.find(t) != outofall.end()) {
					outofall.erase(outofall.find(t));
				}
			}
			if (c == i) {
				best[c].insert(0);
			} else {
				int myb = br[lev[c]][i], myd = d[lev[c]][i];
				if (m[c][myb].size() && best[c].find(*m[c][myb].rbegin()) != best[c].end()) {
					best[c].erase(best[c].find(*m[c][myb].rbegin()));
				}
				m[c][myb].insert(myd);
				while ((int) m[c][myb].size() > 2) m[c][myb].erase(m[c][myb].begin());
				best[c].insert(*m[c][myb].rbegin());
				while ((int) best[c].size() > 2) best[c].erase(best[c].begin());
			}
			if ((int) best[c].size() >= 2) {
				auto it = --best[c].end();
				outofall.insert(*it + *prev(it));
				while ((int) outofall.size() > 2) outofall.erase(outofall.begin());
			}
		}
		if (i >= 2) printf("%d ", *outofall.rbegin());
	}
	return 0;
}