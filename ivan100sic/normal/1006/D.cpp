#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
string a, b;

bool np(vector<char> v) {
	sort(v.begin(), v.end());
	return v[0] == v[1] && v[2] == v[3];
}

int br(vector<char> v) {
	// 0 promena
	if (np(v))
		return 0;

	for (int i=0; i<2; i++) {
		char t = v[i];
		v[i] = v[2];
		if (np(v))
			return 1;
		v[i] = v[3];
		if (np(v))
			return 1;
		v[i] = v[1-i];
		if (np(v))
			return 1;
		v[i] = t;
	}

	return 2;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> a >> b;
	int c = 0;
	for (int i=0; i<n; i++) {
		int j = n-i-1;
		if (i > j)
			break;
		else if (j == i) {
			c += a[i] != b[i];
			break;
		} else {
			int v = br({a[i], a[j], b[i], b[j]});
			// cerr << i << ' ' << v << '\n';
			c += v;
		}
	}
	cout << c << '\n';
}