#include<bits/stdc++.h>
typedef unsigned uint;
const uint MAXN=100000;
std::vector<uint>e[MAXN+5];
uint N;
uint Cnt[2];
void Dfs(uint u,uint fa,bool s){
	++Cnt[s];
	for(auto v:e[u]){
		if(v==fa)
			continue;
		Dfs(v,u,!s);
	}
}
int main(){
	scanf("%u",&N);
	for(uint i=1;i<N;++i){
		uint u,v;
		scanf("%u%u",&u,&v);
		e[u].push_back(v);
		e[v].push_back(u);
	}
	Dfs(1,0,0);
	printf("%u\n",Cnt[0]*Cnt[1]-N+1);
	return 0;
}