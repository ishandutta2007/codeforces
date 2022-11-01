#include<bits/stdc++.h>
//This code is written by Itst
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

char c[1010][1010] , ans[1010][1010];
int N , M;

inline char getc(){
	char c = getchar();
	while(c != '.' && c != 'w' && c != 'b')
		c = getchar();
	return c;
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("in" , "r" , stdin);
	//freopen("out" , "w" , stdout);
#endif
	N = read();
	M = read();
	for(int i = 1 ; i <= N ; ++i)
		for(int j = 1 ; j <= M ; ++j)
			if((c[i][j] = getc()) == '.')
				ans[i][j] = '.';
	for(int i = 1 ; i <= N ; ++i)
		for(int j = 1 ; j <= M ; ++j)
			if(!ans[i][j])
				if(c[i][j] == 'b'){
					puts("NO");
					return 0;
				}
				else
					if(c[i][j + 1] == 'b' && c[i][j + 2] == 'w' && !ans[i][j + 1] && !ans[i][j + 2]){
						for(char k = 'a' ; k <= 'd' ; ++k)
							if(ans[i][j - 1] != k && ans[i - 1][j] != k && ans[i - 1][j + 1] != k && ans[i - 1][j + 2] != k && ans[i][j + 3] != k && ans[i + 1][j] != k && ans[i + 1][j + 1] != k && ans[i + 1][j + 2] != k){
								ans[i][j] = ans[i][j + 1] = ans[i][j + 2] = k;
								break;
							}
					}
					else
						if(c[i + 1][j] == 'b' && c[i + 2][j] == 'w' && !ans[i + 1][j] && !ans[i + 2][j]){
							for(char k = 'a' ; k <= 'd' ; ++k)
								if(ans[i][j - 1] != k && ans[i - 1][j] != k && ans[i + 1][j - 1] != k && ans[i + 2][j - 1] != k && ans[i][j + 1] != k && ans[i + 3][j] != k && ans[i + 1][j + 1] != k && ans[i + 2][j + 1] != k){
									ans[i][j] = ans[i + 1][j] = ans[i + 2][j] = k;
									break;
								}
						}
						else{
							puts("NO");
							return 0;
						}
	puts("YES");
	for(int i = 1 ; i <= N ; ++i){
		for(int j = 1 ; j <= M ; ++j)
			putchar(ans[i][j]);
		putchar('\n');
	}
	return 0;
}