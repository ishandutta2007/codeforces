#include <bits/stdc++.h>
using namespace std;

int baza[100005];
int n, k;

int a[100005];

bool generisi(int l, int r, int k) {
	if (k > baza[r-l]) {
		return false;
	}

	if (r-l == 1) {
		return k == 1;
	}

	if (k == 1) {
		for (int i=l; i<r; i++) {
			a[i] = i-l;
		}
		return true;
	}

	if (k % 2 == 0) {
		return false;
	}
	
	int mid = (l + r) / 2;
	k--;

	int kl=1, kr=1;
	bool ok = false;

	for (kl=1; kl<=baza[mid-l]; kl+=2) {
		kr = k - kl;
		if (kr <= baza[r-mid]) {
			ok = true;
			break;
		}
	}

	if (!ok) {
		return false;
	}

	bool flag1 = generisi(l, mid, kl);
	bool flag2 = generisi(mid, r, kr);

	if (!flag1 || !flag2) {
		return false;
	}

	for (int i=l; i<mid; i++) {
		a[i] += r - mid;
	}

	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> k;
	baza[1] = 1;
	for (int i=2; i<=n; i++) {
		baza[i] = 1 + baza[i / 2] + baza[i - i / 2];
	}

	if (generisi(0, n, k)) {
		for (int i=0; i<n; i++) {
			cout << a[i]+1 << ' ';
		}
	} else {
		cout << -1;
	}
}