#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 50;

priority_queue < int > pq;
vector < int > ReverseEdge[maxn];

int n , m , ans[maxn] , degree[maxn];

int main( int argc , char * argv[] ){
	scanf( "%d%d" , & n , & m );
	for(int i = 1 ; i <= m ; ++ i){
		int u , v ;
		scanf( "%d%d" , & u , & v );
		degree[u] ++ ;
		ReverseEdge[v].emplace_back( u );
	}
	for(int i = 1 ; i <= n ; ++ i)
		if( !degree[i] )
			pq.push( i );
	for(int i = n ; i >= 1 ; -- i){
		int x = pq.top();pq.pop();
		ans[x] = i;
		for(auto v : ReverseEdge[x])
			if( --degree[v] == 0 )
				pq.push( v );
	}
	for(int i = 1 ; i <= n ; ++ i)
		printf( "%d " , ans[i] );
	puts( "" );
	return 0;
}