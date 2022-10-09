// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

template<class T = int, class F = plus<T>>
struct fenwick {
	vector<T> a;
	T e;
	F f;

	fenwick(int n, T e = T(), F f = F()) : a(n, e), e(e), f(f) {}

	void add(int p, const T& v) {
		for (p++; p <= (int)a.size(); p += p & -p)
			a[p-1] = f(a[p-1], v);
	}

	T operator() (int p) const {
		T v = e;
		for (; p; p -= p & -p)
			v = f(v, a[p-1]);
		return v;
	}
};

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	int n;
	string s;
	cin >> n >> s;
	string t = s;
	reverse(begin(t), end(t));
	map<char, queue<int>> mp;

	for (int i=0; i<n; i++) {
		mp[s[i]].push(i);
	}

	fenwick d(n);
	for (int i=0; i<n; i++) {
		d.add(i, 1);
	}

	ll sol = 0;

	for (int i=0; i<n; i++) {
		auto& q = mp[t[i]];
		int y = q.front(); q.pop();
		sol += d(y);
		d.add(y, -1);
	}

	cout << sol << '\n';
}