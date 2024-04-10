// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	int n, k;
	string s;
	cin >> n >> k >> s;

	deque<vector<int>> a;
	int h = 0;

	while (1) {
		vector<int> b;
		for (int i=1; i<n; i++) {
			if (s[i-1] == 'R' && s[i] == 'L') {
				b.push_back(i);
				swap(s[i-1], s[i]);
				h++;
				i++;
			}
		}
		if (b.size()) {
			a.push_back(b);
		} else {
			break;
		}
	}

	if (k < (int)a.size() || k > h) {
		cout << "-1\n";
		return 0;
	}

	while (k > 0) {
		if (k == (int)a.size()) {
			cout << a.front().size();
			for (int x : a.front())
				cout << ' ' << x;
			cout << '\n';
			a.pop_front();
			k--;
		} else {
			cout << "1 " << a.front().back() << '\n';
			a.front().pop_back();
			if (a.front().size() == 0)
				a.pop_front();
			k--;
		}
	}
}