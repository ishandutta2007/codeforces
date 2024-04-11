// Problem: F. Bingo
// Contest: Codeforces - Codeforces Round #733 (Div. 1 + Div. 2, based on VK Cup 2021 - Elimination (Engine))
// URL: https://codeforces.com/contest/1530/problem/F
// Memory Limit: 512 MB
// Time Limit: 7000 ms
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
const int N = 21, mod = 31607;
int a[N][N], b[N][N], n;
__attribute__(( always_inline ))  inline void M(int &v, int i, int j) {
	uint32_t q = (v * 1u * b[i][j]) >> 16;
	v = v*a[i][j] - mod * q;
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	//multitest([&](){});
	cin >> n;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++) {
			cin >> a[i][j], a[i][j] = a[i][j]*3973%mod;
			b[i][j] = (a[i][j]<<16)/mod;
		}
	int MD = 1, AD = 1, MAD = 1;
	for(int i = 0; i < n; i++) {
		MD = MD*a[i][i]%mod;
		//cout << a[i][i] << " " << MD << ", ";
		AD = AD*a[i][n-i-1]%mod;
		MAD = MAD*a[i][i]%mod;
		if(i != n-i-1)
		MAD = MAD*a[i][n-i-1]%mod;
	}
	int ans = 0;
	//cout << MD << "and  " << AD << endl;
	for(int A = 0; A < 4; A++) {
		for(int msk = 0; msk < 1<<n; msk++) {
			int mul = 1;
			if(A==1) mul = MD;
			if(A==2) mul = AD;
			if(A==3) mul = MAD;
			int cur = 1;
			vector<int> v(n, 1);
			for(int i = 0; i < n; i++) {
					if((msk>>i)&1) {
						for(int j = 0; j < n; j++) {
							if(i == j && (A&1)) continue;
							if(j == n-i-1 && (A&2)) continue;
							M(mul, i, j);
						}
					} else {
						for(int j = 0; j < n; j++) {
							if(i == j && (A&1)) continue;
							if(j == n-i-1 && (A&2)) continue;
							M(v[j], i, j);
						}
					}
				//if(!((msk>>i)&1))
				//	cur = cur*(mod+1-v)%mod;
			}//
			for(auto i : v) cur = cur*(mod+1-i)%mod;
			if(0 && cur && mul){
				cout << A << " " << msk << " : " << endl;
				cout << cur << " _ " << mul << endl;
				}
			ans = (ans+cur*mul*1ll*((__builtin_popcount(msk)+__builtin_popcount(A))%2 ? mod-1 : 1))%mod;
		}
	}
	//a*(
	cout << (mod+1-ans)%mod << endl;
}