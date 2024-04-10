#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<cctype>
#include<algorithm>
#include<cstring>
#include<iomanip>
#include<queue>
#include<map>
#include<set>
#include<bitset>
#include<stack>
#include<vector>
#include<cmath>
#include<random>
#include<cassert>
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
		a = a * 10 + c - 48;
		c = getchar();
	}
	return f ? -a : a;
}

int arr[1510] , N , Q;

int main(){
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
	//freopen("out","w",stdout);
#endif
	N = read();
	bool cnt = 0;
	for(int i = 1 ; i <= N ; ++i){
		arr[i] = read();
		for(int j = 1 ; j < i ; ++j)
			cnt ^= (arr[j] > arr[i]);
	}
	Q = read();
	for(int i = 1 ; i <= Q ; ++i){
		int l = read() , r = read() , all = (r - l + 1) * (r - l) / 2;
		cnt ^= all & 1;
		puts(cnt ? "odd" : "even");
	}
	return 0;
}