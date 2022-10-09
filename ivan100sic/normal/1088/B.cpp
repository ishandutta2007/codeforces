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
	vector<int> a(n);
	for (int i=0; i<n; i++)
		cin >> a[i];
	sort(a.begin(), a.end());
	a.resize(unique(a.begin(), a.end()) - a.begin());
	for (int i=0; i<k; i++) {
		if (i == 0)
			cout << a[0];
		else if (i < (int)a.size())
			cout << a[i] - a[i-1];
		else
			cout << 0;
		cout << '\n';
	}
}