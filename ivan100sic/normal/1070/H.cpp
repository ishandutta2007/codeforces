#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

map<string, int> cnt;
map<string, string> sol;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int n;
	cin >> n;
	while (n--) {
		string s;
		cin >> s;
		int m = s.size();
		set<string> q;
		for (int i=0; i<m; i++)
			for (int j=1; j<=m-i; j++)
				q.insert(s.substr(i, j));
		for (string e : q) {
			cnt[e]++;
			sol[e] = s;
		}
	}
	int q;
	cin >> q;
	while (q--) {
		string s;
		cin >> s;
		if (cnt[s] == 0)
			cout << "0 -\n";
		else {
			cout << cnt[s] << ' ' << sol[s] << "\n";
		}
	}
}