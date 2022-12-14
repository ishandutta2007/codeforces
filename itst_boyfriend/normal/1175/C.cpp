#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstring>
#include<iomanip>
#include<cmath>
#include<cassert>
//This code is written by Itst
using namespace std;

int read(){
	int a = 0; bool f = 0;
	char c = getchar();
	while(!isdigit(c)){f = c == '-'; c = getchar();}
	while(isdigit(c)){
		a = a * 10 + c - 48; c = getchar();
	}
	return f ? -a : a;
}

#define int long long
int pos[200003] , N , K;

signed main(){
	for(int T = read() ; T ; --T){
		N = read(); K = read();
		for(int i = 1 ; i <= N ; ++i)
			pos[i] = read();
		pos[0] = 1; pos[++N] = 1e9;
		int Max = 1e18 , id = 0;
		if(K == 0){cout << pos[1] << endl; continue;}
		for(int i = 1 ; i + K <= N ; ++i){
			int tpid = (pos[i + K - 1] + pos[i - 1] + 1) / 2 , tpMx = tpid - pos[i - 1];
			int tpid2 = (pos[i + K] + pos[i]) / 2 , tpMx2 = pos[i + K] - tpid2;
			if(i == 1) tpMx = 1e18;
			if(i + K == N) tpMx2 = 1e18;
			if(tpMx > tpMx2){
				tpMx = tpMx2; tpid = tpid2;
			}
			if(Max > tpMx){
				Max = tpMx; id = tpid;
			}
		}
		printf("%I64d\n" , id);
	}
	return 0;
}