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

const int MAXN = 2e5 + 3 , MOD = 1e9 + 7;
int dp[MAXN][3] , N , L , R , cnt[3];

inline void calc(int x){
	int p = L , q = R;
	while(p % 3 != x)
		++p;
	while((q % 3 + 3) % 3 != x)
		--q;
	cnt[x] = (q - p) / 3 + 1;
}

int main(){
	dp[0][0] = 1;
	cin >> N >> L >> R;
	calc(0);
	calc(1);
	calc(2);
	for(int i = 1 ; i <= N ; ++i)
		for(int j = 0 ; j < 3 ; ++j)
			for(int k = 0 ; k < 3 ; ++k)
				dp[i][j] = (dp[i][j] + 1ll * dp[i - 1][k] * cnt[(j - k + 3) % 3]) % MOD;
	cout << dp[N][0];
	return 0;
}