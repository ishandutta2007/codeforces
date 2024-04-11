#pragma GCC optimize("trapv")
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
#include<bits/extc++.h>
using namespace __gnu_pbds;
//using namespace __gnu_cxx;
#define pb push_back
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
using vi = vector<int>;
using pi = pair<ll, ll>;
using vpi = vector<pi>;
const int maxn = 3e5 + 33, mlg = 18, mod = 1e9 + 7;
vi a[2];
int n;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	int t;
	while(n--) {
		cin >> t;
		a[t&1].pb(t);
	}
	sort(all(a[0]));
	sort(all(a[1]));
	if(a[0].size() < a[1].size()) swap(a[0], a[1]);
	ll ans = 0;
	for(int i = 0; i < (int)a[0].size()-(int)a[1].size()-1; i++)
		ans += a[0][i];
	cout << ans;
}