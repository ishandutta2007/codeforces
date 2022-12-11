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
int a[N], p[N];
int main() {
	ucin();
	int t; cin >> t;
	while(t --) {
		int n; cin >> n;
		for(int i = 1; i <= n; i ++) cin >> a[i];
		fill(p + 1, p + n + 1, 0);
		int ans = N;
		for(int i = 1; i <= n; i ++) {
			if(p[a[i]]) ans = min(ans, i - p[a[i]] + 1);
			p[a[i]] = i;
		}
		if(ans == N) ans = -1;
		cout << ans << endl;
	}
	return 0;
}