#include <bits/stdc++.h>
using namespace std;

const int N = 200;
int n, k, top, ans, a[N];
 
int main() {
	cin >> n >> k;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		top += a[i];
	}
	for(int j = 1; j <= k; j++){
		int sm = 0;
		for(int l = j; l <= n; l += k)
			sm += a[l];
		ans = max(ans, abs(top - sm));
	}
	cout << ans << endl;
}