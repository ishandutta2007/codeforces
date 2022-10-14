#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,ssse3,tune=native")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
using ll = long long;
using vi = vector<int>;
using pi = pair<int, int>;
using vpi = vector<pi>;
const int maxn = 1<<21;
const int mod = 998244353, inv2 = (mod+1)/2, rt = 733596141;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	int ans = 0;
	if(n&1) ans += 16;
	if(n&2) ans += 2;
	if(n&4) ans += 8;
	if(n&8) ans += 4;
	if(n&16) ans += 1;
	if(n&32) ans += 32;
	cout << ans;
	
	return 0;
}
// 20998782977