#include<bits/stdc++.h>
using namespace std;

#define ld long double
ld dp[2003][2003]; int N , M;

ld solve(int N , int M){
	if(!N || !M) return 1.0 / (M + 1);
	if(dp[N][M]) return dp[N][M];
	ld X = solve(M - 1 , N) , Y = solve(M , N - 1);
	ld a1 = 1 , b1 = M / (M + 1.0) * (1 - X) - 1;
	ld a2 = 1 - Y , b2 = 1 / (M + 1.0) + M / (M + 1.0) * (1 - X) - (1 - Y);
	ld p = (a1 - a2) / (b2 - b1);
	return dp[N][M] = max((ld)1.0 / (M + 1) , p * M / (M + 1) * (1 - X) + 1 - p);
}

int main(){
	cin >> N >> M; ld ans = solve(N , M);
	cout << fixed << setprecision(9) << ans << ' ' << 1 - ans << endl;
	return 0;
}