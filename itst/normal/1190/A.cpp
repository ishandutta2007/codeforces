#include<bits/stdc++.h>
//This code is written by Itst
using namespace std;

#define int long long
int read(){
	int a = 0; char c = getchar(); bool f = 0;
	while(!isdigit(c)){f = c == '-'; c = getchar();}
	while(isdigit(c)){
		a = a * 10 + c - 48; c = getchar();
	}
	return f ? -a : a;
}

signed main(){
#ifndef ONLINE_JUDGE
	//freopen("in","r",stdin);
	//freopen("out","w",stdout);
#endif
	int N , M , K;
	static int p[100003];
	N = read(); M = read(); K = read();
	for(int i = 1 ; i <= M ; ++i) p[i] = read() - 1;
	int pos = 0 , cnt = 0;
	for(int i = 1 ; i <= M ; i = pos){
		pos = i; ++cnt;
		while(pos <= M && (p[pos] - i + 1) / K == (p[i] - i + 1) / K) ++pos;
	}
	cout << cnt;
	return 0;
}