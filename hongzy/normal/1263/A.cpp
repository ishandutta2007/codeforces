#include <bits/stdc++.h>
using namespace std;
#define fs first
#define sc second
#define mp make_pair
#define pb push_back
#define ucin() ios :: sync_with_stdio(0)
typedef vector<int> vi;
typedef map<int, int> mii;
typedef pair<int, int> pii;
typedef unsigned long long ull;
typedef long double ld;
typedef long long ll;
typedef double db;

const int N = 1e5 + 10;

int main() {
	ucin();
	int t; cin >> t;
	while(t --) {
		int ans = 0, x, a[3];
		cin >> a[0] >> a[1] >> a[2];
		sort(a, a + 3);
		ans = (x = (a[1] - a[0])); a[1] -= x; a[2] -= x;
		ans += max(0, a[0] - (a[2] + 1) / 2);
		cout << ans + min(a[2], a[0] << 1) << endl;
	}
	return 0;
}