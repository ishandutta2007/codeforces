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

	int n, k;
	cin >> n >> k;
	string s, p, q;
	cin >> s;

	int rem = (n-k) / 2;

	for (char x : s) {
		q += x;
		if (x == ')') {
			p.pop_back();
			if (rem > 0) {
				rem--;
				q.pop_back();
				q.pop_back();
			}
		} else {
			p += x;
		}
	}

	cout << q;
}