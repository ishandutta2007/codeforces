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
void solve() {
	int n;
	cin >> n;
	vi a(n);
	for(auto &i : a) cin >> i;
	set<int> b(all(a));
	if(b.size()==1) {
		cout << "1\n";
		for(int i = 0; i < n; i++) cout << "1 "; cout << '\n';return;
	}
	if(n%2==0||a[0]==a.back()) {
		cout << "2\n";
		for(int i = 0; i < n; i++) cout << 1+(i&1) << " "; cout << '\n';return;
	}
	if(b.size()==2) {
		cout << "2\n";
		for(int i = 0; i < n; i++) cout << 1+(*b.begin() == a[i]) << " "; cout << '\n';return;
	}
	int x = -1;
	for(int i = 1; i < n; i++) if(a[i]==a[i-1]) {x = i;break;}
	if(x!=-1) {
		vi r(n);
		r[x] = 1;
		r[x-1] = 1;
		for(int i = 1; i < n; i++)
			r[(x+i)%n] = r[(x+i-1)%n]^3;
		cout << "2\n";
		for(auto &i : r) cout << i << " ";cout << '\n';
		return;
	}
	vi r;
	for(int i = 0; i < n; i++)
		r.pb(1 + i%3);
	if(r[0] == r.back())
		swap(r[0], r[1]);
	cout << "3\n";
	for(auto &i : r) cout << i << " ";cout << '\n';
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}