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
	map<int, int> cnt;
	while(n--) {
		cin >> t;
		cnt[t]++;
		if(cnt[t]==1)
		a[0].pb(t);
		else if(cnt[t]==2)
		a[1].pb(t);
		else
			return cout << "NO", 0;
	}
	sort(all(a[0]));
	sort(all(a[1]));
	reverse(all(a[1]));
	cout << "YES\n";
	for(int k = 0; k < 2; k++) {
		cout << a[k].size() << "\n";
		for(auto i : a[k]) cout << i << " ";
		cout << "\n";
	}
}