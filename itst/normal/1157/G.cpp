#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<iomanip>
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

int arr[203][203] , rot[203][203] , N , M;
bool h[203] , l[203];

signed main(){
	N = read(); M = read();
	for(int i = 1 ; i <= N ; ++i)
		for(int j = 1 ; j <= M ; ++j)
			arr[i][j] = read();
	for(int i = 1 ; i <= M ; ++i)
		for(int j = 0 ; j <= 1 ; ++j){
			memset(h , 0 , sizeof(h)); memset(l , 0 , sizeof(l));
			memcpy(rot , arr , sizeof(arr));
			if(h[1] = j)
				for(int k = 1 ; k <= M ; ++k)
					rot[1][k] ^= 1;
			for(int k = 1 ; k <= M ; ++k)
				if((k < M - i + 1 && rot[1][k]) || (k >= M - i + 1 && !rot[1][k])){
					l[k] = 1;
					for(int j = 1 ; j <= N ; ++j)
						rot[j][k] ^= 1;
				}
			bool flg = 1;
			for(int k = 2 ; flg && k <= N ; ++k){
				h[k] = 1 ^ rot[k][1];
				for(int l = 2 ; flg && l <= M ; ++l)
					flg = rot[k][1] == rot[k][l];
			}
			if(flg){
				puts("YES");
				for(int i = 1 ; i <= N ; ++i)
					putchar('0' + h[i]);
				putchar('\n');
				for(int i = 1 ; i <= M ; ++i)
					putchar('0' + l[i]);
				return 0;
			}
		}
	for(int j = 0 ; j <= 1 ; ++j){
		memset(h , 0 , sizeof(h)); memset(l , 0 , sizeof(l));
		memcpy(rot , arr , sizeof(arr));
		if(h[1] = j)
			for(int k = 1 ; k <= M ; ++k)
				rot[1][k] ^= 1;
		for(int k = 1 ; k <= M ; ++k)
			if(rot[1][k]){
				l[k] = 1;
				for(int j = 1 ; j <= N ; ++j)
					rot[j][k] ^= 1;
			}
		bool flg = 1 , have = 0;
		for(int k = 2 ; flg && k <= N ; ++k){
			bool f = rot[k][1] == rot[k][M];
			if(!f)
				if(have) flg = 0;
				else{
					have = 1; h[k] = rot[k][1];
					bool cng = 0;
					for(int l = 2 ; flg && l < M ; ++l)
						if(rot[k][l] != rot[k][cng ? M : 1])
							if(cng) flg = 0;
							else cng = 1;
				}
			else{
				h[k] = have ^ rot[k][1];
				for(int j = 2 ; flg && j <= M ; ++j)
					if(rot[k][1] != rot[k][j]) flg = 0;
			}
		}
		if(flg){
			puts("YES");
			for(int i = 1 ; i <= N ; ++i)
				putchar('0' + h[i]);
			putchar('\n');
			for(int i = 1 ; i <= M ; ++i)
				putchar('0' + l[i]);
			return 0;
		}
	}
	puts("NO");
	return 0;
}