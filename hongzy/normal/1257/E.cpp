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
int k1, k2, k3, n;
int a[3][N], pre[N], suf[N], s[N];
int main() {
	ucin(); cin >> k1 >> k2 >> k3; n = k1 + k2 + k3;
	for(int i = 1; i <= k1; i ++) cin >> a[0][i], suf[a[0][i]] = 1;
	for(int i = 1; i <= k2; i ++) cin >> a[1][i], s[a[1][i]] = 1;
	for(int i = 1; i <= k3; i ++) cin >> a[2][i], pre[a[2][i]] = 1;
	for(int i = 1; i <= n + 1; i ++) pre[i] += pre[i - 1], s[i] += s[i - 1];
	for(int i = n; i >= 0; i --) suf[i] += suf[i + 1];
	int ans = min(n - k1, min(n - k2, n - k3));
	int Min = min(suf[0], suf[1]);
	for(int r = 1; r <= n + 1; r ++) {
		if(r != n) Min = min(Min, suf[r + 1] + s[r]);
		ans = min(ans, Min + k2 + pre[r] - s[r]);
	}
	cout << ans << endl; return 0;
}