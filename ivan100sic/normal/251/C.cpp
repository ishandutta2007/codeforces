#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

ll a, b;
int dp[777777], k;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> a >> b >> k;
	for (int i=1; i<777777; i++) {
		dp[i] = dp[i-1] + 1;
		for (int x=2; x<=k; x++) {
			int y = (i+b)%x;
			if (i-y < 0)
				continue;
			dp[i] = min(dp[i], dp[i-y]+1);
		}
	}
	ll z = 0;
	if (a-b < 777777)
		z = dp[a-b];
	else
		z = (dp[720720] - dp[360360]) * ((a-b)/360360-1) + dp[360360 + (a-b)%360360];
	cout << z << '\n';
}