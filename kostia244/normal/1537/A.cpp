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

int main() {
	cin.tie(0)->sync_with_stdio(0);
	multitest([&](){
		ll n, s = 0, t;
		cin >> n;
		for(int i = 0; i < n; i++)
			cin >> t, s += t;
		if(s > n)
			cout << s-n << '\n';
		else
			cout << (s!=n) << '\n';

	});
	
}