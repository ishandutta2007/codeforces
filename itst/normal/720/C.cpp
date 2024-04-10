#include<bits/stdc++.h>
using namespace std;

int N , M , K , T;

int main(){
	for(scanf("%d" , &T) ; T ; --T){
		scanf("%d %d %d" , &N , &M , &K);
		bool f = N == 3; if(f) swap(N , M);
		vector < vector < char > > pot(N); bool haveans = 1;
		for(int i = 0 ; i < N ; ++i) pot[i].resize(M , !i + '0');
		for(int i = 1 ; i < N && K ; ++i)
			for(int j = 0 ; j < M && K ; ++j)
				if(K < (j == 0 ? 1 : (j == M - 1 ? 3 : 4))){
					if(j == M - 1)
						if(i == N - 1) haveans = 0;
						else{pot[i + 1][M - 2] = '1'; pot[i + 1][M - 1] = '0' + (K == 2);}
					else
						if(K == 1) pot[i][M - 1] = '1';
						else if(j == M - 2)
							if(i == N - 1) haveans = 0;
							else
								if(j == 1){
									pot[i + 1][M - 3] = pot[i + 1][M - 2] = pot[i][M - 1] = '1'; pot[i + 1][M - 1] = '0' + (K == 3);
								}else{pot[i + 1][M - 3] = pot[i + 1][M - 2] = '1'; pot[i][M - 1] = '0' + (K == 3);}
						else if(K == 2) pot[i][M - 2] = '1';
						else if(j == M - 3)
							if(i == N - 1) haveans = 0;
							else pot[i][M - 2] = pot[i + 1][M - 2] = pot[i + 1][M - 1] = '1';
						else pot[i][M - 1] = pot[i][M - 3] = '1';
					K = 0;
				}else{K -= (j == 0 ? 1 : (j == M - 1 ? 3 : 4)); pot[i][j] = '1';}
		
		if(!haveans || K) puts("-1");
		else
			if(!f)
				for(int i = 0 ; i < N ; ++i , puts(""))
					for(int j = 0 ; j < M ; ++j) putchar(pot[i][j] == '0' ? '.' : '*');
			else
				for(int j = 0 ; j < M ; ++j , puts(""))
					for(int i = 0 ; i < N ; ++i) putchar(pot[i][j] == '0' ? '.' : '*');
		if(T != 1) puts("");
	}
	return 0;
}