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

typedef unsigned long long ull;

ull p[100005];

const ull C1 = 314'983'498'433'143ull;
const ull C2 = 721'985'877'871'743'321ull;
const ull C3 = 662'113'223'551'626'337ull;

int n;
vector<int> e[100005];

ull hu[100005], hd[100005];

void init() {
	p[0] = 1;
	for (int i=1; i<100005; i++) {
		p[i] = p[i-1] * C1;
	}
}

template<class T>
ull hash_range(T begin, T end, ull val = 0) {
	while (begin != end) {
		val = val * C1 + *begin;
		++begin;
	}

	return val;
}

vector<ull> helper[100005];
vector<ull> hoolper[100005];

template<class T, class U>
void hash_prepare_range(T begin, T end, U& tmp) {

	tmp.resize(end - begin + 1);

	int i = 0;
	ull val = 0;
	while (begin != end) {
		tmp[i] = val;
		val = val * C1 + *begin;
		i++;
		++begin;
	}
	tmp[i] = val;
}

template<class U>
ull hash_range_advanced(int l, int r, U& tmp) {
	return tmp[r] - tmp[l] * p[r-l];
}

// racunamo samo heseve na dole
void dfs_d(int x, int p) {
	if (x != p) {
		vector<ull> h;
		for (int y : e[x]) {
			if (y != p) {
				dfs_d(y, x);
				h.push_back(hd[y]);
			}
		}

		sort(h.begin(), h.end());
		hd[x] = (hash_range(h.begin(), h.end()) + C3) ^ C2;
	} else {
		for (int y : e[x]) {
			dfs_d(y, x);
		}
	}
}



// izracunali na dole, sad racunamo na gore
void dfs_u(int x, int p) {

	// cerr << x << '\n';

	if (x != p) {

		// racunaj svoj hu

		auto it = lower_bound(helper[p].begin(), helper[p].end(), hd[x]) - helper[p].begin();

		hu[x] = hash_range_advanced(0, it, hoolper[p]);
		hu[x] = (hu[x] * ::p[helper[p].size() - it - 1] +
			hash_range_advanced(it+1, helper[p].size(), hoolper[p]) + C3) ^ C2;

		// spremi se da racunas hu za svoju decu

		for (int y : e[x]) {
			if (y != p) {
				helper[x].push_back(hd[y]);
			}
		}

		helper[x].push_back(hu[x]);
		sort(helper[x].begin(), helper[x].end());
		hash_prepare_range(helper[x].begin(), helper[x].end(), hoolper[x]);

		// do it

		for (int y : e[x]) {
			if (y != p) {
				dfs_u(y, x);
			}
		}

	} else {

		for (int y : e[x]) {
			helper[x].push_back(hd[y]);
		}
		sort(helper[x].begin(), helper[x].end());
		hash_prepare_range(helper[x].begin(), helper[x].end(), hoolper[x]);

		for (int y : e[x]) {
			dfs_u(y, x);
		}
	}
}

void ucitaj() {
	cin >> n;
	for (int i=1; i<n; i++) {
		int u, v;
		cin >> u >> v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
}

map<ull, int> br;
int uq;

void hadd(ull x) {
	if (++br[x] == 1) {
		uq++;
	}
}

void hrem(ull x) {
	if (--br[x] == 0) {
		uq--;
	}
}

int sol = -1, bx;

void tour(int x, int p) {

	// cerr << "tour " << x << ' ' << uq << '\n';

	if (uq > sol) {
		sol = uq;
		bx = x;
	}

	for (int y : e[x]) {
		if (y != p) {
			hrem(hd[y]);
			hadd(hu[y]);
			tour(y, x);
			hrem(hu[y]);
			hadd(hd[y]);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	init();
	ucitaj();

	dfs_d(1, 1);
	dfs_u(1, 1);

	/*
	for (int i=2; i<=n; i++) {
		cerr << i << ' ' << hd[i] << ' ' << hu[i] << '\n';
	}
	*/

	for (int i=2; i<=n; i++) {
		hadd(hd[i]);
	}

	tour(1, 1);

	cout << bx;
}