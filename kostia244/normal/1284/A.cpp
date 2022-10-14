//#pragma GCC optimize("trapv")
//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma")
//#pragma GCC optimize("unroll-loops")
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
const int maxn = 88, mod = 1e9 + 7;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n >> m;
	vector<string> a, b;
	a.resize(n);
	for(auto &i : a) cin >> i;
	b.resize(m);
	for(auto &i : b) cin >> i;
	int q, t;
	cin >> q;
	while(q--) {
		cin >> t, t--;
		cout << a[t%n] << b[t%m] << "\n";
	}
}