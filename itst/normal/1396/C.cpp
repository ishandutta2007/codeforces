#include<bits/stdc++.h>
using namespace std;

int read(){
	int a = 0; char c = getchar(); while(!isdigit(c)) c = getchar();
	while(isdigit(c)){a = a * 10 + c - 48; c = getchar();} return a;
}

long long N , A1 , A2 , A3 , D , dp[1000003][2] , A[1000003];

int main(){
	N = read(); A1 = read(); A2 = read(); A3 = read(); D = read();
	for(int i = 1 ; i <= N ; ++i) A[i] = read();
	for(int i = 1 ; i <= N ; ++i){
		long long v1 = A[i] * A1 + A3 , v2 = min(A2 + A1 , (A[i] + 2) * A1);
		dp[i][0] = min(dp[i - 1][0] + min(v1 , v2 + 2 * D) ,
					   dp[i - 1][1] + min(v1 , v2) + 3 * i * D) + D;
		dp[i][1] = min(dp[i - 1][0] - 3 * i * D + v2 , dp[i - 1][1] + min(v1 , v2));
	}
	long long ans = dp[N][0] - D , sufsum = min(A[N] * A1 + A3 , min(A1 + A2 , (A[N] + 2) * A1) + 2 * D);
	for(int i = N - 1 ; i ; --i){
		sufsum += min(A[i] * A1 + A3 , min(A1 + A2 , (A[i] + 2) * A1));
		ans = min(ans , dp[i - 1][0] + sufsum + (N - i) * 2 * D);
	}
	cout << ans;
	return 0;
}