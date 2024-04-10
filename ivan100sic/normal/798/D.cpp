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

int n, k;
int a[100005], b[100005];

void ans(int j) {
	cout << k << '\n';
	for (int i=0; i<k; i++) {
		cout << ((i+j) % n + 1) << ' ';
	}
	exit(0);
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
	for (int i=0; i<n; i++) {
		cin >> b[i];
	}

	k = n/2 + 1;
	long long an = accumulate(a, a+n, 0ll);
	long long bn = accumulate(b, b+n, 0ll);
	long long ak = accumulate(a, a+k, 0ll);
	long long bk = accumulate(b, b+k, 0ll);

	for (int i=0; i<n; i++) {
		if (2*ak > an && 2*bk > bn) {
			ans(i);
		}

		ak -= a[i];
		bk -= b[i];
		ak += a[(i+k) % n];
		bk += b[(i+k) % n];
	}
}