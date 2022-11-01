#include<bits/stdc++.h>
using namespace std;

int read(){
	int a = 0; char c = getchar(); bool f = 0;
	while(!isdigit(c)){f = c == '-'; c = getchar();}
	while(isdigit(c)){
		a = a * 10 + c - 48; c = getchar();
	}
	return f ? -a : a;
}

const int _ = 2e5 + 7;
int jump[_][20] , mn[_] , nxt[_] , pm[_] , arr[_] , N , M , Q;

int main(){
	N = read(); M = read(); Q = read(); for(int i = 1 ; i <= N ; ++i) pm[i] = read();
	for(int i = 1 ; i <= N ; ++i) nxt[pm[i]] = pm[i % N + 1];
	for(int i = 1 ; i <= M ; ++i) pm[i] = read();
	mn[M + 1] = 1e9;
	for(int i = M ; i ; --i){
		jump[i][0] = arr[nxt[pm[i]]]; arr[pm[i]] = i; int to = i;
		for(int j = 1 ; jump[i][j - 1] ; ++j) jump[i][j] = jump[jump[i][j - 1]][j - 1];
		for(int j = 18 ; j >= 0 ; --j) if((N - 1) >> j & 1) to = jump[to][j];
		mn[i] = min(mn[i + 1] , to == 0 ? (int)1e9 : to);
	}
	while(Q--){int l = read() , r = read(); putchar('0' + (mn[l] <= r));}
	return 0;
}