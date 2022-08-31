#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld double

const int N = 500;
ld P[N][N];

double dp[N][N];
double prob[N][N], st[N][N];
int n;
void go(int s, int e, int ind, int lev){
	if(s == e){
		prob[ind][s] = 1;
		return;
	}
	int mid = (s + e) >> 1;

	go(s, mid, 2 * ind, lev - 1);
	go(mid + 1, e, 2 * ind + 1, lev - 1);
	memset(st, 0, sizeof st);
	for(int i = s; i <= mid; i++){
		for(int j = mid + 1; j <= e; j++){
			double pp = prob[2 * ind][i] * prob[2 * ind + 1][j];
			prob[ind][i] += pp * P[i][j];
			prob[ind][j] += pp * P[j][i];
		}
	}
	for(int i = s; i <= mid; i++){
		for(int j = mid + 1; j <= e; j++){
			
			dp[ind][i] = max(dp[ind][i], dp[2 * ind][i] + dp[2 * ind + 1][j] + (1 << lev) * prob[ind][i]);
			dp[ind][j] = max(dp[ind][j], dp[2 * ind][i] + dp[2 * ind + 1][j] + (1 << lev) * prob[ind][j]);
			
		}
	}
}

int main(){
	cin >> n;
	int xyz;
	for(int i = 1; i <= (1 << n); i++){
		for(int j = 1; j <= (1 << n); j++){
			cin >> xyz;
			P[i][j] = xyz/100.0;
		}
	}

	go(1, 1 << n, 1, n - 1);

	double ans = 0;

	cerr << prob[1][1] << " " << prob[1][2] << " " << prob[1][3] << " " << prob[1][4] << endl;
	for(int i = 1; i <= (1 << n); i++){
		ans = max(ans, dp[1][i]);
	}
	cout << setprecision(10) << fixed << ans;
}