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
		int a, b;
		cin >> a >> b;
		set<int> cn;
		int A = (a+b+1)/2;
		int B = a+b-A;
		for(int I = 0; I < 2; I++, swap(a, b)) {
			//Alice starts
			for(int br = 0; br <= min(B, a); br++) {
				int left = a-br;
				if(left > A) continue;
				cn.insert(br+A-left);
			}
		}
		cout << cn.size() << '\n';
		for(auto i : cn) cout << i << " "; cout << '\n';
	});
	
}