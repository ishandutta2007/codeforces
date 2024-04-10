// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> a(n), b(n);
		for (int& x : a)
			cin >> x;
		sort(begin(a), end(a));
		int i = 0, j = n-1, k = 0;
		while (i <= j) {
			if (k % 2)
				b[k++] = a[i++];
			else
				b[k++] = a[j--];
		}
		reverse(begin(b), end(b));
		for (int x : b)
			cout << x << ' ';
		cout << '\n';
	}
}