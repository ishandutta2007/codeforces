#include<bits/stdc++.h>
#define ll long long
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

const int MAXN = 1e5 + 7;
ll num[MAXN] , sum;
int N , last;

int main(){
	#ifndef ONLINE_JUDGE
	//freopen("in" , "r" , stdin);
	//freopen("out" , "w" , stdout);
	#endif
	N = read();
	last = read();
	int minN = 1e9;
	for(int i = 1 ; i <= N ; ++i){
		num[i] = read();
		minN = min((ll)minN , num[i]);
	}
	for(int i = 1 ; i <= N ; ++i)
		num[i] -= minN;
	sum = 1ll * minN * N;
	while(num[last]){
		++sum;
		--num[last];
		last == 1 ? last = N : --last;
	}
	num[last] = sum;
	for(int i = 1 ; i <= N ; ++i)
		cout << num[i] << ' ';
	return 0;
}