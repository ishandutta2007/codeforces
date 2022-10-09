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
	set<int> s;
	for (int i=0; i<n; i++) {
		int x, q;
		cin >> x;
		if (i % 2) {
			q = (x - i + n) % n; 
		} else {
			q = (i - x + n) % n;
		}
		s.insert(q);
	}
	cout << (s.size() == 1 ? "Yes\n" : "No\n");
}