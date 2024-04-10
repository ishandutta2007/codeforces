#include <bits/stdc++.h>
using namespace std;

long long k;

int aa[1005], bb[1005], apts[1005], bpts[1005];
int a[4][4], b[4][4];

int len, repeat;

bool good(int x, int y) {
	if (x == 3 && y == 2) {
		return true;
	}
	if (x == 2 && y == 1) {
		return true;
	}
	if (x == 1 && y == 3) {
		return true;
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> k >> aa[0] >> bb[0];

	for (int i=1; i<=3; i++) {
		for (int j=1; j<=3; j++) {
			cin >> a[i][j];
		}
	}

	for (int i=1; i<=3; i++) {
		for (int j=1; j<=3; j++) {
			cin >> b[i][j];
		}
	}

	bool dblbrk = false;

	for (int i=1; 1; i++) {
		aa[i] = a[aa[i-1]][bb[i-1]];
		bb[i] = b[aa[i-1]][bb[i-1]];

		cerr << aa[i] << ' ' << bb[i] << '\n';

		for (int j=0; j<i; j++) {
			if (aa[i] == aa[j] && bb[i] == bb[j]) {
				len = i - j;
				repeat = j;
				dblbrk = true;
				break;
			}
		}

		if (dblbrk) {
			break;
		}
	}

	cerr << "len: " << len << '\n';
	cerr << "repeat: " << repeat << '\n';

	
	for (int i=1; i<=len+repeat; i++) {
		apts[i] = apts[i-1] + (good(aa[i-1], bb[i-1]) ? 1 : 0);
		bpts[i] = bpts[i-1] + (good(bb[i-1], aa[i-1]) ? 1 : 0);
	}

	if (k <= len+repeat) {
		cout << apts[k] << ' ' << bpts[k] << '\n';
		return 0;
	}

	long long q = (k - repeat) / len;
	long long r = (k - repeat) % len;

	cout << q * (apts[repeat + len] - apts[repeat]) + apts[repeat + r] << ' ';
	cout << q * (bpts[repeat + len] - bpts[repeat]) + bpts[repeat + r] << ' ';
	


}