#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

ull B = 5513213683949581ull;
ull UNDEF = 5987321471411431ull;

int n;
basic_string<int> e[100005];
ull gore[100005], dole[100005];

int parent[100005];

template<class T, class U, int H>
struct minimap {
private:
	T keys[H];
public:
	U vals[H];
	U fowf;
	int len;

	minimap() {
		len = 0;
		for (int i=0; i<H; i++) {
			keys[i] = T();
			vals[i] = U();
		}
	}

	// int size() {
	// 	return len;
	// }

	U& operator[] (const T& x) {
		for (int i=0; i<len; i++) {
			if (keys[i] == x) {
				return vals[i];
			}
		}

		if (len < H) {
			keys[len] = x;
			return vals[len++] = U();
		} else {
			return fowf;
		}
	}

	int upv() {
		int z = 0;
		for (int i=0; i<len; i++) {
			if (vals[i] != U()) {
				z++;
			}
		}
		return z;
	}

	T positive_key() {
		for (int i=0; i<len; i++) {
			if (vals[i] != U()) {
				return keys[i];
			}
		}
		return T();
	}
};

void dfs1(int x, int p) {

	parent[x] = p;
	minimap<ull, int, 3> mp;

	for (int y : e[x]) {
		if (y != p) {
			dfs1(y, x);
			mp[dole[y]]++;
		}
	}

	ull val;
	int u = mp.upv();
	if (u == 0) {
		val = 0;
	} else if (u == 1) {
		val = mp.positive_key();
	} else {
		val = UNDEF;
	}

	if (val != UNDEF) {
		val = val * B + e[x].size();
	}

	dole[x] = val;
}

// dole[1] se racuna ali je irelevantno


void dfs2(int x, int p) {
	minimap<ull, int, 3> mp;

	if (x != p) {
		mp[gore[x]]++;
	}

	for (int y : e[x]) {
		if (y == p)
			continue;

		mp[dole[y]]++;
	}

	for (int y : e[x]) {
		if (y == p)
			continue;

		mp[dole[y]]--;
		int u = mp.upv();

		if (u == 0) {
			gore[y] = 0;	
		} else if (u == 1) {
			gore[y] = mp.positive_key();
		} else {
			gore[y] = UNDEF;
		}

		mp[dole[y]]++;
	}

	for (int y : e[x]) {
		if (y == p)
			continue;

		if (gore[y] != UNDEF) {
			gore[y] = gore[y] * B + e[x].size();
		}
		dfs2(y, x);
	}
}

bool dobar(int x) {
	minimap<ull, int, 3> mp;

	for (int y : e[x]) {
		if (y == parent[x]) {
			mp[gore[x]]++;
		} else {
			mp[dole[y]]++;
		}
	}

	return mp.upv() == 1 && mp.positive_key() != UNDEF;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;

	if (n == 1) {
		cout << "1\n";
		return 0;
	}

	for (int i=1; i<n; i++) {
		int u, v;
		cin >> u >> v;
		e[u] += v;
		e[v] += u;
	}

	int root = 1;

	dfs1(root, root);
	dfs2(root, root);

	// for (int i=2; i<=n; i++) {
	// 	cerr << i << ' ' << gore[i] << ' ' << dole[i] << ' ' << dobar(i) << '\n';
	// }

	for (int i=1; i<=n; i++) {
		if (dobar(i)) {
			cout << i << '\n';
			return 0;
		}
	}
	cout << "-1\n";
}