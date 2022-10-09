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

	int n;
	cin >> n;
	vector<int> a;
	int prev = 0;
	for (int i=1; i<=n; i++) {
		int x;
		cin >> x;
		if (x == 1) {
			if (prev)
				a.push_back(prev);
		}
		prev = x;
	}
	a.push_back(prev);
	cout << a.size() << '\n';
	for (int x : a)
		cout <<x << ' ';
}