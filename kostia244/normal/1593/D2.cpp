// Problem: D2. Half of Same
// Contest: Codeforces - Codeforces Round #748 (Div. 3)
// URL: https://codeforces.com/contest/1593/problem/D2?locale=en
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
int a[44], b[44], n;
int main() {
	cin.tie(0)->sync_with_stdio(0);
	multitest([&](){
		cin >> n;
		for(int i = 0; i < n; i++)
			cin >> a[i];
		int z;
		for(z = 2000001; z; z--) {
			for(int i = 0; i < n; i++) {
				b[i] = a[i]%z;
				if(b[i] < 0) b[i] += z;
			}
			int val = -1, cnt = 0;
			for(int i = 0; i < n; i++)
				cnt += b[i] == b[n-1];
			if(2*cnt >= n) break;
			val = -1, cnt = 0;
			for(int i = 0; i < n-(n%2==0); i++) {
				if(val == b[i]) cnt++;
				else cnt--;
				if(cnt < 0) val = b[i], cnt = 1;
			}
			cnt = 0;
			for(int i = 0; i < n; i++)
				cnt += b[i] == val;
			if(2*cnt >= n) {
				break;
			}
		}
		if(z == 2000001) z = -1;
		cout << z << '\n';
	});
	
}