#include<bits/stdc++.h>
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

const int MAXN = 2010;
bitset < MAXN > gauss[MAXN];
int N , M , ans[MAXN];

int main(){
	for(int T = read() ; T ; --T){
		N = read();
		M = read();
		for(int i = 1 ; i <= N ; ++i){
			gauss[i].reset();
			gauss[i].set(i);
		}
		for(int i = 1 ; i <= M ; ++i){
			int a = read() , b = read();
			gauss[a][N + 1] = ~gauss[a][N + 1];
			gauss[b][N + 1] = ~gauss[b][N + 1];
			gauss[a][b] = gauss[b][a] = 1;
		}
		bool f = 1;
		for(int i = 1 ; f && i <= N ; ++i)
			f = !gauss[i][N + 1];
		if(f){
			puts("1");
			for(int i = 1 ; i <= N ; ++i)
				printf("1 ");
		}
		else{
			for(int i = 1 ; i <= N ; ++i)
				if(!gauss[i][N + 1])
					gauss[i][i] = 0;
			int now = 1;
			for(int i = 1 ; i <= N ; ++i){
				int j = now;
				while(j <= N && !gauss[j][i])
					++j;
				if(j > N){
					ans[i] = 0;
					for(int k = 1 ; k < now ; ++k)
						gauss[k][i] = 0;
					continue;
				}
				if(j != now)
					swap(gauss[j] , gauss[now]);
				while(++j <= N)
					if(gauss[j][i])
						gauss[j] ^= gauss[now];
				++now;
			}
			for(int j = now - 1 ; j ; --j){
				int p = 0;
				for(int k = 1 ; !p && k <= N ; ++k)
					if(gauss[j][k])
						p = k;
				ans[p] = gauss[j][N + 1];
				for(int k = j - 1 ; k ; --k)
					if(gauss[k][p])
						gauss[k] ^= gauss[j];
			}
			puts("2");
			for(int i = 1 ; i <= N ; ++i)
				printf("%d " , ans[i] + 1);
		}
		putchar('\n');
	}
	return 0;
}