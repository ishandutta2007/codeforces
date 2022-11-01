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

#define ll long long
#define PII pair < int , int >
#define PIII pair < int , pair < int , int > >
#define st first
#define nd second
const int MOD = 998244353;
priority_queue < PIII > q;
int N , M;

inline int poww(ll a , int b){
	int times = 1;
	while(b){
		if(b & 1)
			times = times * a % MOD;
		a = a * a % MOD;
		b >>= 1;
	}
	return times;
}

int main(){
	#ifndef ONLINE_JUDGE
	//freopen("in" , "r" , stdin);
	//freopen("out" , "w" , stdout);
	#endif
	N = read();
	M = read();
	for(int i = 1 ; i <= N ; ++i)
		for(int j = 1 ; j <= M ; ++j)
			q.push(PIII(-read() , PII(i , j)));
	int x , cx = 0 , y , cy = 0 , sum , csum = 0 , cnt , ccnt = 0 , pre = -1 , X = read() , Y = read();
	bool f = 0;
	while(!q.empty()){
		PIII t = q.top();
		q.pop();
		if(-t.st > pre){
			if(pre >= 0)
				f = 1;
			pre = -t.st;
			x = cx;
			y = cy;
			sum = csum;
			cnt = ccnt;
		}
		int num = (((sum - 2ll * x * t.nd.st - 2ll * y * t.nd.nd) % MOD + MOD) % MOD * poww(cnt , MOD - 2) + t.nd.st * t.nd.st + t.nd.nd * t.nd.nd) % MOD;
		num *= f;
		if(t.nd.st == X && t.nd.nd == Y){
			cout << num;
			break;
		}
		++ccnt;
		cx = (cx + t.nd.st) % MOD;
		cy = (cy + t.nd.nd) % MOD;
		csum = (csum + num + t.nd.st * t.nd.st + t.nd.nd * t.nd.nd) % MOD;
	}
	return 0;
}