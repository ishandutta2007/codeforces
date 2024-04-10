#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <cmath>
#include <complex>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

void solve() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	string s;
	cin >> n >> s;
	if (s == "0") {
		cout << 0;
	}
	else {
		int c = count(s.begin(), s.end(), '0');
		cout << 1 << string(c, '0');
	}
}

int main() {
	solve();
#ifdef _MSVC_STL_VERSION
	system("pause");
#endif
}