#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <cmath>
#include <numeric>
#include <cstdlib>
#include <cstring>
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
	int osam = count(s.begin(), s.end(), '8');
	cout << min(osam, n / 11);
}

int main() {
	solve();
#ifdef _MSVC_STL_VERSION
	system("pause");
#endif
}