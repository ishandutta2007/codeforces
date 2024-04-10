// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int n, k;
string a[1000005];

set<char> s;
string e[256];

bool vis[256];
bool inst[256];
string sol;
bool ok = 1;

void dfs(char c) {
	vis[+c] = 1;
	inst[+c] = 1;
	for (char d : e[+c]) {
		if (!vis[+d]) {
			dfs(d);
		} else if (inst[+d]) {
			ok = 0;
		}
	}
	inst[+c] = 0;
	sol += c;
}

int main() {
	ios::sync_with_stdio(!cin.tie(0));


	cin >> n >> k;
	for (int i=0; i<n; i++) {
		int j;
		cin >> j;
		for (int l=0; l<k; l++) {
			cin >> a[k*j+l];
		}
	}

	n *= k;

	for (int i=0; i<n; i++) {
		for (char c : a[i]) {
			s.insert(c);
		}
	}

	for (int i=0; i<n-1; i++) {
		int l = 0;
		string& u = a[i];
		string& v = a[i+1];
		while (l < (int)min(u.size(), v.size()) && u[l] == v[l]) l++;

		if (l < (int)min(u.size(), v.size())) {
			e[+v[l]] += u[l];
		} else {
			// meh
			if (u.size() > v.size()) {
				ok = 0;
			}
		}
	}

	for (char c : s) {
		if (!vis[+c]) {
			dfs(c);
		}
	}

	if (!ok) {
		sol = "IMPOSSIBLE";
	}

	cout << sol << '\n';
}