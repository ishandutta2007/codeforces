#include<bits/stdc++.h>
using namespace std;

const int _ = 5e5 + 7;
int fa[_] , ch[_][26] , cnt = 1; char str[_];

int ins(){
	int rt = 1;
	for(int i = 1 ; str[i] ; ++i){
		if(!ch[rt][str[i] - 'a'])
			fa[ch[rt][str[i] - 'a'] = ++cnt] = rt;
		rt = ch[rt][str[i] - 'a'];
	}return rt;
}

int ts , fail[_] , dfn[_] , sz[_]; vector < int > nxt[_];
void build(){
	queue < int > q;
	for(int i = 0 ; i < 26 ; ++i)
		if(!ch[1][i]) ch[1][i] = 1; else{fail[ch[1][i]] = 1; q.push(ch[1][i]);}
	while(!q.empty()){
		int t = q.front(); q.pop(); nxt[fail[t]].push_back(t);
		for(int i = 0 ; i < 26 ; ++i)
			if(!ch[t][i]) ch[t][i] = ch[fail[t]][i];
			else{fail[ch[t][i]] = ch[fail[t]][i]; q.push(ch[t][i]);}
	}
}
void dfs(int x){dfn[x] = ++ts; sz[x] = 1; for(auto t : nxt[x]){dfs(t); sz[x] += sz[t];}}

int arr[_];
#define lowbit(x) x & -x
void add(int x , int val){while(x <= cnt){arr[x] += val; x += lowbit(x);}}
int get(int x){int sum = 0; while(x){sum += arr[x]; x -= lowbit(x);} return sum;}

int N , Q , id[_] , l[_] , r[_] , p[_] , ans[_]; vector < pair < int , int > > qry[_];

int main(){
	scanf("%d %d" , &N , &Q); for(int i = 1 ; i <= N ; ++i){scanf("%s" , str + 1); id[i] = ins();}
	build(); dfs(1);
	for(int i = 1 ; i <= Q ; ++i){
		scanf("%d %d %d" , l + i , r + i , p + i);
		qry[l[i] - 1].push_back(make_pair(i , -1));
		qry[r[i]].push_back(make_pair(i , 1));
	}
	for(int i = 1 ; i <= N ; ++i){
		for(int j = id[i] ; j ; j = fa[j]) add(dfn[j] , 1);
		for(auto t : qry[i])
			ans[t.first] += t.second * (get(dfn[id[p[t.first]]] + sz[id[p[t.first]]] - 1) - get(dfn[id[p[t.first]]] - 1));
	}
	for(int i = 1 ; i <= Q ; ++i) printf("%d\n" , ans[i]);
	return 0;
}