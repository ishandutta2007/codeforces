#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <numeric>
#include <iterator>
using namespace std;

int a[105];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int n, sol=-100;
	cin >> n;
	for (int i=1; i<=n; i++) {
		cin >> a[i];
	}

	for (int i=1; i<=n; i++) {
		int c0=0, c1=0;
		for (int j=i; j<=n; j++) {
			if (a[j] == 0) {
				c0++;
			} else {
				c1++;
			}
			sol = max(sol, c0-c1);
		}
	}

	cout << sol + accumulate(a+1, a+n+1, 0);
}