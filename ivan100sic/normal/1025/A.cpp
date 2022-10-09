#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

void moz() {
	cout << "Yes\n";
	exit(0);
}

void nem() {
	cout << "No\n";
	exit(0);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int n;
	cin >> n;
	string s;
	cin >> s;
	if (s.size() == 1)
		moz();

	map<int, int> m;
	for (char x : s)
		m[x]++;
	for (auto p : m)
		if (p.second >= 2)
			moz();

	nem();
}