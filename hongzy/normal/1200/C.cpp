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

const int N = 1010;

int main() {
	ucin();
	ll n, m, q;
	cin >> n >> m >> q;
	ll sn = n / __gcd(n, m), sm = m / __gcd(n, m);
	for(int i = 1; i <= q; i ++) {
		ll sx, sy, ex, ey;
		cin >> sx >> sy >> ex >> ey;
		ll g1 = -1, g2 = 0;
		if(sx == 1) g1 = (sy + sn - 1) / sn;
		else g1 = (sy + sm - 1) / sm;
		if(ex == 1) g2 = (ey + sn - 1) / sn;
		else g2 = (ey + sm - 1) / sm;
		puts(g1 == g2 ? "YES" : "NO");
	}
	return 0;
}