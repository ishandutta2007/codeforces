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

int pot1[10] , pot2[10] , pot3[10] , pot4[10];

int main(){
#ifndef ONLINE_JUDGE
	freopen("777B.in" , "r" , stdin);
	//freopen("777B.out" , "w" , stdout);
#endif
	int N = read() , cnt = 0;
	char c;
	for(int i = 1 ; i <= N ; i++){
		c = getchar();
		while(!isdigit(c))
			c = getchar();
		pot1[c - '0']++;
		pot3[c - '0']++;
	}
	for(int i = 1 ; i <= N ; i++){
		c = getchar();
		while(!isdigit(c))
			c = getchar();
		pot2[c - '0']++;
		pot4[c - '0']++;
	}
	for(int i = 0 ; i < 10 ; i++)
		for(int j = i ; pot1[i] && j < 10 ; j++){
			int t = min(pot1[i] , pot2[j]);
			cnt += t;
			pot1[i] -= t;
			pot2[j] -= t;
		}
	cout << N - cnt << endl;
	memcpy(pot1 , pot3 , sizeof(pot1));
	memcpy(pot2 , pot4 , sizeof(pot4));
	cnt = 0;
	for(int i = 0 ; i < 10 ; i++)
		for(int j = i + 1 ; pot1[i] && j < 10 ; j++){
			int t = min(pot1[i] , pot2[j]);
			cnt += t;
			pot1[i] -= t;
			pot2[j] -= t;
		}
	cout << cnt;
	return 0;
}