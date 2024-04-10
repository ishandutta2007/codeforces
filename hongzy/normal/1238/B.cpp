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

const int N = 2e5 + 10;
int a[N];
int main() {
	ucin();
	int q; cin >> q;
	while(q --) {
		int n, r; cin >> n >> r; a[0] = 0;
		for(int i = 1; i <= n; i ++) cin >> a[i];
		sort(a + 1, a + n + 1);
		n = unique(a + 1, a + n + 1) - a - 1;
		ll ans = n;
		for(int i = n; i >= 0; i --) {
			ll w = a[i] - 1ll * r * (n - i);
			ll cur = (n - i) + (w <= 0 ? 0 : ((w + r - 1) / r));
			if(cur < ans) ans = cur;
		}
		cout << ans << endl;
	}
	return 0;
}