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
		int n, x, a, b, ans = 0;
		cin >> n >> x >> a >> b;
		ans = abs(a - b);
		if(a > b) swap(a, b);
		int t = min(x, a - 1); x -= t; ans += t;
		t = min(x, n - b); x -= t; ans += t;
		cout << ans << endl;
	}
	return 0;
}