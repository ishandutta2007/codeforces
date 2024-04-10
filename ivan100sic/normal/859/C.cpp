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
int dp_token[55], dp_bez[55];
int a[55];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=1; i<=n; i++) {
		cin >> a[i];
	}

	for (int i=n; i>=1; i--) {
		// biram
		dp_token[i] = max(dp_token[i+1], dp_bez[i+1] + a[i]);

		// ne biram
		dp_bez[i] = accumulate(a+i, a+n+1, 0) - dp_token[i];
	}

	cout << dp_bez[1] << ' ' << dp_token[1] << '\n';
}