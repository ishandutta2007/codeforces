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

ll ans, p[1000010], cnt, n;
int main() {
	ucin();
	cin >> n;
	if(n == 1) {
		cout << 1 << endl;
		return 0;
	}
	for(ll i = 2; i * i <= n; i ++) {
		if(n % i == 0) {
			p[++ cnt] = i;
			while(n % i == 0) n /= i;
		}
	}
	if(n > 1) p[++ cnt] = n;
	cout << (cnt == 1 ? p[1] : 1) << endl;
	return 0;
}