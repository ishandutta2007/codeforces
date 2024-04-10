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

	long long n, k, z = 1, g=0, q=1;
	cin >> n >> k;

	
	if (n-k < k) {
		k = n-k;
	}
	

	for (long long i=1; i<=n; i++) {
		if (i*k/n != (i-1)*k/n) {
			g = 2;
		}
		if (g > 0) {
			g--;
			q++;
		}
		z += q;
		if (i == n) z--;
		cout << z << ' ';
	}
}