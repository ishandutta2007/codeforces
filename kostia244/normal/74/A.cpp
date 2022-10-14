//#pragma GCC optimize("O2")
//#pragma GCC target("avx,avx2,sse,fma,tune=native")
//#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
#include<bits/extc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
using ll = long long;
using vi = vector<ll>;
using pi = pair<ll, ll>;
const int maxn = 1e5 + 666, mlg = 18, mod =1e9 + 7;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	vector<pair<int, string>> a;
	string t;
	int n, q;
	cin >> n;
	while(n--) {
		cin >> t;
		ll cur = 0;
		cin >> q;
		cur = q*100;
		cin >> q;
		cur -= q*50;
		for(int i = 0; i < 5; i++) cin >> q, cur += q;
		a.pb({cur, t});
//		cout << q << " " << t << "\n";
	}
	sort(rall(a));
	cout << a[0].second;
	return 0;
}