#include<bits/stdc++.h>
using namespace std;

int read(){
	int a = 0; char c = getchar(); while(!isdigit(c)) c = getchar();
	while(isdigit(c)){a = a * 10 + c - 48; c = getchar();} return a;
}

int N , K , col[100003] , pre[103] , segl[103] , segr[103];

int main(){
	N = read(); K = read(); int cnt = 0;
	for(int i = 1 ; i <= N * K ; ++i){
		col[i] = read();
		if(pre[col[i]]){
			if(segl[col[i]]) continue;
			segl[col[i]] = pre[col[i]]; segr[col[i]] = i;
			if(++cnt == (N + K - 2) / (K - 1)){memset(pre , 0 , sizeof(pre)); cnt = 0;}
		}else pre[col[i]] = i;
	}
	for(int i = 1 ; i <= N ; ++i){assert(segl[i]); cout << segl[i] << ' ' << segr[i] << endl;}
	return 0;
}