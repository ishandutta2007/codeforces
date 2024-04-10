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

bool is[19000010];
int N , be[6010];

void calc2(int x){
	for(int j = 3 ; j <= x >> 1 ; j += 2)
		if(!is[j] && !is[x - j]){
			int p = j % (x + 1) , q = j / (x + 1);
			if(p == 3 && be[3])
				be[1] = be[2] = 1;
			else
				be[p] = 1;
			for(int k = 1 ; q && k < x >> 1 ; ++k)
				if(!be[k])
					be[k] = be[x - k] = 1;
			break;
		}
	for(int i = 1 ; i <= N ; ++i)
		printf("%d " , be[i] ? be[i] : 2);
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("in" , "r" , stdin);
	//freopen("out" , "w" , stdout);
#endif
	N = read();
	int T = N * (N + 1) / 2;
	for(int i = 2 ; i <= T ; ++i)
		if(!is[i]){
			for(int j = i ; j <= T / i ; ++j)
				is[i * j] = 1;
		}
	if(!is[T])
		for(int i = 1 ; i <= N ; ++i)
			printf("1 ");
	else
		if(T % 2 == 0)
			calc2(T);
		else
			if(!is[T - 2])
				for(int i = 1 ; i <= N ; ++i)
					printf("%d " , 1 + (i == 2));
			else{
				T -= 3;
				be[3] = 3;
				calc2(T);
			}
	return 0;
}