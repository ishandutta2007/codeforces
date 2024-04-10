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
	int T; cin >> T;
	while(T --) {
		ll x, y;
		cin >> x >> y;
		cout << (x - 1 == y ? "NO" : "YES") << endl;
	}
	return 0;
}