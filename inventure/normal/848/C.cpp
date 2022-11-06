#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
inline int read(){int x=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}
using namespace __gnu_pbds;
using namespace std;
const int maxn = 1e5 + 50;
#define lowbit( x ) ( (x) & (-x) )

template < class Node_CItr , class Node_Itr , class Cmp_Fn , class _Alloc>
struct MyUpdate{
	virtual Node_CItr node_begin() const = 0;
	virtual Node_CItr node_end() const = 0;
	typedef long long metadata_type;
	inline void operator()(Node_Itr it , Node_CItr end_it){
		Node_Itr l = it.get_l_child(), r = it.get_r_child();
		long long res = 0;
		if(l != end_it) res += l.get_metadata();
		if(r != end_it) res += r.get_metadata();
		const_cast <metadata_type &>(it.get_metadata()) = res + (*it)->second;
	}
	inline long long PrefixSum( int x ){
		long long ret = 0;
		Node_CItr it = node_begin();
		while( it != node_end() ){
			Node_CItr l = it.get_l_child() , r = it.get_r_child();
			if(Cmp_Fn()(x,(*it)->first)) it=l;
			else{
				ret += (*it)->second;
				if( l != node_end() ) ret += l.get_metadata();
				it = r;
			}
		}
		return ret;
	}
};
tree < int , long long , less < int > , rb_tree_tag , MyUpdate > rbt[maxn];
int n , m , a[maxn];
set < int > occur[maxn];

void Moidfy( int x , int y , int z ){
	while( x <= n ){
		long long f = 0;
		if( rbt[x].find( y ) != rbt[x].end() ){
			f += rbt[x][y];
			rbt[x].erase( y );
		}
		rbt[x].insert( make_pair( y , f + z ) );
		x += lowbit( x );
	}
}

long long Prefix( int x , int y ){
	long long z = 0;
	while( x ){
		z += rbt[x].PrefixSum( y );
		x -= lowbit( x );
	}
	return z;
}

int main( int argc , char * argv[] ){
	n = read() , m = read();
	for(int i = 1 ; i <= n ; ++ i){
		a[i] = read();
		occur[a[i]].insert( i );
	}
	for(int i = 1 ; i <= n ; ++ i){
		int pre = -1;
		for(auto && x : occur[i]){
			if( pre != -1 ) Moidfy( x , pre , x - pre );
			pre = x;
		}
	}
	while( m -- ){
		int tp = read() , x = read() , y = read();
		if( tp == 2 ) printf( "%lld\n" , Prefix( y , 1e9 + 7 ) - Prefix( y , x - 1 ) );
		else{
			if( a[x] == y ) continue;

			// Delete
			{
				auto Next = occur[a[x]].upper_bound( x );
				auto Prev = prev( Next );
				if( Prev == occur[a[x]].begin() ) Prev = occur[a[x]].end();
				else Prev = prev( Prev );
				if( Prev != occur[a[x]].end() ) Moidfy( x , *Prev , - ( x - *Prev ) );
				if( Next != occur[a[x]].end() ){
					Moidfy( *Next , x , - ( *Next - x ) );
					if( Prev != occur[a[x]].end() ) Moidfy( *Next , *Prev , *Next - *Prev );
				}
				occur[a[x]].erase( x );
			}
			a[x] = y;
			// Add
			{
				occur[a[x]].insert( x );
				auto Next = occur[a[x]].upper_bound( x );
				auto Prev = prev( Next );
				if( Prev == occur[a[x]].begin() ) Prev = occur[a[x]].end();
				else Prev = prev( Prev );
				if( Prev != occur[a[x]].end() ) Moidfy( x , *Prev , x - *Prev );
				if( Next != occur[a[x]].end() ){
					Moidfy( *Next , x , *Next - x );
					if( Prev != occur[a[x]].end() ) Moidfy( *Next , *Prev , -( *Next - *Prev ) );
				}
			}
		}
	}
	return 0;
}