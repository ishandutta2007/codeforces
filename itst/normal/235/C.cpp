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

const int MAXN = 2e6 + 7;
char S[MAXN] , T[MAXN];
int L , L1;
namespace SAM{
	int Lst[MAXN] , Sst[MAXN] , trans[MAXN][26] , fa[MAXN] , endpos[MAXN];
	int cnt = 1 , lst = 1;

	void insert(int len , int x){
		int t = ++cnt , p = lst;
		Lst[lst = t] = len;
		endpos[t] = 1;
		while(p && !trans[p][x]){
			trans[p][x] = t;
			p = fa[p];
		}
		if(!p){
			fa[t] = Sst[t] = 1;
			return;
		}
		int q = trans[p][x];
		Sst[t] = Lst[p] + 2;
		if(Lst[q] == Lst[p] + 1){
			fa[t] = q;
			return;
		}
		int k = ++cnt;
		Sst[k] = Sst[q];
		Lst[k] = Lst[p] + 1;
		Sst[q] = Lst[p] + 2;
		memcpy(trans[k] , trans[q] , sizeof(int) * 26);
		fa[k] = fa[q];
		fa[q] = fa[t] = k;
		while(trans[p][x] == q){
			trans[p][x] = k;
			p = fa[p];
		}
	}

	int in[MAXN];
	queue < int > q;
	void init(){
		endpos[1] = 1;
		scanf("%s" , S + 1);
		L = strlen(S + 1);
		for(int i = 1 ; i <= L ; ++i)
			insert(i , S[i] - 'a');
		for(int i = 2 ; i <= cnt ; ++i)
			++in[fa[i]];
		for(int i = 2 ; i <= cnt ; ++i)
			if(!in[i])
				q.push(i);
		while(!q.empty()){
			int t = q.front();
			q.pop();
			if(t == 1)
				continue;
			endpos[fa[t]] += endpos[t];
			if(!--in[fa[t]])
				q.push(fa[t]);
		}
	}

	bool vis[MAXN];
	void work(){
		scanf("%s" , T + 1);
		int Q = L1 = strlen(T + 1);
		for(int i = 1 ; i < L1 ; ++i)
			T[L1 + i] = T[i];
		L1 = L1 * 2 - 1;
		int cur = 1 , len = 0 , ans = 0;
		for(int i = 1 ; i <= L1 ; ++i){
			if(trans[cur][T[i] - 'a']){
				++len;
				cur = trans[cur][T[i] - 'a'];
			}
			else{
				while(cur && !trans[cur][T[i] - 'a'])
					cur = fa[cur];
				if(!cur){
					len = 0;
					cur = 1;
				}
				else{
					len = Lst[cur] + 1;
					cur = trans[cur][T[i] - 'a'];
				}
			}
			while(Sst[cur] > Q){
				cur = fa[cur];
				len = Lst[cur];
			}
			if(len >= Q && !vis[cur]){
				ans += endpos[cur];
				vis[cur] = 1;
			}
		}
		cout << ans << '\n';
		cur = 1;
		for(int i = 1 ; i <= L1 ; ++i){
			while(cur && !trans[cur][T[i] - 'a'])
				cur = fa[cur];
			if(!cur)
				cur = 1;
			else
				cur = trans[cur][T[i] - 'a'];
			while(Sst[cur] > Q)
				cur = fa[cur];
			vis[cur] = 0;
		}
	}
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
	//freopen("out","w",stdout);
#endif
	SAM::init();
	for(int K = read() ; K ; --K)
		SAM::work();
	return 0;
}