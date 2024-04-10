// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int c[100005], d[11], pr;

int kl(int k) {
	return min(4, k/2*2);
}

void ad(int x) {
	d[kl(c[x])]--;
	pr -= c[x] / 2;
	c[x]++;
	d[kl(c[x])]++;
	pr += c[x] / 2;
}

void rm(int x) {
	d[kl(c[x])]--;
	pr -= c[x] / 2;
	c[x]--;
	d[kl(c[x])]++;
	pr += c[x] / 2;
}

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	int n;
	cin >> n;
	while (n--) {
		int x;
		cin >> x;
		ad(x);
	}

	int q;
	cin >> q;
	while (q--) {
		string s;
		cin >> s;

		int x;
		cin >> x;

		if (s == "+") {
			ad(x);
		} else {
			rm(x);
		}

		if (d[4] && pr >= 4) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}
}