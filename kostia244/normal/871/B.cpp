#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,ssse3,tune=native")
#include<bits/stdc++.h>
using namespace std;
using ld = long double;
using vec = complex<ld>;
const int maxn = 5e3 + 33;
int n, a[maxn], b[maxn], ta[maxn], tb[maxn], c[maxn]; //a^b_0, b^a_0
vector<int> x = {0, 1, 2}, y = {0, 1, 2};
int q(int i, int j) {
	cout << "? " << i << " " << j << endl;
	int t;
	cin >> t;
	return t;
}
int check(int b_0) {
	int a_0 = a[0]^b_0;
	for(int i = 0; i < n; i++) {
		ta[i] = a[i]^b_0;
		tb[i] = b[i]^a_0;
		if(ta[i]>=n||tb[i]>=n) return 0;
	}
	for(int i = 0; i < n; i++) {
		if(ta[tb[i]]!=i) return 0;
	}
	return 1;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++)
		a[i] = q(i, 0);
	for(int j = 0; j < n; j++)
		b[j] = q(0, j);
	int ans = 0, x = 0;
	for(int i = 0; i < n; i++) {
		int t = check(i);
		if(t) {
			ans++;
			x = i;
		}
	}
	check(x);
	cout << "!\n" << ans << "\n";
	for(int i = 0; i < n; i++)
		cout << ta[i] << " ";cout << endl;
}