#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, sz;
int kraj[100005];
struct trie {
	int nx[26];
	int p, c, e, q;
} d[100005];

int ubaci(string s) {
	int t = 0;
	int dub = 0;
	for (char x : s) {
		int y = x - 'a';
		if (d[t].nx[y] == 0) {
			d[t].nx[y] = ++sz;
			d[sz].p = t;
		}
		t = d[t].nx[y];
		d[t].c++;
		d[t].q = ++dub;
	}
	d[t].e = 1;
	return t;
}

typedef map<int, int> mii;

void spoji(mii& a, mii& b) {
	if (b.size() > a.size())
		swap(a, b);
	for (auto p : b)
		a[p.first] += p.second;
}

mii dfs(int x) {
	vector<mii> v;
	for (int i=0; i<26; i++) {
		if (d[x].nx[i])
			v.push_back(dfs(d[x].nx[i]));
	}
	mii tmp;
	for (auto& z : v)
		spoji(tmp, z);

	if (d[x].e) {
		tmp[d[x].q]++;
	} else {
		if (tmp.size()) {
			tmp[d[x].q]++;
			if (!--tmp.rbegin()->second)
				tmp.erase(--tmp.end());
		}
	}
	return tmp;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=1; i<=n; i++) {
		string s;
		cin >> s;
		kraj[i] = ubaci(s);
	}
	
	int sol = 0;
	for (int i=0; i<26; i++) {
		if (d[0].nx[i]) {
			auto r = dfs(d[0].nx[i]);
			for (auto p : r)
				sol += p.first * p.second;
		}
	}

	cout << sol << '\n';
}