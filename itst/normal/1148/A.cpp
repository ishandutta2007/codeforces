#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstring>
#include<iomanip>
#include<cmath>
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

signed main(){
	#define int long long
	int a , b , c;
	cin >> a >> b >> c;
	int ans = c * 2;
	int t = min(a , b);
	if(a > t || b > t) ++ans;
	cout << ans + 2 * t;
	return 0;
}