#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <numeric>
#include <iterator>
#include <cstring>
using namespace std;

int n;
int a[5005];
long long z[5005];
long long sol = -1e18;

long long psum(int l, int r) {
	return z[r] - z[l];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> a[i];
	}
	for (int i=1; i<=n; i++) {
		z[i] = z[i-1] + a[i-1];
	}
	int xx=0, yy=0, zz=0;
	for (int y=0; y<=n; y++) {
		long long s1 = -1e18, s2 = -1e18;
		int xxx=0, zzz=0;
		for (int x=0; x<=y; x++) {
			long long v = psum(0, x) - psum(x, y);
			if (v > s1) {
				s1 = v;
				xxx = x;
			}
		}
		for (int z=y; z<=n; z++) {
			long long v = psum(y, z) - psum(z, n);
			if (v > s2) {
				s2 = v;
				zzz = z;
			}
		}
		if (s1 + s2 > sol) {
			sol = s1 + s2;
			xx = xxx;
			yy = y;
			zz = zzz;
		}
	}
	cout << xx << ' ' << yy << ' ' << zz << '\n';
}