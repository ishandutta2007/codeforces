#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

pair<int, int> a[105];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int n;
	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> a[i].first;
		a[i].second = i+1;
	}
	sort(a, a+n);
	for (int i=0; i<n/2; i++) {
		cout << a[i].second << ' ' << a[n-i-1].second << '\n';
	}
}