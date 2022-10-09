// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int a[4], b[4];

set<int> vals() {
	set<int> s;
	for (int m=0; m<8; m++) {
		vector<int> b;
		int z = a[0];
		for (int i=0; i<3; i++) {
			if (m & (1 << i)) {
				z = 10 * z + a[i+1];
			} else {
				b.push_back(z);
				z = a[i+1];
			}
		}
		b.push_back(z);

		int k = b.size();
		for (int g=0; g<(1<<k); g+=2) {
			for (int h=0; h<(1<<k); h++) {
				int z = 0;
				for (int i=0; i<k; i++) {
					if (h & (1 << i)) {
						z += b[i];
					} else if (g & (1 << i)) {
						z *= b[i];
					} else {
						z -= b[i];
					}
				}

				s.insert(z);
			}
		}
	}

	return s;
}

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	int k, m;
	cin >> k >> m;
	for (a[0]=0; a[0]<=9; a[0]++)
	for (a[1]=0; a[1]<=9; a[1]++)
	for (a[2]=0; a[2]<=9; a[2]++)
	for (a[3]=0; a[3]<=9; a[3]++)
	{
		set<int> moz;
		for (int x : vals()) {
			moz.insert(abs(k-x));
			moz.insert(abs(k+x));
		}

		for (int x : moz) {
			if (m > 0 && x < 10000) {
				m--;
				int z = x;
				for (int i=0; i<4; i++) cout << a[i];
				for (int i=0; i<4; i++) {
					b[3-i] = z % 10;
					z /= 10;
				}
				for (int i=0; i<4; i++) cout << b[i];
				cout << '\n';
			}
		}
	}
}