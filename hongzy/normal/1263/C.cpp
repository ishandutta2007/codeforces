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

int main() {
	ucin();
	int t; cin >> t;
	while(t --) {
		int n; cin >> n;
		static int ans[N]; int len = 0;
		ans[++ len] = 0;
		for(int l = 1, r; l <= n; l = r + 1) {
			ans[++ len] = n / l;
			r = n / (n / l);
		}
		cout << len << endl; reverse(ans + 2, ans + len + 1);
		for(int i = 1; i <= len; i ++)
			cout << ans[i] << ' ';
		cout << endl;
	}
	return 0;
}