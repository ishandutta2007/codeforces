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
const int N = 110;
const int M = 1 << 15;
int n, a[N];
map<vi, int> Map;
int main() {
	ucin();
	cin >> n;
	for(int i = 1; i <= n; i ++) cin >> a[i];
	vi vv; 
	for(int x = 0; x < M; x ++) {
		vv.clear();
		int t = __builtin_popcount((a[1] & (M - 1)) ^ x);
		for(int i = 2; i <= n; i ++)
			vv.pb(t - __builtin_popcount((a[i] & (M - 1)) ^ x));
		Map[vv] = x;
	}
	for(int x = 0; x < M; x ++) {
		vv.clear();
		int t = __builtin_popcount(x ^ (a[1] >> 15));
		for(int i = 2; i <= n; i ++)
			vv.pb(__builtin_popcount(x ^ (a[i] >> 15)) - t);
		if(Map.count(vv)) {
			cout << (x << 15 | Map[vv]);
			return 0;
		}
	}
	cout << -1;
	return 0;
}