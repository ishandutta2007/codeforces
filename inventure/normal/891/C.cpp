#include <bits/stdc++.h>

using namespace std;

const int maxn = 5e5 + 50;

struct edg{
	int u , v , cost;
	edg( int u = 0 , int v = 0 , int cost = 0) : u( u ) , v( v ) , cost( cost ){}
}Edge[maxn];

int n , m , fa[maxn] , sz[maxn] , Q , id[maxn] , ans[maxn];
pair < int , int > Query[maxn];
vector < pair < int * , int > > Save;

int find_fa( int u ){
	while( u ^ fa[u] ) u = fa[u];
	return u;
}

inline void Read( int & x ){
	x = 0;
	char ch;
	for( ch = getchar() ; ch < '0' || ch > '9' ; ch = getchar() );
	for( ; ch <= '9' && ch >= '0' ; ch = getchar() ) x = x * 10 + ch - '0';
}

bool Union( int u , int v , int flag ){
	int p1 = find_fa( u ) , p2 = find_fa( v );
	if( p1 == p2 ) return false;
	if( sz[p1] > sz[p2] ) swap( p1 , p2 );
	if( flag ){
		Save.push_back( { & fa[p1] , fa[p1] } );
		Save.push_back( { & sz[p2] , sz[p2] } );
	}
	fa[p1] = fa[p2];
	sz[p2] += sz[p1];
	return true;
}

int main( int argc , char * argv[] ){
	Read( n ) , Read( m );
	for(int i = 1 ; i <= n ; ++ i) fa[i] = i , sz[i] = 1;
	for(int i = 1 ; i <= m ; ++ i){
		Read( Edge[i].u );
		Read( Edge[i].v );
		Read( Edge[i].cost );
		id[i] = i;
	}
	Read( Q );
	int len = 0;
	for(int i = 1 ; i <= Q ; ++ i){
		int num;
		Read( num );
		while( num -- ){
			int k;
			Read( k );
			Query[++ len] = { k , i };
		}
	}
	for(int i = 1 ; i <= Q ; ++ i) ans[i] = 1;
	sort( id + 1 , id + m + 1 , [ & ](const int & x , const int & y){
		return Edge[x].cost < Edge[y].cost;
	} );
	sort( Query + 1 , Query + len + 1 , [ & ](const pair < int , int > & x , const pair < int , int > & y ){
		return Edge[x.first].cost < Edge[y.first].cost || ( Edge[x.first].cost == Edge[y.first].cost && x.second < y.second);
	});
	for(int i = 1 , j = 1 ; i <= len ; ){
		while( j <= m && Edge[id[j]].cost < Edge[Query[i].first].cost ){
			Union( Edge[id[j]].u , Edge[id[j]].v , 0 );
			++ j;
		}
		int k = i;
		while( k <= len && Edge[Query[k].first].cost == Edge[Query[i].first].cost && Query[k].second == Query[i].second ){
			if( ans[ Query[k].second ] && !Union( Edge[ Query[k].first ].u , Edge[ Query[k].first ].v , 1 ) )
				ans[ Query[k].second ] = 0;
			++ k;
		}
		for(auto && it : Save) *it.first = it.second;
		Save.clear();
		i = k;
	}
	for(int i = 1 ; i <= Q ; ++ i)
		if( ans[i] ) puts( "YES" );
		else puts( "NO" );
	return 0;
}