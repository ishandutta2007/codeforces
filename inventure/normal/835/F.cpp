#include <bits/stdc++.h>

inline int read(){int x=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}
using namespace std;
const long long inf = 0x3f3f3f3f3f3f3f3f;
const int maxn = 2e5 + 50;

int n , vis[maxn] , Seq[maxn << 1] , Seqlen;
long long Sum[maxn] , Dp[maxn] , ans , Sr[maxn] , Ms[maxn << 1] , pf[maxn] , sf[maxn] , g1[maxn] , g2[maxn];
vector < pair < int , int > > Edge[maxn];
vector < int > otk;
map < pair < int , int > , int > dist;

int Dfs_Circle( int u , int fa = 0 ){
	vis[u] = 1;
	for(auto && it : Edge[u]){
		int v = it.first;
		if( v == fa )
			continue;
		if( vis[v] ){
			otk.emplace_back( u );
			return v;
		}
		int z = Dfs_Circle( v , u );
		if( ~z ){
			otk.emplace_back( u );
			if( z == u )
				return -1;
			return z;
		}
	}
	return -1;
}

queue < int > que;

void Solve( int root ){
	vis[root] = 0;
	vector < int > vi;
	function < void( int , vector < int >& ) > Bfs = [&]( int base , vector < int > & seq ){
		Sr[base] = 0;
		que.push( base );
		while( !que.empty() ){
			int x = que.front() ; que.pop();
			seq.emplace_back( x );
			for(auto && it : Edge[x]){
				int v = it.first , c = it.second;
				if( !vis[v] && Sr[v] == inf ){
					Sr[v] = Sr[x] + c;
					que.push( v );
				}
			}
		}
	};
	Bfs( root , vi );
	int z = root;
	for(auto & it : vi){
		Dp[root] = max( Dp[root] , Sr[it] );
		if( Sr[it] > Sr[z] )
			z = it;
	}
	for(auto & it : vi)
		Sr[it] = inf;
	vi.clear();
	Bfs( z , vi );
	for(auto & it : vi)
		ans = max( ans , Sr[it] );
	vis[root] = 1;
}

int main( int argc , char * argv[] ){
	n = read();
	memset( Sr , 0x3f , sizeof( Sr ) );
	for(int i = 1 ; i <= n ; ++ i){
		int u = read() , v = read() , l = read();
		Edge[u].emplace_back( make_pair( v , l ) );
		Edge[v].emplace_back( make_pair( u , l ) );
		dist[make_pair( u , v )] = dist[make_pair( v , u)] = l;
	}
	Dfs_Circle( 1 );
	memset( vis , 0 , sizeof( vis ) );
	for(auto && it : otk) Seq[++ Seqlen] = it;
	for(auto && it : otk) vis[it] = 1;
	for(int i = 2 ; i <= Seqlen ; ++ i)
		Sum[i] = Sum[i - 1] + dist[make_pair( Seq[i] , Seq[i - 1] )];
	for(auto && it : otk)
		Solve( it );
	long long Final = 1e18 , Mx = 0;
	for(int i = 1 ; i <= Seqlen ; ++ i){
		pf[i] = max( pf[i - 1] , Dp[ Seq[i] ] + Sum[i] + Mx );
		Mx = max( Mx , Dp[ Seq[i] ] - Sum[i] );
		g1[i] = max( g1[i - 1] , Dp[ Seq[i] ] + Sum[i] );
	}
	Mx = Sum[Seqlen];
	for(int i = Seqlen ; i >= 1 ; -- i){
		sf[i] = max( sf[i + 1] , Dp[ Seq[i] ] - Sum[i] + Mx );
		Mx = max( Mx , Dp[ Seq[i] ] + Sum[i] );
		g2[i] = max( g2[i + 1] , Dp[ Seq[i] ] + Sum[Seqlen] - Sum[i] );
	}
	Final = pf[Seqlen];
	for(int i = 1 ; i < Seqlen ; ++ i){
		long long ret =  max( max( pf[i] , sf[i + 1] ) , g1[i] + g2[i + 1] + dist[make_pair( Seq[1] , Seq[Seqlen] )] );
		Final = min( Final , ret );
	}
	Final = max( Final , ans );
	printf( "%lld\n" , Final );
 	return 0;
}