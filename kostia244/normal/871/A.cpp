#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,ssse3,tune=native")
#include<bits/stdc++.h>
using namespace std;
using ld = long double;
using vec = complex<ld>;
void solve() {
	int a;
	cin >> a;
	if(a<4||a==5||a==7||a==11) {
		cout << "-1\n";
		return;
	}
	if(a%4==0) {
		cout << a/4 << "\n";
	} else if(a%4==1) {
		cout << a/4 - 1 << "\n";
	}else if(a%4==2) {
		cout << a/4 << "\n";
	} else if(a%4==3) {
		cout << a/4 - 1 << "\n";
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--) solve();
}