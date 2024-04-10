#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <numeric>
#include <iterator>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int n, s=0;
	cin >> n;
	int mp = 1e9;

	for (int i=1; i<=n; i++) {
		int a, p;
		cin >> a >> p;
		mp = min(p, mp);
		s += a*mp;
	}

	cout << s;
}