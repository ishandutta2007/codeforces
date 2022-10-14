#include<bits/stdc++.h>
#define all(x) begin(x), end(x)
using ll = long long;
using namespace std;
const int maxn = 2020, mod = 1e9 + 7;
ll n, k, res[maxn];
void print() {
	res[0] = res[1] = 1;
	for(int i = 2; i <= n; i++) res[i] = res[i-1] + res[i-2];
	for(int i = 1; i <= n;) {
		int l = 0;
		while(i+l < n && k>res[n-i-l]) k -= res[n-i-l], l++;
		if(l) cout << i+1 << " " << i << " ";
		else cout << i << " ";
		i = i+l+1;
	}
	cout << endl;
}
signed main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> k;
	print();
}