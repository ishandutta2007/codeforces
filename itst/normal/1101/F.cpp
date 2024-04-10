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

#define int long long
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

const int MAXN = 2.5e5 + 7;
struct que{
	int s , f , c , r , ind;
	bool operator <(const que a)const{
		return s < a.s;
	}
};
int dp[410][410] , pos[410];
int N , M , ans;
deque < int > q;
vector < que > query;

inline void push(int j , int k){
	while(!q.empty() && dp[q.back()][k] >= dp[j][k])
		q.pop_back();
	q.push_back(j);
}

inline void maintain(int j , int k){
	while(q.size() > 1 && pos[j] - pos[q[0]] >= dp[q[1]][k])
		q.pop_front();
}

signed main(){
	N = read();
	M = read();
	for(int i = 1 ; i <= N ; ++i)
		pos[i] = read();
	for(int i = 1 ; i <= M ; ++i){
		que now;
		now.s = read();
		now.f = read();
		now.c = read();
		now.r = min(read() + 1 , now.f - now.s);
		now.ind = i;
		query.push_back(now);
	}
	sort(query.begin() , query.end());
	int p = 1;
	for(int i = 1 ; i <= N ; ++i){
		memset(dp , 0x1f , sizeof(dp));
		dp[i][0] = 0;
		for(int j = 1 ; j <= N - i ; ++j){
			q.empty();
			for(int k = i ; k < i + j ; ++k)
				push(k , j - 1);
			for(int k = i + j ; k <= N ; ++k){
				maintain(k , j - 1);
				dp[k][j] = max(dp[q.front()][j - 1] , pos[k] - pos[q.front()]);
				push(k , j - 1);
			}
		}
		while(p < M && query[p].s == i){
			ans = max(ans , dp[query[p].f][query[p].r] * query[p].c);
			++p;
		}
	}
	cout << ans;
	return 0;
}