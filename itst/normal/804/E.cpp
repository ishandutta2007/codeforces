#include<bits/stdc++.h>
//This code is written by Itst
using namespace std;

inline int read(){
	int a = 0;
	bool f = 0;
	char c = getchar();
	while(c != EOF && !isdigit(c)){
		if(c == '-')
			f = 1;
		c = getchar();
	}
	while(c != EOF && isdigit(c)){
		a = (a << 3) + (a << 1) + (c ^ '0');
		c = getchar();
	}
	return f ? -a : a;
}

const int mod1[6][2] = {1,2,1,3,2,4,1,4,2,3,3,4};
inline void output1(int x){
	x *= 4;
	for(int i = 0 ; i < 6 ; ++i)
		printf("%d %d\n" , mod1[i][0] + x , mod1[i][1] + x);
}

const int mod2[16][2] = {1,1,1,2,1,3,2,1,2,4,1,4,2,3,3,1,4,2,3,2,2,2,3,3,4,1,4,4,3,4,4,3};
inline void output2(int x1 , int x2){
	x1 *= 4;
	x2 *= 4;
	for(int i = 0 ; i < 16 ; ++i)
		printf("%d %d\n" , mod2[i][0] + x1 , mod2[i][1] + x2);
}

const int mod3[10][2] = {1,2,1,3,1,4,2,3,2,5,3,5,1,5,3,4,2,4,4,5};
inline void output3(int x , int end){
	x *= 4;
	for(int i = 0 ; i < 10 ; ++i)
		printf("%d %d\n" , mod3[i][0] + x , mod3[i][1] == 5 ? end : mod3[i][1] + x);
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("804E.in" , "r" , stdin);
	//freopen("804E.out" , "w" , stdout);
#endif
	int N = read();
	if(N % 4 == 2 || N % 4 == 3){
		puts("NO");
		return 0;
	}
	puts("YES");
	if(N % 4 == 0)
		for(int i = 0 ; i < N / 4 ; ++i)
			output1(i);
	else
		for(int i = 0 ; i < N / 4 ; ++i)
			output3(i , N);
	for(int i = 0 ; i < N / 4 ; ++i)
		for(int j = i + 1 ; j < N / 4 ; ++j)
			output2(i , j);
	return 0;
}