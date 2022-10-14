#include<bits/stdc++.h>
#define all(x) begin(x), end(x)
using namespace std;
const int maxn = 1<<20;
int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;cin >> t;
	while(t--) {
		int n;cin >> n;
		for(int i =2 ; i <= n; i++) cout << i << " ";
		cout << "1\n";
	}
}