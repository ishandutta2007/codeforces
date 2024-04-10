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

int main() {
	ucin();
	ll n, p, a, b, g, x, y;
	cin >> n >> p >> a >> b;
	if(p == 0) {
		cout << 0 << ' ' << 0 << ' ' << n << endl;
		return 0;
	}
	for(ll v = 0; v <= a; v ++) {
		if((p - b * v) % a == 0) {
			ll u = (p - b * v) / a;
			if(u >= 0 && u <= n && u + v <= n && u + v >= 0) {
				cout << u << ' ' << v << ' ' << n - u - v << endl;
				return 0;
			}
		}
	}
	cout << -1 << endl;
	return 0;
}