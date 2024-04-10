#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef long double ld;

char ans[1000010];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll q, n, k;
	cin >> q;
	while(q--) {
		cin >> n >> k;
		string s;
		cin >> s;
		ll last0 = -1;
		memset(ans, '1', sizeof(ans));
		for(ll i = 0; i < n; i++)
			if(s[i] == '0') {
				last0++;
				if(i - last0 <= k) {
					ans[last0] = '0';
					k -= i - last0;
				} else {
					ans[i - k] = '0';
					k = 0;
				}
			}
		for(int i = 0; i < n; i++)
			cout << ans[i];
		cout << endl;
	}
	return 0;
}