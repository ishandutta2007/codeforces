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

int num1[100010];

int main(){
	int N = read();
	if(N & 1)
		puts("NO");
	else{
		printf("YES");
		for(int i = 1 ; i <= N ; ++i)
			num1[i] = i;
		for(int i = log2(N) ; i ; --i)
			for(int j = 1 << i ; num1[j] == j ; ++j)
				swap(num1[j] , num1[(1 << (i + 1)) - 1 - j]);
		for(int i = 1 ; i <= N ; ++i)
			printf(" %d" , num1[i]);
	}
	putchar('\n');
	if(!(N & 1) || N >= 7){
		for(int i = 1 ; i <= N ; ++i)
			num1[i] = i;
		for(int i = 2 ; i < N ; i += 2)
			swap(num1[i] , num1[i + 1]);
		if(N & 1){
			num1[1] = 5;
			num1[5] = 7;
			num1[7] = 1;
			num1[6] = 4;
			num1[4] = 6;
		}
		else{
			if(1 << (int)log2(N) == N){
				puts("NO");
				return 0;
			}
			else{
				num1[N] = N - 2;
				num1[N - 2] = N;
				num1[N - 1] = 1;
				num1[1] = N - 1;
			}
		}
		printf("YES");
		for(int i = 1 ; i <= N ; ++i)
			printf(" %d" , num1[i]);
	}
	else
		puts("NO");
	return 0;
}