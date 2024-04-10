#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstring>
#include<iomanip>
#include<cmath>
#include<cassert>
//This code is written by Itst
using namespace std;

int read(){
	int a = 0; bool f = 0;
	char c = getchar();
	while(!isdigit(c)){f = c == '-'; c = getchar();}
	while(isdigit(c)){
		a = a * 10 + c - 48; c = getchar();
	}
	return f ? -a : a;
}

#define int long long
int tms[100003];
bool flg[100003];

signed main(){
	int x = 0 , top = 0 , N; tms[0] = 1;
	cin >> N;
	for(int i = 1 ; i <= N ; ++i){
		string s; cin >> s;
		if(s == "add")
			if(flg[top] || x + tms[top] >= (1ll << 32)){
				puts("OVERFLOW!!!"); return 0;
			}
			else
				x += tms[top];
		else
			if(s == "end") --top;
			else{
				int x; cin >> x;
				++top;
				if(flg[top - 1] || 1ll * tms[top - 1] * x >= (1ll << 32))
					flg[top] = 1;
				else{flg[top] = 0; tms[top] = 1ll * tms[top - 1] * x;}
			}
	}
	cout << x;
	return 0;
}