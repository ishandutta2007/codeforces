#include<bits/stdc++.h>
//This code is written by Itst
using namespace std;

const int MAXN = 5007;
int num[MAXN] , dp[MAXN][MAXN] , N;

int main(){
	cin >> N;
	int cnt = 0;
	for(int i = 1 ; i <= N ; ++i){
		int a;
		cin >> a;
		if(a != num[cnt])
			num[++cnt] = a;
	}
	for(int i = 2 ; i <= cnt ; ++i)
		for(int j = i - 1 ; j ; --j){
			dp[j][i] = max(dp[j][i] , max(dp[j + 1][i] , dp[j][i - 1]));
			if(num[j] == num[i])
				dp[j][i] = max(dp[j][i] , dp[j + 1][i - 1] + 1);
		}
	cout << cnt - dp[1][cnt] - 1;
	return 0;
}