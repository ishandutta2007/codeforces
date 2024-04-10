#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sd(x) scanf("%d", &(x))

const int N = 4005;

double a[N];
int b[N];
int up[N], down[N], cstfreq[N];
long long dp[N][N];
const ll INF = 1e18;
int main(){
	int n;
	sd(n);
	long long UP = 0;
	for(int i = 1; i <= 2 * n; i++){
		cin >> a[i];
		b[i] = (int)(a[i] * 1000 + 0.5);
		down[i] = b[i] % 1000;
		up[i] = (b[i] % 1000 == 0) ? 0 : 1000 - (b[i] % 1000);
		UP += up[i];
		cstfreq[up[i] + down[i]] ++;
	}
	for(int i = 1; i <= 999; i++) assert(!cstfreq[i]);
	int f0 = cstfreq[0], f1 = cstfreq[1000];
	long long ans = INF;
	for(int t = 0; t <= n; t++){
		if(t <= f1 && (n - t) <= f0){
			ans = min(ans, (ll)abs(UP - t * 1000));
		}
	}
	printf("%.3lf", ans / 1000.0);
}