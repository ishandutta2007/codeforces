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

int N;
struct node{
	int ch[10] , sum[2007] , fail;
}Trie[16017];
int cnt = 1 , L1 , L2;
char L[807] , R[807];

#define get(x , y) (!Trie[x].ch[y] ? Trie[x].ch[y] = ++cnt : Trie[x].ch[y])

void insert(){
	L1 = strlen(L + 1) , L2 = strlen(R + 1);
	int u = 1 , v = 1;
	if(L1 == L2){
		for(int j = 1 ; j <= L1 ; ++j)
			if(u == v){
				for(int k = L[j] - '0' + 1 ; k < R[j] - '0' ; ++k)
					++Trie[get(u , k)].sum[L1 - j];
				u = get(u , L[j] - '0');
				v = get(v , R[j] - '0');
			}
			else{
				for(int k = L[j] - '0' + 1 ; k <= 9 ; ++k)
					++Trie[get(u , k)].sum[L1 - j];
				u = get(u , L[j] - '0');
				for(int k = j == 1 ; k < R[j] - '0' ; ++k)
					++Trie[get(v , k)].sum[L2 - j];
				v = get(v , R[j] - '0');
			}
		++Trie[u].sum[0];Trie[v].sum[0] += u != v;
	}
	else{
		for(int j = 1 ; j <= L1 ; ++j){
			for(int k = L[j] - '0' + 1 ; k <= 9 ; ++k)
				++Trie[get(u , k)].sum[L1 - j];
			u = get(u , L[j] - '0');
		}
		for(int j = 1 ; j <= L2 ; ++j){
			for(int k = j == 1 ; k < R[j] - '0' ; ++k)
				++Trie[get(v , k)].sum[L2 - j];
			v = get(v , R[j] - '0');
		}
		for(int j = L1 + 1 ; j < L2 ; ++j)
			for(int k = 1 ; k <= 9 ; ++k)
				++Trie[get(1 , k)].sum[j - 1];
		++Trie[u].sum[0];++Trie[v].sum[0];
	}
}

void build(){
	queue < int > q;
	for(int i = 0 ; i < 10 ; ++i)
		if(!Trie[1].ch[i])
			Trie[1].ch[i] = 1;
		else{
			Trie[Trie[1].ch[i]].fail = 1;
			q.push(Trie[1].ch[i]);
		}
	while(!q.empty()){
		int t = q.front();
		q.pop();
		for(int j = 0 ; j < L2 ; ++j)
			Trie[t].sum[j] += Trie[Trie[t].fail].sum[j];
		for(int i = 0 ; i < 10 ; ++i)
			if(!Trie[t].ch[i])
				Trie[t].ch[i] = Trie[Trie[t].fail].ch[i];
			else{
				Trie[Trie[t].ch[i]].fail = Trie[Trie[t].fail].ch[i];
				q.push(Trie[t].ch[i]);
			}
	}
	for(int i = 1 ; i <= cnt ; ++i)
		for(int j = 1 ; j < N ; ++j)
			Trie[i].sum[j] += Trie[i].sum[j - 1];
}

void init(){
	scanf("%s %s %d" , L + 1 , R + 1 , &N);
	insert();
	build();
}

int dp[2007][16017];
bool can[2007][16017];

inline int maxx(int a , int b){
	return a > b ? a : b;
}

int main(){
	init();
	memset(dp , -0x3f , sizeof(dp));
	dp[0][1] = 0;
	for(int i = 0 ; i < N ; ++i)
		for(int j = 1 ; j <= cnt ; ++j)
			if(dp[i][j] >= 0)
				for(int k = 0 ; k < 10 ; ++k)
					dp[i + 1][Trie[j].ch[k]] = maxx(dp[i + 1][Trie[j].ch[k]] , dp[i][j] + Trie[Trie[j].ch[k]].sum[N - i - 1]);
	int ans = 0;
	for(int i = 1 ; i <= cnt ; ++i)
		ans = maxx(ans , dp[N][i]);
	cout << ans << endl;
	for(int i = 1 ; i <= cnt ; ++i)
		can[N][i] = (dp[N][i] == ans);
	for(int i = N - 1 ; i >= 0 ; --i)
		for(int j = 1 ; j <= cnt ; ++j)
			if(dp[i][j] >= 0)
				for(int k = 0 ; !can[i][j] && k < 10 ; ++k)
					can[i][j] = can[i + 1][Trie[j].ch[k]] && (dp[i + 1][Trie[j].ch[k]] == dp[i][j] + Trie[Trie[j].ch[k]].sum[N - i - 1]);
	int u = 1;
	for(int i = 1 ; i <= N ; ++i)
		for(int j = 0 ; j < 10 ; ++j)
			if(can[i][Trie[u].ch[j]] && (dp[i][Trie[u].ch[j]] == dp[i - 1][u] + Trie[Trie[u].ch[j]].sum[N - i])){
				putchar(j + '0');
				u = get(u , j);
				break;
			}
	return 0;
}