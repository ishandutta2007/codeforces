#include<iostream>
#include<cstdio>
#include<set>
#include<vector>
#include<map>
#define ll int
#define int long long 
#define N 60005
using namespace std;

std::map<int,int>cnt[N];
std::vector<int>e[N];
std::vector<int>va[N];
int n;

int siz[N],son[N],head[N],hcnt;
int s[N],k;

inline void dfs(int u,int f){
	siz[u] = 1;
//	std::cout<<u<<" "<<s[u]<<std::endl;
	for(int i = 0;i < e[u].size();++i){
		int v = e[u][i];
		if(v == f)continue;
		s[v] = s[u] + va[u][i];
		dfs(v,u);
		if(siz[v] > siz[son[u]])
		son[u] = v;
		siz[u] += siz[v];
	}
}

ll ans = 0;

std::map<int,int>::iterator it;

inline void solve(int u,int f){
	if(!son[u])head[u] = ++ hcnt;
	if(son[u])solve(son[u],u),head[u] = head[son[u]];
	for(int i = 0;i < e[u].size();++i){
		int v = e[u][i];
		if(v == f || v == son[u])continue;
		solve(v,u);
		it = cnt[head[v]].begin();
		while(it != cnt[head[v]].end()){
			if(cnt[head[u]].find(k + 2 * s[u] - (it -> first)) != cnt[head[u]].end())
			ans += (it -> second) * cnt[head[u]][k + 2 * s[u] - (it -> first)];
			++it;
		}
		it = cnt[head[v]].begin();
		while(it != cnt[head[v]].end())
		cnt[head[u]][it -> first] += (it -> second) ,++it;		
	}
	if(cnt[head[u]].find(k + s[u]) != cnt[head[u]].end())
	ans += cnt[head[u]][k + s[u]];	
	cnt[head[u]][s[u]] ++ ;	
//	std::cout<<u<<":"<<std::endl;
//	it = cnt[head[u]].begin();
//	while(it != cnt[head[u]].end())
//	std::cout<<"("<<it -> first<<","<<it -> second<<")"<<std::endl,it ++ ;	
//	std::cout<<ans<<std::endl;
//	puts("");	
}

signed main(){
	cin>>n>>k;
	for(int i = 1;i < n;++i){
		int x,y,v;
		cin>>x>>y;
		v = 1; 
		e[x].push_back(y);
		va[x].push_back(v);
		e[y].push_back(x);
		va[y].push_back(v);
	}
	dfs(1,0);
	solve(1,0);
	std::cout<<ans<<std::endl;
}
/*
11 4
2 1
3 1
4 2
5 2
6 3
7 3
8 4
9 4
10 5
11 5
*/