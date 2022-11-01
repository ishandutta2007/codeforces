#include<bits/stdc++.h>
#define lowbit(x) ((x) & -(x))
//This code is written by Itst
using namespace std;

inline int read(){
	int a = 0;
	char c = getchar();
	bool f = 0;
	while(!isdigit(c) && c != EOF){
		if(c == '-')
			f = 1;
		c = getchar();
	}
	if(c == EOF)
		exit(0);
	while(isdigit(c)){
		a = a * 10 + c - 48;
		c = getchar();
	}
	return f ? -a : a;
}

const int MOD = 1e9 + 7;
int arr[11][11] , f[11][11] , cnt1[1 << 10] , times[11];
int N , M , K;

int dfs(int x , int y){
	if(y > M){
		y = 1;
		++x;
	}
	if(x > N)
		return 1;
	int s = f[x - 1][y] | f[x][y - 1] , sum = 0 , calc = 0;
	if(K - cnt1[s] < N - x + M - y + 1)
		return 0;
	bool ff = 0;
	for(int i = 0 ; i < K ; ++i)
		if(!(s & (1 << i)))
			if(arr[x][y] == i + 1 || arr[x][y] == 0){
				f[x][y] = s | (1 << i);
				if(!times[i + 1]++){
					if(!ff){
						calc = dfs(x , y + 1);
						ff = 1;
					}
					sum = (sum + calc) % MOD;
				}
				else
					sum = (sum + dfs(x , y + 1)) % MOD;
				--times[i + 1];
			}
	return sum;
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
	//freopen("out","w",stdout);
#endif
	N = read();
	M = read();
	K = read();
	if(N + M - 1 > K){
		puts("0");
		return 0;
	}
	for(int i = 1 ; i <= N ; ++i)
		for(int j = 1 ; j <= M ; ++j)
			++times[arr[i][j] = read()];
	for(int i = 1 ; i < 1 << K ; ++i)
		cnt1[i] = cnt1[i - lowbit(i)] + 1;
	cout << dfs(1 , 1);
	return 0;
}