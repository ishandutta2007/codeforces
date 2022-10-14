//#pragma GCC optimize("O2")
//#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
using ll = long long;
using vi = vector<ll>;
const int maxn = 100003;
using ld = long double;
int n;
vi a, b;
map<pair<int, int>, int> m;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	a.resize(n);
	for(auto &i : a) cin >> i;
	b.resize(n);
	for(auto &i : b) cin >> i;
	int l = 0;
	for(int g, i = 0; i < n; i++) {
		if(a[i]) {
		g = __gcd(a[i], b[i]);
		a[i]/=g, b[i]/=g;
		b[i]*=-1;
		if(a[i]<0) a[i] = -a[i], b[i] = -b[i];
		m[{a[i], b[i]}]++;
		} else if(b[i]==0)
			l++;
//		cout << a[i] << " " << b[i] << " " << g << "\n";
	}
	int ans = 0;
	for(auto i : m) ans = max(ans, i.second);
	cout << ans+l;
}