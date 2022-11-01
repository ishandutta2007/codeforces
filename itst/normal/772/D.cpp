#include<iostream>
#include<cstdio>
//This code is written by Itst
using namespace std;

inline int read(){
	int a = 0;
	char c = getchar();
	while(!isdigit(c))
		c = getchar();
	while(isdigit(c)){
		a = a * 10 + c - 48;
		c = getchar();
	}
	return a;
}

const int MAXN = 1e6 + 7 , MOD = 1e9 + 7;
int sum0[MAXN] , sum1[MAXN] , sum2[MAXN] , N;

void merge(int x , int y){
	sum2[y] = (2ll * sum1[x] * sum1[y] + sum2[x] * (sum0[y] + 1ll) + sum2[y] * (sum0[x] + 1ll)) % MOD;
	sum1[y] = (sum1[x] * (sum0[y] + 1ll) + sum1[y] * (sum0[x] + 1ll)) % MOD;
	sum0[y] = (1ll * (sum0[x] + 1) * (sum0[y] + 1) + MOD - 1) % MOD;
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
	//freopen("out","w",stdout);
#endif
	N = read();
	for(int i = 1 ; i <= N ; ++i){
		int a = read();
		sum0[0] = 1;
		sum1[0] = a;
		sum2[0] = 1ll * a * a % MOD;
		merge(0 , a);
	}
	int times = 1;
	for(int i = 0 ; i < 6 ; ++i){
		for(int j = 999999 ; j ; --j)
			if(j / times % 10 != 9)
				merge(j + times , j);
		times *= 10;
	}
	times = 1;
	for(int i = 0 ; i < 6 ; ++i){
		for(int j = 1 ; j < 1e6 ; ++j)
			if(j / times % 10 != 9)
				sum2[j] = (sum2[j] - sum2[j + times] + MOD) % MOD;
		times *= 10;
	}
	long long ans = 0;
	for(long long i = 1 ; i < 1e6 ; ++i) ans ^= sum2[i] * i;
	cout << ans;
	return 0;
}