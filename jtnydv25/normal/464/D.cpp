#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
const int MAX = 1005;

double dp[MAX];
double dp2[MAX];
double ans = 0;
double gain[N];
double inv[N], inv2[N];
double F[N];
int main(){
	for(int i = 1; i < MAX; i++) gain[i] = (i * (i + 3)) / (2. * (i + 1));
	for(int i = 1; i < MAX; i++){inv[i] = 1. / i; inv2[i] = (double)i / (double(i + 1));}
	int n, k;
	cin >> n >> k;
	double p = 1. / k;
	double ip = 1. - p;
	dp[1] = 1;
	for(int i = 1; i <= n; i++){
		memcpy(dp2, dp, sizeof dp2);
		double sm = 0;
		for(int j = 1; j < MAX; j++){
			dp[j] = ip * dp2[j];
			double add = dp2[j] * inv2[j];
			if(j != 1) add += dp2[j - 1] * inv[j];
			dp[j] += add * p;
			F[j] += dp2[j];
		}
	}
	for(int j = 0; j < MAX; j++) ans += F[j] * gain[j];
	cout << setprecision(10) << fixed << ans << endl;

}