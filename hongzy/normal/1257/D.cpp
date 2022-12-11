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
const int N = 4e5 + 10;
int n, m, a[N], suf[N];
int main() {
	ucin();
	int t; cin >> t;
	while(t --) {
		cin >> n;
		for(int i = 1; i <= n; i ++) cin >> a[i];
		cin >> m;
		fill(suf, suf + n + 1, 0);
		for(int i = 1; i <= m; i ++) {
			int x, y; cin >> x >> y; suf[y - 1] = max(suf[y - 1], x);
		}
		for(int i = n - 2; i >= 0; i --) suf[i] = max(suf[i], suf[i + 1]);
		int ans = 0;
		for(int i = 1, j, mx; i <= n; i = j) {
			j = n + 1;
			for(int k = i; k <= n; k ++) {
				mx = k == i ? a[k] : max(mx, a[k]);
				if(suf[k - i] < mx) {
					j = k; break ;
				}
			}
			if(i == j) {
				ans = -1; break ;
			}
			ans ++;
		}
		cout << ans << endl;
	}
	return 0;
}