#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<cmath>
#include<iomanip>
using namespace std;

int read(){
	int a = 0; char c = getchar(); bool f = 0; while(!isdigit(c)){f = c == '-'; c = getchar();}
	while(isdigit(c)){a = a * 10 + c - 48; c = getchar();} return f ? -a : a;
}

int N; map < int , long long > cnt;

int main(){
	N = read();
	for(int i = 1 ; i <= N ; ++i){int t = read(); cnt[t - i] += t;}
	long long mx = 0; for(auto t : cnt) mx = max(mx , t.second);
	cout << mx;
	return 0;
}