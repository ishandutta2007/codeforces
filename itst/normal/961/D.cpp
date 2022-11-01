#include<bits/stdc++.h>
#define ll long long
//This code is written by Itst
using namespace std;

inline int read(){
	int a = 0;
	char c = getchar();
	bool f = 0;
	while(!isdigit(c) && c != EOF){
		if(c == '-')
			f = 1;
		c = getchar();
	}
	if(c == EOF)
		exit(0);
	while(isdigit(c)){
		a = (a << 3) + (a << 1) + (c ^ '0');
		c = getchar();
	}
	return f ? -a : a;
}

const int MAXN = 1e5 + 10;
int N;
ll point[MAXN][2];

void input(){
	N = read();
	for(int i = 1 ; i <= N ; ++i){
		point[i][0] = read();
		point[i][1] = read();
	}
}

void work(){
	for(int i = 1 ; i <= 3 ; ++i)
		for(int j = i + 1 ; j <= 3 ; ++j){
			int p = 0;
			ll A = point[i][1] - point[j][1] , B = point[j][0] - point[i][0] , C = point[i][0] * point[j][1] - point[i][1] * point[j][0] , curA , curB , curC;
			bool f = 1;
			for(int k = 1 ; f && k <= N ; ++k)
				if(k != i && k != j){
					if(A * point[k][0] + B * point[k][1] + C == 0)
						continue;
					if(!p)
						p = k;
					else
						if(p != -1){
							curA = point[p][1] - point[k][1];
							curB = point[k][0] - point[p][0];
							curC = point[p][0] * point[k][1] - point[p][1] * point[k][0];
							p = -1;
						}
						else
							if(curA * point[k][0] + curB * point[k][1] + curC != 0)
								f = 0;
				}
			if(f){
				puts("YES");
				return;
			}
		}
	puts("NO");
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("in" , "r" , stdin);
	//freopen("out" , "w" , stdout);
#endif
	input();
	work();
	return 0;
}