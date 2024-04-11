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
void solve() {
	string s;
	int n;
	cin >> n;
	cin >> s;
	for(int i = 0; i < n/2; i++) {
		if(abs(s[i]-s[n-1-i])>2||abs(s[i]-s[n-1-i])==1) {cout << "NO\n"; return;};
	}
	cout << "YES\n";
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--) solve();
}
// 20998782977