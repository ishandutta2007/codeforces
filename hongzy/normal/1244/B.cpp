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
		int n; cin >> n;
		static char s[N]; cin >> s + 1;
		bool t = 0; int l = n + 1, r = 0, cnt = 0;
		for(int i = 1; i <= n; i ++) {
			if(s[i] == '1') {
				t = 1; l = min(l, i); r = max(r, i); cnt ++;
			}
		}
		int ans = 2 * max(max(l, r), max(n - l + 1, n - r + 1));
		ans = max(ans, n + cnt);
		if(!t) cout << n << endl;
		else cout << ans << endl;
	}
	return 0;
}