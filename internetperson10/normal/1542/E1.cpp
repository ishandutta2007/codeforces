#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

ll dp[25001], dpans[501], dp2[25001];

int main() {
	ll n, MOD;
	cin >> n >> MOD;
	if(n < 4) {
		cout << "0\n";
		return 0;
	}
	int tar = 3;
	dp[0] = 1;
	dp[1] = 2;
	dp[2] = 2;
	dp[3] = 1;
	dpans[n] = 0;
	while(tar != n) {
		dpans[tar+1] = (dpans[tar]*(tar+1))%MOD;
		int k = (tar * tar - tar)/2;
		for(int i = 0; i <= k; i++) {
			for(int j = i+2; j <= k; j++) {
				ll bads = 0;
				for(int x = 0; x <= tar; x++) {
					bads += min(j-i-1, tar-x);
				}
				dpans[tar+1] += ((dp[i]*dp[j])%MOD)*bads;
				dpans[tar+1] %= MOD;
			}
		}
		for(int i = 0; i <= tar; i++) {
			for(int j = 0; j <= k; j++) {
				dp2[i+j] += dp[j];
			}
		}
		for(int i = 0; i <= tar+k; i++) {
			dp[i] = dp2[i]%MOD;
			dp2[i] = 0;
		}
		tar++;
	}
	cout << dpans[n] << '\n';
}