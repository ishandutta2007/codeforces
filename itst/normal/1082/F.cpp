#include<iostream>
#include<cstdio>
#include<cstring>
//This code is written by Itst
using namespace std;

int ch[507][10] , val[507] , dp[507][11][507] , tp[11][507];
int N , K , cnt = 1 , maxLen;

void insert(string s , int w){
	int cur = 1;
	for(auto c : s){
		if(!ch[cur][c - '0']) ch[cur][c - '0'] = ++cnt;
		cur = ch[cur][c - '0'];
	}
	val[cur] += w;
	maxLen = max(maxLen , (int)s.size());
}

void calc(int x){
	memset(dp[x] , 0x3f , sizeof(dp[x]));
	memset(dp[x][0] , 0 , sizeof(dp[x][0]));
	for(int i = 0 ; i < 10 ; ++i)
		if(ch[x][i]){
			calc(ch[x][i]);
			memset(tp , 0x7f , sizeof(tp));
			for(int j = 0 ; j <= K ; ++j)
				for(int k = 0 ; k + j <= K ; ++k)
					for(int l = 0 ; l < maxLen ; ++l)
						tp[j + k][l] = min(tp[j + k][l] , dp[x][j][l] + dp[ch[x][i]][k][l + 1]);
			memcpy(dp[x] , tp , sizeof(tp));
		}
	for(int j = 0 ; j <= K ; ++j)
		for(int k = 0 ; k <= maxLen ; ++k)
			dp[x][j][k] += k * val[x];
	for(int j = 0 ; j < K ; ++j)
		for(int k = 1 ; k <= maxLen ; ++k)
			dp[x][j + 1][k] = min(dp[x][j + 1][k] , dp[x][j][0]);
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
	//freopen("out","w",stdout);
#endif
	cin >> N >> K;
	for(int i = 1 ; i <= N ; ++i){
		string s;
		int w;
		cin >> s >> w;
		insert(s , w);
	}
	calc(1);
	int minN = 1e9;
	for(int i = 0 ; i <= K ; ++i)
		minN = min(minN , dp[1][i][0]);
	cout << minN;
	return 0;
}