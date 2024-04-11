#include <bits/stdc++.h>
using namespace std;
using lint = long long;
int main(){
	int t; cin >> t;
	while(t--){
		lint n, k;
		cin >> n >> k;
		lint ans = 0;
		while(n){
			if(n % k == 0){
				ans++;
				n /= k;
				continue;
			}
			ans += n % k;
			n -= n % k;
		}
		cout << ans << endl;
	}
}