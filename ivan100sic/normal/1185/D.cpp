#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
pair<int, int> a[200005];

void probaj(int i) {
	basic_string<int> b;
	for (int j=0; j<n; j++)
		if (j != i)
			b += a[j].first;
	for (int i=2; i<n-1; i++) {
		if (b[i] - b[i-1] != b[1] - b[0]) {
			return;
		}
	}
	cout << a[i].second << '\n';
	exit(0);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> a[i].first;
		a[i].second = i+1;
	}
	sort(a, a+n);
	for (int i=1; i<n-1; i++) {
		if (a[i].first - a[i-1].first != a[i+1].first - a[i].first) {
			probaj(i-1);
			probaj(i);
			probaj(i+1);
			cout << "-1\n";
			return 0;
		}
	}
	probaj(0);
}