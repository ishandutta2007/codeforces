#include<bits/stdc++.h>
using namespace std;
char s[2003][2003];
int S1[2003][2003] , S2[2003][2003];
int S3[2003][2003] , S4[2003][2003];
int S5[2003] , S6[2003];
int main(){
	int n , k; cin >> n >> k;
	for(int i = 1 ; i <= n ; ++i)
		scanf("%s" , s[i] + 1);
	for(int i = 1 ; i <= n ; ++i)
		for(int j = 1 ; j <= n ; ++j){
			S1[i][j] = (s[i][j]=='B') + S1[i - 1][j];
			S2[i][j] = (s[i][j]=='B') + S2[i][j - 1];
		}
	for(int i = 1; i <= n ; ++i)
		for(int j = 1; j <= n ; ++j){
			if(i + k - 1 <= n)
				S3[i][j] = S1[i + k - 1][j] - S1[i - 1][j] == S1[n][j];
			if(j + k - 1 <= n)
				S4[i][j] = S2[i][j + k - 1] - S2[i][j - 1] == S2[i][n];
			S3[i][j] += S3[i][j - 1];
			S4[i][j] += S4[i - 1][j];
		}
	for(int i = 1 ; i <= n ; ++i)
		S5[i] = (!S1[n][i]) + S5[i - 1];
	for(int i = 1;i <= n ; ++i)
		S6[i] = (!S2[i][n]) + S6[i - 1];
	int ans = 0;
	for(int i = 1 ; i + k - 1 <= n ; ++i)
		for(int j = 1 ; j + k - 1 <= n ; ++j)
			ans = max(ans , S3[i][j+k-1]-S3[i][j-1]+S4[i+k-1][j]-S4[i-1][j]+S5[j-1]+S5[n]-S5[j+k-1]+S6[i-1]+S6[n]-S6[i+k-1]);
	printf("%d\n" , ans);
	return 0;
}