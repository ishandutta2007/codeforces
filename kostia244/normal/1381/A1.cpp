#pragma GCC optimize("O2,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,ssse3")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
const int maxn = 1<<20, mod = 1e9 + 7;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
int n;
string a, b;
vector<int> op;
void solve() {
	cin >> n >> a >> b;
	for(auto &i : a) i -= '0';
	for(auto &i : b) i -= '0';
	int l = 0, r = n-1, t = 0;
	op.clear();
	for(int i = n-1; i >= 0; i--) {
		if((a[l]^t) == b[i]) {
			op.push_back(1);
		}
		op.push_back(i+1), t ^= 1;
		swap(l, r);
		if(r > l) r--;
		else r++;
	}
	assert(op.size() <= 2*n);
	cout << op.size() << " ";
	for(auto i : op) cout << i << " "; cout << endl;
}
signed main() {
	cin.tie(0)->sync_with_stdio(0);
	int t;
	cin >> t;
	while(t--) solve();
}