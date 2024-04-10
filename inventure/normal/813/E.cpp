#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 50;

struct Node{
	int sum , l , r;
}tree[maxn * 90];

int n , k , Q , root[maxn] , ret , a[maxn] , tot ;
vector < int > pos[maxn];

int Modify( int x , int y , int l , int r , int f ){
	int ret = ++ tot;
	tree[ret] = tree[f];
	tree[ret].sum += y;
	if( l < r ){
		int mid = l + r >> 1;
		if( x <= mid )
			tree[ret].l = Modify( x , y , l , mid , tree[f].l );
		else
			tree[ret].r = Modify( x , y , mid + 1 , r , tree[f].r );
	}
	return ret;
}

int query( int ql , int qr , int l , int r , int f ){
	if( ql <= l && r <= qr )
		return tree[f].sum;
	else{
		int mid = l + r >> 1 , sum = 0;
		if( ql <= mid )
			sum += query( ql , qr , l , mid , tree[f].l );
		if( qr > mid )
			sum += query( ql , qr , mid + 1 , r , tree[f].r );
		return sum;
	}
}


int main( int argc , char * argv[] ){
	scanf( "%d%d" , & n , & k );
	for(int i = 1 ; i <= n ; ++ i){
		scanf( "%d" , a + i );
		pos[a[i]].emplace_back( i );
	}
	for(int i = n ; i >= 1 ; -- i){
		root[i] = Modify( i , 1 , 1 , n , root[i + 1] );
		int w = lower_bound( pos[a[i]].begin() , pos[a[i]].end() , i ) - pos[a[i]].begin();
		if( w + k < pos[a[i]].size() )
			root[i] = Modify( pos[a[i]][w + k] , -1 , 1 , n , root[i] );
	}
	int Q , last = 0;
	scanf( "%d" , & Q );
	while( Q -- ){
		int x , y;
		scanf( "%d%d" , & x , & y );
		int l = ( x + last ) % n + 1;
		int r = ( y + last ) % n + 1;
		if( l > r )
			swap( l , r );
		last = query( l , r , 1 , n , root[l] );
		printf( "%d\n" , last );
	}
	return 0;
}