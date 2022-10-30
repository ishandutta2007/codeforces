#include<cstdio>
#include<iostream>
#include<cstring>
#include<iomanip>
#include<cmath>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<bitset>
#include<random>
#include<unistd.h>
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

int now[7003] , arr[7003] , val[7003] , sum , N;
bool flg[7003][7003]; bool vis[7003];

signed main(){
    ios::sync_with_stdio(0);
	cin >> N;
	for(int i = 1 ; i <= N ; ++i){
		cin >> arr[i];
		for(int j = 1 ; j < i ; ++j){
			flg[i][j] = (arr[i] & (((1ll << 60) - 1) ^ arr[j])) != 0;
			flg[j][i] = (arr[j] & (((1ll << 60) - 1) ^ arr[i])) != 0;;
		}
	}
	for(int i = 1 ; i <= N ; ++i){
		cin >> val[i]; sum += val[i];
	}
	int cur = 0; queue < int > q;
	for(int i = 1 ; i <= N ; ++i){
		for(int j = 1 ; j <= N ; ++j) now[i] += flg[i][j];
		if(now[i] == N - 1){vis[i] = 1; q.push(i);}
	}
	while(!q.empty()){
		int t = q.front(); q.pop(); sum -= val[t]; ++cur;
		for(int i = 1 ; i <= N ; ++i)
			if(!vis[i] && (now[i] -= flg[i][t]) == N - cur - 1){
				vis[i] = 1; q.push(i);
			}
	}
	cout << sum;
	return 0;
}