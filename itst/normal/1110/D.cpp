#include<bits/stdc++.h>
//This code is written by Itst
using namespace std;

inline int read(){
    int a = 0;
    char c = getchar();
    bool f = 0;
    while(!isdigit(c)){
	    if(c == '-')
			f = 1;
        c = getchar();
    }
    while(isdigit(c)){
		a = (a << 3) + (a << 1) + (c ^ '0');
		c = getchar();
	}
	return f ? -a : a;
}

int N , M , pot[1000007] , dp[2][9][9];

#define min(i,j) ((i) < (j) ? (i) : (j))

int main(){
	N = read();
	M = read();
	for(int i = 1 ; i <= N ; ++i)
		++pot[read()];
	memset(dp , -0x3f , sizeof(dp));
	dp[0][0][0] = 0;
	int now = 0;
	for(int j = 1 ; j <= M ; ++j){
		now ^= 1;
		memset(dp[now] , -0x3f , sizeof(dp[now]));
		int p = pot[j] % 3;
		while(p <= pot[j] && p <= 8){
			for(int k = 0 ; k <= 6 ; ++k)
				for(int l = 0 ; l <= 6 ; ++l){
					int cnt = min(min(l , k) , p);
					dp[now][l - cnt][p - cnt] = max(dp[now][l - cnt][p - cnt] , dp[now ^ 1][k][l] + cnt + (pot[j] - p) / 3);
				}
			p += 3;
		}
	}
	int ans = 0;
	for(int j = 0 ; j < 9 ; ++j)
		for(int k = 0 ; k < 9 ; ++k)
			ans = max(ans , dp[now][j][k]);
	cout << ans;
	return 0;
}