#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
int a[200005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=1; i<=n; i++)
		cin >> a[i];

	string s;
	cin >> s;

	set<pair<int, int>> prazni, polu;

	for (int i=1; i<=n; i++)
		prazni.insert({a[i], i});

	for (char x : s) {
		if (x == '0') {
			auto p = *prazni.begin();
			prazni.erase(p);
			cout << p.second << ' ';
			polu.insert({-p.first, p.second});
		} else {
			auto p = *polu.begin();
			polu.erase(p);
			cout << p.second << ' ';
		}
	}
}