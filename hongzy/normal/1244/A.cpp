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
		int a, b, c, d, k, ans = 0;
		cin >> a >> b >> c >> d >> k;
		int na = (a + c - 1) / c;
		int nb = (b + d - 1) / d;
		if(na + nb <= k) cout << na << ' ' << nb << endl; 
		else cout << "-1\n";
	}
	return 0;
}