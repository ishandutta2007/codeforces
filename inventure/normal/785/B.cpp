#include <bits/stdc++.h>

inline int read(){int x=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}
using namespace std;

struct Segment{
	int l , r ;
	Segment( int l , int r ):l(l),r(r){}
	friend bool operator < (const Segment & a , const Segment & b){
		return a.l < b.l || (a.l == b.l && a.r < b.r);
	}
};

vector < Segment > s1 , s2;
int n , m ;

int Get( Segment a , Segment b ){
	if(a.l > b.l)
		swap( a , b );
	if(b.l <= a.r)
		return 0;
	return b.l - a.r;
}

int main( int argc , char * argv[] ){
	n = read();
	for(int i = 1 ; i <= n ; ++ i){
		int l = read() , r = read();
		s1.emplace_back( Segment( l , r ) );
	}
	m = read();
	for(int i = 1 ; i <= m ; ++ i){
		int l = read() , r = read();
		s2.emplace_back( Segment( l , r ) );
	}
	sort( s1.begin() , s1.end() );
	sort( s2.begin() , s2.end() );
	int ans = 0;
	for(int i = 0 ; i < n ; ++ i){
		ans = max( ans , Get( s1[i] , s2[0] ) );
		ans = max( ans , Get( s1[i] , s2[m - 1] ) );
	}
	for(int i = 0 ; i < m ; ++ i){
		ans = max( ans , Get( s2[i] , s1[0] ) );
		ans = max( ans , Get( s2[i] , s1[n - 1] ) );
	}
	cout << ans << endl;
	return 0;
}