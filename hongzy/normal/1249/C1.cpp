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
ull a[N];
ull qpow(ull a, ull b) {
	ull ans = 1;
	for(; b >= 1; b >>= 1, a = a * a)
		if(b & 1) ans = ans * a;
	return ans;
}
int main() {
	ucin();
	int q; cin >> q;
	while(q --) {
		ull n; cin >> n; int l = 0, r = -1;
		a[0] = 0; ll nn = n;
		while(n) {
			a[++ l] = n % 3; n /= 3;
			if(a[l] == 2) r = l;
		}
		a[l + 1] = 0;
		if(r == -1) cout << nn << endl;
		else {
			for(int i = r + 1; i <= l + 1; i ++) {
				if(!a[i]) {
					a[i] = 1;
					for(int j = i - 1; j >= 1; j --)
						a[j] = 0;
					break ;
				}
			}
			ull ans = 0, base = 1;
			for(int i = 1; i <= l + 1; i ++) {
				if(a[i]) {
					ans += base;
				}
				base *= 3;
			}
			cout << ans << endl;
		}
	}
	return 0;
}