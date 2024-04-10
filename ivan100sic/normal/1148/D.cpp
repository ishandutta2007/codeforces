#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
int a[300005], b[300005];

basic_string<int> rising, falling;

bool cmp_rising(int x, int y) {
	return a[x] > a[y];
}

bool cmp_falling(int x, int y) {
	return b[x] < b[y];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=1; i<=n; i++) {
		cin >> a[i] >> b[i];
		if (a[i] > b[i])
			falling += i;
		else
			rising += i;
	}
	if (rising.size() > falling.size()) {
		sort(rising.begin(), rising.end(), cmp_rising);
		cout << rising.size() << '\n';
		for (int x : rising)
			cout << x << ' ';
		cout << '\n';
	} else {
		sort(falling.begin(), falling.end(), cmp_falling);
		cout << falling.size() << '\n';
		for (int x : falling)
			cout << x << ' ';
		cout << '\n';
	}
}