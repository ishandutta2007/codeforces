#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

pair<int, int> a[1005];
int n;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> a[i].first;
		a[i].second = i;
	}
	sort(a, a+n);
	reverse(a, a+n);
	int sol = 0;
	for (int i=0; i<n; i++) {
		sol += a[i].first * i + 1;
	}
	cout << sol << '\n';
	for (int i=0; i<n; i++)
		cout << a[i].second + 1 << " \n"[i == n-1];
}