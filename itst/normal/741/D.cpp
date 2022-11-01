#include<bits/stdc++.h>
using namespace std;

const int _ = 5e5 + 7;
#define PII pair < int , int >
#define st first
#define nd second
vector < PII > ch[_]; int mx[1 << 22] , id[_] , ans[_] , sz[_] , son[_] , mrk1[_] , mrk2[_] , N;

void dfs1(int x){sz[x] = 1; for(auto t : ch[x]){dfs1(t.st); sz[x] += sz[t.st]; if(sz[son[x]] < sz[t.st]) son[x] = t.st;}}

void clr(int x , int v){mx[v] = -1e9; for(auto t : ch[x]) clr(t.st , v ^ t.nd);}

void add(int x , int v , int l){mx[v] = max(mx[v] , l); for(auto t : ch[x]) add(t.st , v ^ t.nd , l + 1);}

void dsu(int x , int v , int l , int &ans){
	ans = max(ans , mx[v] + l); for(int i = 0 ; i < 22 ; ++i) ans = max(ans , mx[v ^ (1 << i)] + l);
	for(auto t : ch[x]) dsu(t.st , v ^ t.nd , l + 1 , ans);
}

void dfs(int x){
	if(son[x]){
		for(auto t : ch[x]) if(t.st != son[x]){dfs(t.st); clr(t.st , mrk1[t.st]);} else mrk1[x] ^= t.nd;
		dfs(son[x]); mrk1[x] ^= mrk1[son[x]]; mrk2[x] = mrk2[son[x]] + 1;
		ans[x] = max(ans[x] , max(mx[mrk1[x]] + mrk2[x] , ans[son[x]]));
		for(int i = 0 ; i < 22 ; ++i) ans[x] = max(ans[x] , mrk2[x] + mx[mrk1[x] ^ (1 << i)]);
		mx[mrk1[x]] = max(mx[mrk1[x]] , -mrk2[x]);
		for(auto t : ch[x])
			if(t.st != son[x]){
				dsu(t.st , t.nd ^ mrk1[x] , 1 + mrk2[x] , ans[x] = max(ans[x] , ans[t.st]));
				add(t.st , t.nd ^ mrk1[x] , 1 - mrk2[x]);
			}
	}
	else mx[0] = 0;
}

int main(){
	ios::sync_with_stdio(0); cin >> N; memset(mx , -0x3f , sizeof(mx));
	for(int i = 2 ; i <= N ; ++i){int fa; char s; cin >> fa >> s; ch[fa].push_back(PII(i , 1 << (s - 'a')));}
	dfs1(1); dfs(1); for(int i = 1 ; i <= N ; ++i) printf("%d " , ans[i]);
	return 0;
}