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
ll n, a, b, k, t;
vi v;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> a >> b >> k;
	int ans = 0;
	for(int i = 0; i < n; i++) {
		cin >> t;
		t%=(a+b);
//		cout << t << " ";
		if(t==0) t+=a+b;
		if(t<=a) ans++;
		else {
			t-=a;
			v.pb((t+a-1)/a);
		}
	}
	sort(all(v));
	for(auto i : v)
		if(i<=k)
			k-=i,ans++;//, cout << i << " ";
		else
			break;
	cout << ans;
	return 0;
}