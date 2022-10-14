#pragma GCC optimize("O2")
#pragma GCC target("avx,avx2,sse,fma,tune=native")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
#include<bits/extc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
using namespace __gnu_pbds;
using ll = long long;
using vi = vector<ll>;
using pi = pair<ll, ll>;
const int maxn = 1e5 + 555, mod = (119<<23)+1;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int n;
vi a, b;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	int t;
	char c;
	for(int i = 0; i < n; i++) {
		cin >> c;
		int t =c;
		auto it = lower_bound(all(b), -t);
		if(it==b.end()) a.pb(b.size()), b.pb(-t);
		else *it = -t, a.pb(it-b.begin());
//		for(auto i : b)
//			cout << i << " ";cout << "\n";
	}
	cout << b.size() << "\n";
	for(int i = 0; i < n; i++) {
		cout << a[i]+1 << " ";
	}
	return 0;
}