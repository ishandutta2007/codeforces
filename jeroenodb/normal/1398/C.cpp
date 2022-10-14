#include <iostream>
#include <bitset>
#include <string>
#include <cstring>
using namespace std;
#define D(a) \
    do { cout << #a ": " << (a) << ' '; } while(false)

const int mxN = 1e6 + 1;

int n, a[mxN] = {};

int main() {
	int t;
	cin >> t;

	while (t--) {
		long long ans = 0;

		cin >> n;
		memset(a, 0,sizeof(int) * (10*n+1));
		a[n] = 1;
		int prefsum = 0;
		for (int i = 1; i <= n; ++i) {
			char c; cin >> c;
			prefsum += (c - '0');
			ans += a[prefsum - i + n]++;
		}
		cout << ans << endl;
	}
}