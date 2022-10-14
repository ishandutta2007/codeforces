#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>

using namespace std;

const int MAXN = 200005;

int n, s, cnt, br;
int l[MAXN], bio[MAXN];
vector <int> v, t, r;
vector < pair <int, int> > g[MAXN];
vector < vector <int> > sol, nsol;

void sazimanje () {
	v.push_back(0);
	for (int i=1; i<=n; i++) {
		v.push_back(l[i]);
	}
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	br = (int) v.size() - 1;
	for (int i=1; i<=n; i++) {
		l[i] = lower_bound(v.begin(), v.end(), l[i]) - v.begin();
	}
	v.clear();
	v.push_back(0);
	for (int i=1; i<=n; i++) {
		v.push_back(l[i]);
	}
	sort(v.begin(), v.end());
}

void euler (int x) {
	bio[x] = 1;
	while (g[x].size() >= 1) {
		int sus = g[x].back().first;
		int ind = g[x].back().second;
		g[x].pop_back();
		euler(sus);
		t.push_back(ind);
	}
}

int main () {
	cin >> n >> s;
	for (int i=1; i<=n; i++) {
		scanf("%d", &l[i]);
	}
	sazimanje();
	for (int i=1; i<=n; i++) {
		if (v[i] != l[i]) {
			cnt++;
			g[v[i]].push_back(make_pair(l[i], i));
		}
	}
	if (cnt > s) {
		cout << -1;
		return 0;
	}
	for (int i=1; i<=br; i++) {
		if (!bio[i]) {
			t.clear();
			euler(i);
			reverse(t.begin(), t.end());
			if (t.size() >= 1) sol.push_back(t);
		}
	}
	int k = min((int) sol.size(), s - cnt);
	if (k > 1) {
		for (int i=k-1; i>=0; i--) {
			r.push_back(sol[i].back());
		}
		nsol.push_back(r);
		r.clear();
		for (int i=0; i<k; i++) {
			for (int j=0; j<sol[i].size(); j++) {
				r.push_back(sol[i] [j]);
			}
		}
		nsol.push_back(r);
		for (int i=k; i<sol.size(); i++) {
			nsol.push_back(sol[i]);
		}
		swap(sol, nsol);
	}
	cout << sol.size() << endl;
	for (int i=0; i<sol.size(); i++) {
		printf("%d\n", sol[i].size());
		for (int j=0; j<sol[i].size(); j++) {
			printf("%d ", sol[i] [j]);
		}
		printf("\n");
	}
	return 0;
}