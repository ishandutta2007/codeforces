#pragma GCC optimize("O2,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,ssse3")
#include<bits/stdc++.h>
#define int long long
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
const int maxn = 5050;
int mod = 1e9 + 7;
int n, k, a, b, c, d, o = -1;
signed main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> k >> a >> b >> c >> d;
	if(n < 5 || k < n+1) return cout << "-1\n", 0;
	vector<int> f;
	for(int i = 1; i <= n; i++) {
		if(i == a || i == b || i == c || i == d) continue;
		if(o == -1) {o = i; continue;}
		f.push_back(i);
	}
	cout << a << " " << d << " " << o << " " << c << " ";
	for(auto i : f) cout << i << " ";
	cout << b << endl;
	cout << c << " ";
	for(auto i : f) cout << i << " ";
	cout << b << " " << o << " " << a << " " << d << endl;
}