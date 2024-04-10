#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstring>
#include<iomanip>
#include<cmath>
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

const int _ = 2e5 + 3;
int arr1[_] , arr2[_] , N , M , K , ta , tb;

signed main(){
	N = read(); M = read(); ta = read(); tb = read(); K = read();
	for(int i = 1 ; i <= N ; ++i) arr1[i] = read();
	for(int i = 1 ; i <= M ; ++i) arr2[i] = read();
	if(N <= K || M <= K){puts("-1"); return 0;}
	int ans = 0;
	for(int i = 0 ; i < N && i <= K ; ++i){
		int t = lower_bound(arr2 + 1 , arr2 + M + 1 , arr1[i + 1] + ta) - arr2;
		if(M - t + 1 <= K - i){puts("-1"); return 0;}
		ans = max(ans , arr2[t + K - i] + tb);
	}
	cout << ans;
	return 0;
}