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

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;

		string s, t;
		cin >> s >> t;
		vector<int> p;

		for (int i=0; i<n; i++)
			if (s[i] != t[i])
				p.push_back(i);

		if (p.size() == 0) {
			cout << "Yes\n";
		} else if (p.size() == 2) {
			string s1 = s, s2 = s;
			string t1 = t, t2 = t;
			swap(s1[p[0]], t1[p[1]]);
			swap(s2[p[1]], t2[p[0]]);
			if (s1 == t1 || s2 == t2) {
				cout << "Yes\n";
			} else {
				cout << "No\n";
			}
		} else {
			cout << "No\n";
		}
	}
}