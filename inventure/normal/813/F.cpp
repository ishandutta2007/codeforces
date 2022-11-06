#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 50;

int n , Q , sz[maxn] , fa[maxn] , rev[maxn] , st[maxn] , ed[maxn];
vector < pair < int , int > > Seg[maxn << 2];
map < pair < int , int > , int > Sav;
stack < pair < int * , int > > stk;

void Add( int ql , int qr , int l , int r , pair < int , int > y , int o ){
	if( ql <= l && r <= qr )
		Seg[o].emplace_back( y );
	else{
		int mid = l + r >> 1;
		if( ql <= mid )
			Add( ql , qr , l , mid , y , o << 1 );
		if( qr > mid )
			Add( ql , qr , mid + 1 , r , y , o << 1 | 1 );
	}
}

int Find_fa( int u ){
	while( u ^ fa[u] )	u = fa[u];
	return u;
}

int GetDist( int u ){
	int dist = 0;
	while( u ^ fa[u] ) dist ^= rev[u] , u = fa[u];
	return dist;
}

void Solve( int l , int r , int o ){
	int f = stk.size() , ok = 1;
	for(auto & it : Seg[o]){
		int u = it.first , v = it.second;
		if( Find_fa( u ) == Find_fa( v ) ){
			if( GetDist( u ) == GetDist( v ) ){
				ok = 0;
				break;
			}
		}else{
			int a = u , b = v , p1 = Find_fa( a ) , p2 = Find_fa( b );
			if( sz[p1] > sz[p2] )
				swap( a , b ),
				swap( p1 , p2 );
			int w = GetDist( a ) ^ GetDist( b ) ^ 1;
			stk.push( make_pair( fa + p1 , fa[p1] ) );
			stk.push( make_pair( sz + p2 , sz[p2] ) );
			stk.push( make_pair( rev + p1 , rev[p1] ) );
			fa[p1] = p2;
			sz[p2] += sz[p1];
			rev[p1] = w;
		}
	}
	if( ok ){
		int mid = l + r >> 1;
		if( l < r ){
			Solve( l , mid , o << 1 );
			Solve( mid + 1 , r , o << 1 | 1 );
		}
	}else
		++ st[l] , ++ ed[r];
	while( stk.size() > f ){
		pair < int * , int > fr = stk.top(); stk.pop();
		*fr.first = fr.second;
	}
}

int main( int argc , char * argv[] ){
	scanf( "%d%d" , & n , & Q );
	for(int i = 1 ; i <= n ; ++ i)
		sz[i] = 1 , fa[i] = i;
	for(int i = 1 ; i <= Q ; ++ i){
		int u , v;
		scanf( "%d%d" , & u , & v );
		if( u > v )
			swap( u , v );
		if( Sav.count ( make_pair( u , v ) ) ){
			Add( Sav[make_pair( u , v )] , i - 1 , 1 , Q , make_pair( u , v ) , 1 );
			Sav.erase( make_pair( u , v ) );
		}else
			Sav[make_pair( u , v )] = i;
	}
	for(auto & it : Sav)
		Add( it.second , Q , 1 , Q , it.first , 1 );
	Solve( 1 , Q , 1 );
	for(int i = 1 , sum = 0 ; i <= Q ; ++ i){
		sum += st[i];
		if( sum )
			puts( "NO" );
		else
			puts( "YES" );
		sum -= ed[i];
	}
	return 0;
}