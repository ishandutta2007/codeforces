#include <bits/stdc++.h>

using namespace std;


inline int read(){int x=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}

const int maxn = 100 + 15;

map < int , vector < int > > f;
map < vector < int > , int > g;
int n;

int GetMex( vector < int > & x ){
	if( x.empty() ) return 0;
	sort( x.begin() , x.end() );
	if( *x.begin() != 0 ) return 0;
	for(int i = 1 ; i < x.size() ; ++ i)
		if( x[i] - x[i - 1] > 1 )
			return x[i - 1] + 1;
	return x.back() + 1;
}

int Dfs( vector < int > x ){
	if( x.empty() ) return 0;
	if( g.count( x ) ) return g[x];
	int & ans = g[x] = 0;
	vector < int > vi;
	int mx = *x.rbegin();
	for(int i = 1 ; i <= mx ; ++ i){
		vector < int > newx = x;
		for(int j = 0 ; j < x.size() ; ++ j)
			if( newx[j] >= i )
				newx[j] -= i;
		sort( newx.begin() , newx.end() , greater < int >() );
		while( !newx.empty() && newx.back() == 0 ) newx.pop_back();
		reverse( newx.begin() , newx.end() );
		vi.push_back( Dfs( newx ) );
	}
	return ans = GetMex( vi );
}

int main( int argc , char * argv[] ){
	n = read();
	for(int i = 1 ; i <= n ; ++ i){
		int x = read();
		for(int j = 2 ; j * j <= x ; ++ j){
			if( x % j ) continue;
			int cnt = 0;
			while( x % j == 0 ){
				x /= j;
				++ cnt;
			}
			f[j].emplace_back( cnt );
		}
		if( x > 1 ) f[x].emplace_back( 1 );
	}
	int ans = 0;
	for(auto && x : f){
		vector < int > y = x.second;
		sort( y.begin() , y.end() );
		y.assign( y.begin() , unique( y.begin() , y.end() ) );
		ans ^= Dfs( y );
	}
	if( ans ) puts( "Mojtaba" );
	else puts( "Arpa" );
	return 0;
}