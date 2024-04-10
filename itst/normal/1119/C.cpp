#include<bits/stdc++.h>
//This code is written by Itst
using namespace std;
inline int read(){
	int a = 0;
	char c = getchar();
	while(!isdigit(c)) c = getchar();
	while(isdigit(c)){
		a = a * 10 + c - 48;
		c = getchar();
	}
	return a;
}
#define int long long
int arr[507][507] , to[507][507] , N , M;
signed main(){
	N = read(); M = read();
	for(int i = 1 ; i <= N ; ++i)
		for(int j = 1 ; j <= M ; ++j)
			arr[i][j] = read();
	for(int i = 1 ; i <= N ; ++i)
		for(int j = 1 ; j <= M ; ++j)
			to[i][j] = read();
	for(int i = 1 ; i < N ; ++i)
		for(int j = 1 ; j < M ; ++j)
			if(arr[i][j] != to[i][j]){
				arr[i][j] ^= 1;
				arr[i + 1][j] ^= 1;
				arr[i][j + 1] ^= 1;
				arr[i + 1][j + 1] ^= 1;
			}
	for(int i = 1 ; i <= N ; ++i)
		for(int j = 1 ; j <= M ; ++j)
			if(arr[i][j] != to[i][j]){
				puts("No");
				return 0;
			}
	puts("Yes");
	return 0;
}