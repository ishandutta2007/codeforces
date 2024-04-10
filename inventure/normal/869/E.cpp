#include <bits/stdc++.h>

using namespace std;

inline int read(){int x=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}
const int maxn = 1e5 + 50;
int n , m , q;
map < pair < int , int > , int > seg[maxn];

void Dfs( int o , int l , int r , int ql , int qr , pair < int , int > Segment , int Col , bool flag ){
	if( ql <= l && r <= qr ){
		if( flag == true )
			seg[o].insert( make_pair( Segment , Col ) );
		else
			seg[o].erase( Segment );
	}else{
		int mid = l + r >> 1;
		if( ql <= mid ) Dfs( o << 1 , l , mid , ql , qr , Segment , Col , flag );
		if( qr > mid ) Dfs( o << 1 | 1 , mid + 1 , r , ql , qr , Segment , Col , flag );
	}
}

void Query( int o , int l , int r , int x , int y , pair < int , int > & best , int & col ){
	if( l < r ){
		int mid = l + r >> 1;
		if( x <= mid ) Query( o << 1 , l , mid , x , y , best , col );
		else Query( o << 1 | 1 , mid + 1 , r , x , y , best , col );
	}
	auto c = seg[o].lower_bound( make_pair( best.first , -1 ) );
	while( c != seg[o].end() ){
		if( c->first.first > y ) break;
		if( c->first.second >= y ) best = c->first , col = c->second;
		c = next( c );
	}
}


int main( int argc , char * argv[] ){
	n = read() , m = read() , q = read();
	for(int i = 1 ; i <= q ; ++ i){
		int tp = read() , r1 = read() , c1 = read() , r2 = read() , c2 = read();
		if( tp == 1 ) Dfs( 1 , 1 , n , r1 , r2 , make_pair( c1 , c2 ) , i , true );
		else if( tp == 2 ) Dfs( 1 , 1 , n , r1 , r2 , make_pair( c1 , c2 ) , i , false );
		else{
			pair < int , int > s1 = make_pair( 1 , m ) , s2 = s1;
			int t1 = 0 , t2 = 0;
			Query( 1 , 1 , n , r1 , c1 , s1 , t1 );
			Query( 1 , 1 , n , r2 , c2 , s2 , t2 );
			if( t1 == t2 ) puts( "Yes" );
			else puts( "No" );
		}
	}
	return 0;
}