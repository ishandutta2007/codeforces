#include<bits/stdc++.h>
using namespace std;

int read(){
	int a = 0; char c = getchar(); while(!isdigit(c)) c = getchar();
	while(isdigit(c)){a = a * 10 + c - 48; c = getchar();} return a;
}

char getc(){char c = getchar(); while(!isupper(c)) c = getchar(); return c;}

const int _ = 1e6 + 7;
long long sz[_] , fa[_] , val[_] , N , M , ans[_]; bool isq[_];
struct qry{int tp , t , x , y , id;}; vector < qry > tmp;
int find(int x , bool flg){
	if(fa[fa[x]] == fa[x]) return fa[x];
	int t = find(fa[x] , flg); val[x] = flg ? max(val[x] , val[fa[x]]) : val[x] + val[fa[x]]; return fa[x] = t;
}

int main(){
	int cnt = N = read(); M = read(); for(int i = 1 ; i <= 2 * N ; ++i) fa[i] = i;
	for(int x , y , i = 1 ; i <= M ; ++i)
		switch(getc()){
		case 'U': x = read(); y = read(); tmp.push_back((qry){0 , i , x , y}); break;
		case 'M': x = read(); y = read(); ++cnt; fa[find(x , 1)] = fa[find(y , 1)] = cnt; break;
		case 'A': tmp.push_back((qry){-1 , i , read()}); break;
		case 'Z': val[find(read() , 1)] = i; break;
		case 'Q':
			x = read(); isq[i] = 1; tmp.push_back((qry){1 , i , x , 1 , i});
			y = find(x , 1); if(max(val[x] , val[y])) tmp.push_back((qry){1 , max(val[x] , val[y]) , x , -1 , i});
			break;
		}
	sort(tmp.begin() , tmp.end() , [&](qry p , qry q){return p.t < q.t;});
	for(int i = 1 ; i <= 2 * N ; ++i){fa[i] = i; val[i] = 0; sz[i] = 1;} cnt = N;
	
	for(auto t : tmp)
		switch(t.tp){
		case -1: val[find(t.x , 0)] += sz[find(t.x , 0)]; break;
		case 0: t.x = find(t.x , 0); t.y = find(t.y , 0); ++cnt; sz[cnt] = sz[t.x] + sz[t.y]; fa[t.x] = fa[t.y] = cnt; break;
		case 1: find(t.x , 0); ans[t.id] += t.y * (val[t.x] + (fa[t.x] == t.x ? 0 : val[fa[t.x]]));
		}
	for(int i = 1 ; i <= M ; ++i) if(isq[i]) printf("%lld\n" , ans[i]);
	
	return 0;
}