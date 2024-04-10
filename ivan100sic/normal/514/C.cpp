#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

struct node {
	int nx[26], f;
} a[600005]; int sz;

struct stanje {
	int ptr, mistakes;
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int n, m;
	cin >> n >> m;
	while (n--) {
		string s;
		cin >> s;

		int p = 1;
		for (char x : s) {
			int y = x - 'a';
			int& sled = a[p].nx[y];
			if (sled)
				p = sled;
			else
				p = sled = ++sz;
		}

		a[p].f = 1;
	}

	while (m--) {
		string s;
		cin >> s;

		basic_string<stanje> q;

		q += {1, 0};

		for (char x : s) {
			int y = x - 'a';

			basic_string<stanje> tmp;

			for (stanje st : q) {
				if (st.mistakes == 0) {
					// pogresi!
					for (int z=0; z<26; z++) {
						if (z == y) {
							if (a[st.ptr].nx[z])
								tmp += {a[st.ptr].nx[z], 0};
						} else {
							if (a[st.ptr].nx[z])
								tmp += {a[st.ptr].nx[z], 1};
						}
					}
				} else {
					if (a[st.ptr].nx[y])
						tmp += {a[st.ptr].nx[y], 1};
				}
			}

			swap(q, tmp);
		}

		int ok = 0;
		for (auto st : q)
			if (st.mistakes)
				ok |= a[st.ptr].f;

		cout << (ok ? "YES\n" : "NO\n");
	}
}