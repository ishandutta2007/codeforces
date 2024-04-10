#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

struct important_set {
	int z, l, m, r, a, b;

	important_set(int a, int b) {
		z = l = m = r = 0;
		this->a = a;
		this->b = b;
	}

	void add(int x, int dir = 1) {
		if (x < b)
			z += dir;
		else if (x < a)
			l += dir;
		else if (x >= 2*b)
			r += dir;
		else
			m += dir;
	}

	void rem(int x) {
		add(x, -1);
	}

	char winner() {
		if (l || r)
			return 'B';
		return 'A' + m%2;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int t;
	cin >> t;
	while (t--) {
		int a, b;
		string s;
		cin >> a >> b >> s;
		s += 'X';
		important_set is(a, b);
		int z = 0;
		vector<int> g;
		for (char x : s) {
			if (x == '.')
				z++;
			else
				is.add(z), g.push_back(z), z = 0;
		}
		char w = 'B';
		for (int x : g) {
			if (x >= a) {
				is.rem(x);
				for (int i=0; i<=x-a; i++) {
					is.add(i);
					is.add(x-a-i);
					if (is.winner() == 'A')
						w = 'A';
					is.rem(i);
					is.rem(x-a-i);
				}
				is.add(x);
			}
		}
		cout << (w == 'A' ? "YES\n" : "NO\n");
	}
}