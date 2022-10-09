#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <numeric>
#include <iterator>
#include <cstring>
using namespace std;

int n, k;
vector<int> e[200005];

struct stanje {
	long long a[5];
	long long c;

	stanje() {
		a[0] = a[1] = a[2] = a[3] = a[4] = c = 0;
	}

	stanje& operator+= (const stanje& other) {
		for (int i=0; i<k; i++) {
			a[i] += other.a[i];
		}
		c += other.c;

		return *this;
	}

	stanje bump() {
		stanje tmp;
		for (int i=1; i<k; i++) {
			tmp.a[i] = a[i-1];
		}
		tmp.a[0] = a[k-1];
		tmp.c = c + a[k-1];

		return tmp;
	}
};

stanje dole[200005];
stanje gore[200005];

vector<stanje> pref[200005], suff[200005];

void dfs1(int x, int p) {
	dole[x].a[0] = 1;

	for (int y : e[x]) {
		if (y != p) {
			dfs1(y, x);
			dole[x] += dole[y].bump();
		}
	}
}

void prep(int x, int p) {
	for (int y : e[x]) {
		if (y != p) {
			pref[x].push_back(dole[y].bump());
		}
	}

	suff[x] = pref[x];

	if (suff[x].size() > 1) {
		for (int i=1; i<pref[x].size(); i++) {
			pref[x][i] += pref[x][i-1];
		}

		for (int i=suff[x].size()-2; i>=0; i--) {
			suff[x][i] += suff[x][i+1];
		}
	}		
}

void dfs2(int x, int p, int chld) {
	prep(x, p);

	if (x != p) {
		// izracunaj si ga
		gore[x].a[0] = 1;

		gore[x] += gore[p].bump();
		if (chld > 0) {
			gore[x] += pref[p][chld-1];
		}
		if (chld < (int)suff[p].size()-1) {
			gore[x] += suff[p][chld+1];
		}
	}

	int c = 0;
	for (int y : e[x]) {
		if (y != p) {
			dfs2(y, x, c++);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> k;
	for (int i=1; i<n; i++) {
		int u, v;
		cin >> u >> v;
		e[u].push_back(v);
		e[v].push_back(u);
	}

	dfs1(1, 1);
	dfs2(1, 1, 0);

	/*
	for (int i=1; i<=n; i++) {
		cerr << gore[i].a[0] << ' ' << gore[i].a[1] << ' ' << gore[i].a[2] << '\n';
		cerr << gore[i].c << '\n';
	}
	*/	

	long long sol = 0;
	for (int x=1; x<=n; x++) {
		auto a1 = dole[x];
		if (x != 1) {
			a1 += gore[x].bump();
		}
		
		sol += a1.c;
		for (int i=1; i<k; i++) {
			sol += a1.a[i];
		}
	}

	cout << sol / 2;


}