#include<bits/stdc++.h>
using namespace std;

const int _ = 4e5 + 7; struct Edge{int end , upEd;}Ed[_ << 1]; int head[_] , cntEd = 1 , S[_] , T[_] , N , M;
void addEd(int a , int b){Ed[++cntEd] = (Edge){b , head[a]}; head[a] = cntEd;}
int fa[_] , sz[_]; int find(int x){return fa[x] == x ? x : (fa[x] = find(fa[x]));}
vector < int > pot[_];

int dep[_] , du[_];
void dfs(int x , int id){
	du[x] = 0;
	for(int i = head[x] ; i ; i = Ed[i].upEd)
		if((i >> 1) != id)
			if(!dep[Ed[i].end]){dep[Ed[i].end] = dep[x] + 1; dfs(Ed[i].end , i >> 1); du[x] ^= !du[Ed[i].end];}
			else if(dep[Ed[i].end] <= dep[x]){du[x] ^= 1; S[i >> 1] = x; T[i >> 1] = Ed[i].end;}
	if(du[x] ^ (S[id] == x)) swap(S[id] , T[id]);
}

int main(){
	ios::sync_with_stdio(0); cin >> N >> M; for(int i = 1 ; i <= N ; ++i) fa[i] = i;
	for(int i = 1 ; i <= M ; ++i){cin >> S[i] >> T[i]; fa[find(S[i])] = find(T[i]); du[S[i]] ^= 1; du[T[i]] ^= 1;}
	for(int i = 1 ; i <= M ; ++i) sz[find(S[i])] ^= 1;
	for(int i = 1 ; i <= N ; ++i) if(du[i]) pot[find(i)].push_back(i);
	int p = 0;
	for(int i = 1 ; i <= N ; ++i)
		if(fa[i] == i)
			if((sz[i] + pot[i].size() / 2) & 1)
				if(pot[i].size())
					if(p){
						while(pot[p].size() && pot[i].size()){
							S[++M] = pot[p].back(); T[M] = pot[i].back(); pot[p].pop_back(); pot[i].pop_back();
						}
						while(pot[p].size()){S[++M] = pot[p].back(); pot[p].pop_back(); T[M] = pot[p].back(); pot[p].pop_back();}
						while(pot[i].size()){S[++M] = pot[i].back(); pot[i].pop_back(); T[M] = pot[i].back(); pot[i].pop_back();}
						p = 0;
					}else p = i;
				else{++M; S[M] = T[M] = i;}
			else while(pot[i].size()){S[++M] = pot[i].back(); pot[i].pop_back(); T[M] = pot[i].back(); pot[i].pop_back();}
	if(p){++M; S[M] = T[M] = p; while(pot[p].size()){S[++M] = pot[p].back(); pot[p].pop_back(); T[M] = pot[p].back(); pot[p].pop_back();}}
	
	for(int i = 1 ; i <= M ; ++i){addEd(S[i] , T[i]); if(S[i] != T[i]) addEd(T[i] , S[i]); else addEd(0 , 0);}
	for(int i = 1 ; i <= N ; ++i) if(!dep[i]){dep[i] = 1; dfs(i , 0);}
	cout << M << '\n'; for(int i = 1 ; i <= M ; ++i) cout << S[i] << ' ' << T[i] << '\n';
	return 0;
}