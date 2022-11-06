#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>  
using namespace __gnu_pbds;
inline int read(){int x=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}
using namespace std;
const int maxn = 2e5 + 50;
#define lowbit(x) ((x)&(-x))

int n , a[maxn] , q;
tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> Tree[maxn]; 

inline void Insert( int x , int y ){
	while( x <= n ){
		Tree[x].insert( y );
		x += lowbit( x );
	}
}

inline void Remove( int x , int y ){
	while( x <= n ){
		Tree[x].erase( y );
		x += lowbit( x );
	}
}

int Prefix_Small( int x , int y ){
	int ret = 0;
	while( x ){
		ret += Tree[x].order_of_key( y );
		x -= lowbit( x );
	}
	return ret;
}

int main( int argc , char * argv[] ){
	n = read() , q = read();
	long long ans = 0;
	for(int i = 1 ; i <= n ; ++ i){
		a[i] = i;
		Insert( i , i );
	}
	while( q -- ){
		int l = read() , r = read();
		if( l == r ){
			printf( "%lld\n" , ans );
			continue;
		}
		if( l > r )
			swap( l , r );
		if( a[l] < a[r] )
			-- ans;
		else
			++ ans;
		int k1 = Prefix_Small( l , a[l] );
		int k2 = Prefix_Small( r , a[r] );
		ans -= (l - 1 - k1 + r - 1 - k2);
		ans -= (a[l] - 1 - k1);
		ans -= (a[r] - 1 - k2);
		Remove( l , a[l] );
		Remove( r , a[r] );
		swap( a[l] , a[r] );
		Insert( l , a[l] );
		Insert( r , a[r] );
		k1 = Prefix_Small( l , a[l] );
		k2 = Prefix_Small( r , a[r] );
		ans += (l - 1 - k1 + r - 1 - k2);
		ans += (a[l] - 1 - k1);
		ans += (a[r] - 1 - k2);
		printf( "%lld\n" , ans );
	}
	return 0;
}