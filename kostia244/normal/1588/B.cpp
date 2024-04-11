// Problem: B. Guess the Permutation
// Contest: Codeforces - Codeforces Round #755 (Div. 1, based on Technocup 2022 Elimination Round 2)
// URL: https://codeforces.com/contest/1588/problem/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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
const int local = 0;
vector<int> _a{-1, 1, 2, 4, 3, 6, 5};
int main() {
	cin.tie(0)->sync_with_stdio(0);
	multitest([&](){
		ll n;
		if(!local)
		cin >> n;
		else
		n = _a.size()-1;
		auto ask = [&](int i, int j) {
			cout << "? " << i << " " << j << endl;
			ll t;
			if(!local)
			cin >> t;
			else {
				t = 0;
				for(int x = i; x <= j; x++)
					for(int y = i; y < x; y++)
						t += _a[y] > _a[x];
			}
			if(t == -1) exit(0);
			return t;
		};
		ll targ = ask(1, n);
		int pos = 0;
		for(int z = 1<<30; z>>=1;)
			if(pos+z < n && ask(1, pos+z)!=targ)
				pos+=z;
		ll L2 = targ-ask(1, pos)+1;
		targ -= L2*(L2-1)/2;
		ll L1 = 0;
		for(ll z = 1ll<<30; z>>=1;)
			if((L1+z)*(L1+z-1)/2 <= targ)
				L1 += z;
		assert(targ == L1*(L1-1)/2);
		ll k = pos+1, j = k-L2+1, i = j-L1;
		cout<< "! " << i << " " << j << " " << k << endl;
		if(local) exit(0);
	});
	
}