#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

struct node {
	int len, link;
	ll cnt;
	bool clone;
	map<char, int> next;
	vector<int> inv;
};

int sz;
node b[800005];

int init() {
	b[sz].link = -1;
	return sz++;
}

int extend(int root, int last, char x) {
	int curr = sz++;
	b[curr].len = b[last].len + 1;
	int p = last;
	for (; p != -1 && !b[p].next.count(x); p = b[p].link)
		b[p].next[x] = curr;
	if (p == -1) {
		b[curr].link = root;
	} else {
		int q = b[p].next[x];
		if (b[p].len + 1 == b[q].len) {
			b[curr].link = q;
		} else {
			int clone = sz++;
			b[clone] = b[q];
			b[clone].clone = true;
			b[clone].len = b[p].len + 1;
			for (; p != -1 && b[p].next[x] == q; p = b[p].link)
				b[p].next[x] = clone;
			b[curr].link = b[q].link = clone;
		}
	}
	return curr;
}

int automat(const string& s) {
	int l = sz;
	int root = init(), last = root;
	for (char x : s)
		last = extend(root, last, x);
	int r = sz;
	for (int i=l; i<r; i++) {
		if (b[i].link != -1) {
			b[b[i].link].inv.push_back(i);
		}
	}
	return root;
}

int walk(int root, const string& s) {
	for (char x : s) {
		auto it = b[root].next.find(x);
		if (it == b[root].next.end())
			return -1;
		root = it->second;
	}
	return root;
}

void prop(int root, vector<ll>& occ) {
	if (!b[root].clone) {
		occ[b[root].len] = b[root].cnt;
	}

	for (int x : b[root].inv) {
		b[x].cnt += b[root].cnt;
		prop(x, occ);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	string s;
	cin >> s;
	int sa = automat(s);
	string r = s;
	reverse(r.begin(), r.end());
	int sb = automat(r);

	int q;
	cin >> q;
	while (q--) {
		string a;
		cin >> a;
		string b = a;
		reverse(b.begin(), b.end());
		int pa = walk(sa, a);
		int pb = walk(sb, b);
		if (pa == -1 || pb == -1) {
			continue;
		}
		::b[pa].cnt++;
		::b[pb].cnt++;
	}

	ll sol = 0;
	int n = s.size();
	vector<ll> fa(n+1), fb(n+1);
	prop(sa, fa);
	prop(sb, fb);
	for (int i=1; i<n; i++) {
		// cerr << fa[i] << ' ' << fb[i] << '\n';
		sol += fa[i] * fb[n-i];
	}
	cout << sol << '\n';
}