#include<bits/stdc++.h>
using namespace std;
 
int read(){
	int a = 0; char c = getchar(); bool f = 0;
	while(!isdigit(c)){f = c == '-'; c = getchar();}
	while(isdigit(c)){
		a = a * 10 + c - 48; c = getchar();
	}
	return f ? -a : a;
}
 
const int _ = 1003; int sz[_] , N , mn = 1e9 , rt; vector < int > nxt[_];
 
void dfs(int x , int p){
	sz[x] = 1; int mx = 0;
	for(auto t : nxt[x])
		if(t != p){dfs(t , x); sz[x] += sz[t]; mx = max(mx , sz[t]);}
	if((mx = max(mx , N - sz[x])) <= mn){mn = mx; rt = x;}
}
 
void dfs1(int x , int p , int l , int r , int tms){
	printf("%d %d %d\n" , x , p , l * tms);
	r = r - l; l = 1;
	for(auto t : nxt[x]) if(t != p){dfs1(t , x , l , l + sz[t] - 1 , tms); l += sz[t];}
}
 
int main(){
	N = read();
	if(N == 1) return 0;
	if(N == 2){puts("1 2 1"); return 0;}
	for(int i = 1 ; i < N ; ++i){
		int a = read() , b = read();
		nxt[a].push_back(b); nxt[b].push_back(a);
	}
#define PIV pair < int , vector < int > >
	priority_queue < PIV > q; vector < int > tmp;
	dfs(1 , 0); int t = rt; dfs(t , 0);
	for(auto x : nxt[t]){
		tmp.clear(); tmp.push_back(x);
		q.push(make_pair(-sz[x] , tmp));
	}
	while(q.size() > 2){
		PIV m = q.top(); q.pop(); PIV n = q.top(); q.pop();
		m.first += n.first;
		m.second.insert(m.second.end() , n.second.begin() , n.second.end());
		q.push(m);
	}
	PIV m = q.top(); q.pop(); PIV n = q.top(); int cur = 1;
	for(auto x : m.second){dfs1(x , t , cur , cur + sz[x] - 1 , 1); cur += sz[x];}
	cur = 1;
	for(auto x : n.second){dfs1(x , t , cur , cur + sz[x] - 1 , -m.first + 1); cur += sz[x];}
	return 0;
}