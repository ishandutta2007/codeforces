#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

ll dp[36][36];
ll dp2[36];

ll rec(int n, int h) {
	if((ll)n >= ((ll)1 << h)) return 0;
	if(n == 0) return 1;
	if(n == 1) return 1;
	if(dp[n][h] > 0) return dp[n][h];
	ll ans = 0;
	n--;
	for(int i = 0; i <= n; i++) {
		ans += rec(i, h-1)*rec(n-i, h-1);
	}
	return dp[n+1][h] = ans;
}

ll rec2(int n) {
	if(n <= 1) return 1;
	if(dp2[n] > 0) return dp2[n];
	ll ans = 0;
	n--;
	for(int i = 0; i <= n; i++) {
		ans += rec2(i)*rec2(n-i);
	}
	return dp2[n+1] = ans;
}

int main() {
	int n, h;
	cin >> n >> h;
	cout << rec2(n) - rec(n, h-1) << '\n';
}