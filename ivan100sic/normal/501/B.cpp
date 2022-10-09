#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	map<string, string> mp;
	int n;
	cin >> n;
	while (n--) {
		string a, b;
		cin >> a >> b;
		auto it = mp.find(a);
		if (it == mp.end()) {
			mp[b] = a;
		} else {
			auto tgt = it->second;
			mp.erase(it);
			mp[b] = tgt;
		}
	}

	cout << mp.size() << '\n';
	for (auto p : mp)
		cout << p.second << ' ' << p.first << '\n';
}