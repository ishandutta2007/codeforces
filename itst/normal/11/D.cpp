#include<bits/stdc++.h>
#define lowbit(x) ((x) & -(x))
#define low(x) (int)(log2(lowbit(x)) + 0.1)
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

bool Edge[19][19];
int head[19] , ind[1 << 19];
int N , M;
long long dp[19][1 << 19] , ans;

int main(){
	#ifndef ONLINE_JUDGE
	//freopen("in" , "r" , stdin);
	//freopen("out" , "w" , stdout);
	#endif
	N = read();
	M = read();
	for(int i = 1 ; i <= M ; ++i){
		int a = read() - 1 , b = read() - 1;
		Edge[a][b] = Edge[b][a] = dp[max(a , b)][(1 << a) + (1 << b)] = 1;
	}
	for(int i = 1 ; i < 1 << N ; ++i)
		for(int j = 0 ; j < N ; ++j)
			if(dp[j][i] && i & (1 << j)){
				ans += Edge[low(i)][j] * dp[j][i];
				for(int k = low(i) + 1 ; k < N ; ++k)
					if(Edge[j][k] && !(i & (1 << k)))
						dp[k][i | (1 << k)] += dp[j][i];
			}
	cout << (ans - M) / 2;
	return 0;
}