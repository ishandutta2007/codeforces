// I've decided to retire from ALL contests
// It's been a nice ride... but I need to move on
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

vector<int> resi(int n, int m) {
	vector<int> a(n);
	iota(begin(a), end(a), 1);

	int mcurr = n % 2 ? (n-1)*(n-1)/4 : n*(n-2)/4;

	int visak = mcurr - m;
	if (visak < 0)
		return {};

	for (int i=n-1; i>=0; i--) {
		int skor = (a[i]-1) / 2;
		if (skor <= visak) {
			// oteraj ga u pm
			a[i] = 321321321 + 6666 * a[i];
			visak -= skor;
		} else {
			a[i] += 2 * visak;
			break;
		}
	}

	return a;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int n, m;
	cin >> n >> m;

	auto a = resi(n, m);
	if (a.size()) {
		for (int x : a)
			cout << x << ' ';
		cout << '\n';
	} else {
		cout << "-1\n";
	}
}

// I will still practice daily...