#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
int b[505];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	multiset<int> ms;

	for (int i=0; i<n*n; i++) {
		int x;
		cin >> x;
		ms.insert(x);
	}

	for (int i=0; i<n; i++) {
		b[i] = *--ms.end();
		ms.erase(--ms.end());
		for (int j=0; j<i; j++) {
			ms.erase(ms.find(gcd(b[i], b[j])));
			ms.erase(ms.find(gcd(b[i], b[j])));
		}
		cout << b[i] << " \n"[i == n-1];
	}
}