#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,ssse3,tune=native")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
using ll = long long;
//using arr = array;
using pi = pair<ll, ll>;
using vi = vector<ll>;
using vpi = vector<pi>;
using ld = long double;
#include<bits/extc++.h>
using namespace __gnu_pbds;
using oset = tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>;
const int maxn = 404, mod = (119<<23)+1, lg = 19;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int a[3][3], k;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> k;
	a[0][1] = 131072;
	a[1][0] = k;
	a[0][0] = 262143;
	a[1][1] = 262143;
	a[1][2] = 262143;
	a[2][1] = 262143;
	a[2][2] = 131071;
	cout << "3 3\n";
	for(int i = 0; i < 3; i++, cout << '\n')
		for(int j = 0; j < 3; j++)
			cout << a[i][j] << ' ';
	return 0;
}