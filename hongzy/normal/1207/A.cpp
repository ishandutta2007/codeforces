#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back
#define fs first
#define sc second
#define ucin() ios :: sync_with_stdio(0)

typedef map<int, int> mii;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef unsigned long long ull;
typedef long long ll;
typedef double db;

const int N = 1e5 + 10;
int main() {
	ucin();
	int t; cin >> t;
	while(t --) {
		int a, x, y, cx, cy;
		cin >> a >> x >> y >> cx >> cy;
		a /= 2;
		if(cx < cy) swap(cx, cy), swap(x, y);
		int q = min(a, x), ans = 0;
		ans += q * cx; a -= q;
		q = max(0, min(a, y));
		ans += q * cy; a -= q;
		cout << ans << endl;
	}
	return 0;
}