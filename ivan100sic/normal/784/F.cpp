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
	for (int i=0; i<n; i++) {
		int x;
		cin >> x;
		for (int i=0; i<3628800/n; i++)
			a.push_back(x);
	}
	for (int i=0; i<25; i++)
		sort(a.begin(), a.end());
	for (int i=0; i<3628800; i+=3628800/n)
		cout << a[i] << " \n"[i == n-1];
}