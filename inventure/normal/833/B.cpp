#include <bits/stdc++.h>

using namespace std;
inline int read(){int x=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}

const int maxn = 35000 + 50;

namespace SegmentTree{
	struct Node{
		int l , r , mx , lzy;

		void Upd( int x ){
			mx += x;
			lzy += x;
		}
	}tree[maxn << 2];

	void Build( int l , int r , int o ){
		tree[o].l = l , tree[o].r = r , tree[o].mx = 0 , tree[o].lzy = 0;
		if( l < r ){
			int mid = l + r >> 1;
			Build( l , mid , o << 1 );
			Build( mid + 1 , r , o << 1 | 1 );
		}
	}

	void ReleaseLabel( int o ){
		if( tree[o].lzy ){
			tree[o << 1].Upd( tree[o].lzy );
			tree[o << 1 | 1].Upd( tree[o].lzy );
			tree[o].lzy = 0;
		}
	}

	void Maintain( int o ){
		tree[o].mx = max( tree[o << 1].mx , tree[o << 1 | 1].mx );
	}

	void Modify( int ql , int qr , int x , int o ){
		int l = tree[o].l , r = tree[o].r;
		if( ql <= l && r <= qr )
			tree[o].Upd( x );
		else{
			int mid = l + r >> 1;
			ReleaseLabel( o );
			if( ql <= mid )
				Modify( ql , qr , x , o << 1 );
			if( qr > mid )
				Modify( ql , qr , x , o << 1 | 1);
			Maintain( o );
		}
	}

	int Query( int ql , int qr , int o ){
		int l = tree[o].l , r = tree[o].r;
		if( ql <= l && r <= qr )
			return tree[o].mx;
		else{
			int mid = l + r >> 1 , ret = 0;
			ReleaseLabel( o );
			if( ql <= mid )
				ret = max( ret , Query( ql , qr , o << 1 ) );
			if( qr > mid )
				ret = max( ret , Query( ql , qr , o << 1 | 1 ) );
			Maintain( o );
			return ret;
		}
	}
};

int n , a[maxn] , k , dp[2][maxn] , cur , pos[maxn];

int main( int argc , char * argv[] ){
	n = read() , k = read();
	for(int i = 1 ; i <= n ; ++ i)
		a[i] = read();
	for(int j = 1 ; j <= k ; ++ j){
		int pre = cur ; cur ^= 1;
		memset( dp[cur] , 0 , sizeof( dp[cur] ) );
		memset( pos , 0 , sizeof( pos ) );
		SegmentTree::Build( 0 , n , 1 );
		for(int i = 1 ; i <= n ; ++ i) SegmentTree::Modify( i , i , dp[pre][i] , 1 );
		for(int i = 1 ; i <= n ; ++ i){
			int z = pos[ a[i] ];
			if( z ) SegmentTree::Modify( 0 , z - 1 , -1 , 1 );
			pos[ a[i] ] = z = i;
			SegmentTree::Modify( 0 , z - 1 , 1 , 1 );
			dp[cur][i] = SegmentTree::Query( 0 , i - 1 , 1 );
		}
	}
	printf( "%d\n" , dp[cur][n] );
	return 0;
}