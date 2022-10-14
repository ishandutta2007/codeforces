#pragma GCC optimize("O2,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2")
#include<bits/stdc++.h>
#define all(x) begin(x), end(x)
using namespace std;
using ll = long long;
const int maxn = 1<<18, mod = 998244353;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t;
	cin >> t;
	int n;
	while(t--) {
		cin >> n;
		vector<int> a(n), l(n), r(n), v(n);
		for(auto &i : a) cin >> i, --i;
		vector<int> st;
		for(int i = 0; i < n; i++) {
			while(!st.empty() && a[st.back()] >= a[i]) st.pop_back();
			l[i] = st.empty() ? -1 : st.back();
			st.push_back(i);
		}
		st.clear();
		for(int i = n; i--;) {
			while(!st.empty() && a[st.back()] >= a[i]) st.pop_back();
			r[i] = st.empty() ? n : st.back();
			st.push_back(i);
		}
		for(int i = 0; i < n; i++) {
			v[a[i]] = max(v[a[i]], r[i]-l[i]-1);
		}
		for(int i = 1; i < n; i++) v[i] = min(v[i], v[i-1]);
		for(int i = 1; i <= n; i++) {
			cout << (v[n-i]>=i);
		}
		cout << '\n';
	}
}