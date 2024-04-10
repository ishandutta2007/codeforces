#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<bitset>
#include<cmath>
#include<cassert>
#include<algorithm>
using namespace std;

#define PII pair < int , int >
long double dp[11][11]; int height[11][11];
PII nxt[11][11];

signed main(){
	for(int i = 1 ; i <= 10 ; ++i)
		for(int j = 1 ; j <= 10 ; ++j)
			cin >> height[i][j];
	for(int i = 1 ; i <= 10 ; ++i)
		if(i & 1)
			for(int j = 1 ; j <= 10 ; ++j)
				nxt[i][j] = j == 1 ? PII(i - 1 , j) : PII(i , j - 1);
		else
			for(int j = 1 ; j <= 10 ; ++j)
				nxt[i][j] = j == 10 ? PII(i - 1 , j) : PII(i , j + 1);
	for(int i = 1 ; i <= 10 ; ++i)
		for(int j = i & 1 ? 1 : 10 ; j <= 10 && j ; i & 1 ? ++j : --j)
			if(i == 1 && j == 1) continue;
			else{
				int px = i , py = j;
				for(int k = 1 ; k <= 6 ; ++k){
					PII t = nxt[px][py]; px = t.first; py = t.second;
					if(px == 0){dp[i][j] = dp[i][j] * 6 / (k - 1) + (6 - k + 1) / 6.0 / (1 - (6 - k + 1) / 6.0); break;}
					dp[i][j] += (min(dp[px][py] , dp[px - height[px][py]][py]) + 1) / 6;
				}
			}
	cout << fixed << setprecision(9) << dp[10][1];
	return 0;
}