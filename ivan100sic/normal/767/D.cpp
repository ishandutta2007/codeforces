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

int n, m, k;
int f[1000005];
int s[1000005];

int sorig[1000005];

int t[2000005];

map<int, int> govno;

bool check(int q) {
	int j = 1, i = 0;
	while (j <= q) {
		if (t[j] < i) {
			return false;
		} else {
			j += k;
			i++;
		}
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m >> k;
	for (int i=1; i<=n; i++) {
		cin >> f[i];
	}
	for (int i=1; i<=m; i++) {
		cin >> s[i];
		sorig[i] = s[i];
	}

	sort(f+1, f+n+1);
	sort(s+1, s+m+1);

	int l = 0, r = m, o = -1;

	while (l <= r) {
		int mid = (l+r) / 2;
		merge(f+1, f+n+1, s+m-mid+1, s+m+1, t+1);
		if (check(n+mid)) {
			o = mid;
			l = mid+1;
		} else {
			r = mid-1;
		}
	}

	cout << o << '\n';
	if (o > 0) {
		for (int i=m-o+1; i<=m; i++) {
			govno[s[i]]++;
		}

		for (int i=1; i<=m; i++) {
			if (govno[sorig[i]] > 0) {
				govno[sorig[i]]--;
				cout << i << ' ';
			}
		}
	}
}