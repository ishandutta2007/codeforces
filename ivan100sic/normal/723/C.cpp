#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, m, tgt;
int a[2005], b[2005];
basic_string<int> bad, okay;

int notgt() {
	for (int i=1; i<=m; i++) {
		if (b[i] < tgt) {
			return i;
		}
	}
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m;
	for (int i=1; i<=n; i++) {
		cin >> a[i];
		if (a[i] > m)
			bad += i;
		else
			b[a[i]]++;
	}
	tgt = n/m;
	int ch = 0;

	for (int i=1; i<=m; i++) {
		int x = b[i] - tgt;
		for (int j=1; j<=n; j++) {
			if (x > 0 && a[j] == i) {
				okay += j;
				x--;
			}
		}
	}

	bad = okay + bad;

	while (1) {
		int i = notgt();
		if (i == 0)
			break;
		int x = bad.back();
		bad.pop_back();
		a[x] = i;
		b[i]++;
		ch++;
	}

	cout << tgt << ' ' << ch << "\n";
	for (int i=1; i<=n; i++)
		cout << a[i] << ' ';
	cout << '\n';

}