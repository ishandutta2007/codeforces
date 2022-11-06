#include <bits/stdc++.h>
inline int read(){int x=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}

using namespace std;

const int maxn = 1e5 + 50;

int n , w , h , type[maxn] , p[maxn] , t[maxn];
pair < int , int > ans[maxn];
map < int , vector < int > > Mp;

int main( int argc , char * argv[] ){
	n = read() , w = read() , h = read();
	for(int i = 1 ; i <= n ; ++ i){
		type[i] = read() , p[i] = read() , t[i] = read();
		Mp[ p[i] - t[i] ].emplace_back( i );
	}
	for(auto && x : Mp){
		vector < int > a , b , id1;
		vector < pair < int , int > > c , d , id2;
		for(auto && z : x.second) if( type[z] == 1 ) a.emplace_back( z ) ; else b.emplace_back( z );
		sort( a.begin() , a.end() , []( const int & q , const int & w){
			return p[q] > p[w];
		});
		sort( b.begin() , b.end() , []( const int & q , const int & w){
			return p[q] < p[w];
		});
		for(auto && it : a) id1.emplace_back( it ) , d.emplace_back( make_pair( p[it] , h ) );
		for(auto && it : b) id1.emplace_back( it ) , c.emplace_back( make_pair( w , p[it] ) );
		sort( c.begin() , c.end() );
		sort( d.begin() , d.end() , greater < pair < int , int > >()  );
		for(auto && it : c) id2.emplace_back( it );
		for(auto && it : d) id2.emplace_back( it );
		for(int i = 0 ; i < id2.size() ; ++ i)
			ans[id1[i]] = id2[i];
	}
	for(int i = 1 ; i <= n ; ++ i)
		printf( "%d %d\n" , ans[i].first , ans[i].second );
	return 0;
}