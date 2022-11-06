#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 50;

struct Edge{
	int u ,v ,nxt ;
};

Edge e[maxn * 2];
int n ,tot,head[maxn],fa[maxn],son[maxn],top[maxn],idx[maxn],dfs_clock,deep[maxn] , Q;
void addedge(int u ,int v){
	e[tot].v=v,e[tot].nxt=head[u],head[u]=tot++;
}

int dfs1(int u){
	int sz = 0 , res = 1;
	for(int i = head[u] ; ~i ; i = e[i].nxt){
		int v = e[i].v;
		if(v==fa[u]) continue;
		fa[v] = u,deep[v]=deep[u]+1;
		int t = dfs1(v);
		if(t > sz){
			sz = t;
			son[u] = v;
		}
		res += t;
	}
	return res;
}

void dfs2(int u ,int tp){
	top[u] = tp , idx[u] = ++dfs_clock;
	if(son[u]) dfs2(son[u],tp);
	for(int i = head[u] ; ~i ; i = e[i].nxt){
		int v = e[i].v;
		if(v==fa[u]||v==son[u]) continue;
		dfs2(v,v);
	}
}

vector < pair < int , int > > f1 , f2;

void modify(int u ,int v , vector < pair < int , int > > & x){
	int f1 = top[u] , f2 = top[v];
	while(f1 != f2){
		if(deep[f1] < deep[f2]) swap(f1,f2),swap(u,v);
		x.push_back( make_pair( idx[f1] , idx[u] ) );
		u = fa[top[u]],f1=top[u];
	}
	if(deep[u] > deep[v]) swap(u,v);
	x.push_back( make_pair( idx[u] , idx[v] ) );
}

int Ff(pair < int , int > L,pair < int , int > R){
	if(L.first > R.first) swap(L,R);
	if(R.first > L.second) return 0;
	else return min(R.second,L.second)-R.first + 1;
}

int getans(){
	int ret = 0;
	for(auto & x : f1)
		for(auto & y : f2)
			ret += Ff( x , y );
	return ret;
}

int z[3] , ar[3];

int main( int argc , char * argv[] ){
	scanf( "%d%d" , & n , & Q );
	memset( head , -1 , sizeof( head ) );
	for(int i = 2 ; i <= n ; ++ i){
		int fa;
		scanf( "%d" , & fa );
		addedge( fa , i );
		addedge( i , fa );
	}
	dfs1( 1 );
	dfs2( 1 , 1 );
	while( Q -- ){
		int mx = 0;
		for(int i = 0 ; i < 3 ; ++ i)
			scanf( "%d" , ar + i );
		f1.clear();
		f2.clear();
		{
			int a = ar[1] , b = ar[0] , c = ar[2];
			modify( a , b , f1 );
			modify( b , c , f2 );
			mx = max( mx , getans() );
		}
		f1.clear();
		f2.clear();
		{
			int a = ar[0] , b = ar[1] , c = ar[2];
			modify( a , b , f1 );
			modify( b , c , f2 );
			mx = max( mx , getans() );
		}
		f1.clear();
		f2.clear();
		{
			int a = ar[0] , b = ar[2] , c = ar[1];
			modify( a , b , f1 );
			modify( b , c , f2 );
			mx = max( mx , getans() );
		}
		printf( "%d\n" , mx );
	}
	return 0;
}