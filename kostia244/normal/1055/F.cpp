// Problem: F. Tree and XOR
// Contest: Codeforces - Mail.Ru Cup 2018 Round 2
// URL: https://codeforces.com/contest/1055/problem/F
// Memory Limit: 256 MB
// Time Limit: 4000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2")
#include<bits/stdc++.h>
#define all(x) begin(x), end(x)
using namespace std;
using ll = long long;

template<typename F>
void multitest(F func) {
	int t;
	cin >> t;
	while(t--) func();
}
void report(int ok) {
	cout << (ok?"YES":"NO") << '\n';
}
const int N = 1<<20;
using view = array<array<int, 2>, 2>;
ll k, xr[N];
int n;
bool empty(array<int, 2> x) {
	return x[0] >= x[1];
}
view split(array<int, 2> x, int bit) {
	if(empty(x)) return {x, x};
	ll R = (xr[x[0]]>>(bit+1))<<(bit+1);
	R |= 1ll<<bit;
	int m = lower_bound(xr+x[0], xr+x[1], R)-xr;
	//cout << x[0] << " " << x[1] << " " << R << " " << xr[1] << " _ " << m << endl;
	return view{x[0], m, m, x[1]};
}
ll len(array<int, 2> a) {
	return max(0, a[1]-a[0]);
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	//multitest([&](){});
	cin >> n >> k;k--;
	for(int t, i = 2; i <= n; i++) {
		cin >> t >> xr[i];
		xr[i] ^= xr[t];
	}
	sort(xr+1, xr+n+1);
	vector<view> A = {{1, n+1}, {-1, -1}};
	ll res = 0;
	for(int bit = 62; bit--;) {
		vector<view> S;
		S.reserve(2*A.size());
		ll zeroes = 0;
		if(!res) {
			for(auto i : A) {
				auto [A, B] = split(i[0], bit);
				zeroes += len(A)*len(A) + len(B)*len(B);
			}
		} else {
			for(auto [F, G] : A) {
				auto [X, Y] = split(F, bit);
				auto [U, V] = split(G, bit);
				zeroes += 2*len(X)*len(U) + 2*len(Y)*len(V);
			}
		}
		if(k >= zeroes) {
			k -= zeroes;
			res |= 1ll<<bit;
		}
		if(res>>(bit+1)) {
			for(auto [F, G] : A) {
				auto [X, Y] = split(F, bit);
				auto [U, V] = split(G, bit);
				S.push_back({X, (res>>bit)&1 ? V : U});
				if((empty(S.back()[0]) || empty(S.back()[1]))) S.pop_back();
				S.push_back({Y, (res>>bit)&1 ? U : V});	
				if((empty(S.back()[0]) || empty(S.back()[1]))) S.pop_back();
			}
		} else {
			if(res>>bit) {
				for(auto i : A) {
					auto [A, B] = split(i[0], bit);
					if(!empty(A)&&!empty(B))
					S.push_back({A, B});
				}
			} else {
				for(auto i : A) {
					auto [A, B] = split(i[0], bit);
					if(!empty(A))
					S.push_back({A, {-1, -1}});
					if(!empty(B))
					S.push_back({B, {-1, -1}});
				}
			}
		}
		//cout << bit << " " << zeroes << " | " << res << endl;
		A.swap(S);
		//for(auto i : A) cout << i[0][0] << " to " << i[0][1] << " | " << i[1][0] << " to " << i[1][1] << endl;
	}
	cout << res << '\n';
}