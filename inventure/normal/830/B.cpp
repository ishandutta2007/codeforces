#include <bits/stdc++.h>

using namespace std;

stack < int > allocate;
int ks;
template < typename T1 , typename T2 >
struct SplayTree{
    const static int maxn = 1e5 + 50;
	int ch[maxn][2] , s[maxn] , root , fa[maxn];
	stack < int > stk;
    T1 Key[maxn];
    T2 Value[maxn] , lzy[maxn] , Mi[maxn];

	inline void up(int x){
		s[x] = s[ch[x][0]] + s[ch[x][1]] + 1;
		Mi[x] = Value[x];
		if( ch[x][0] )
			Mi[x] = min( Mi[x] , Mi[ch[x][0]] );
		if( ch[x][1] )
			Mi[x] = min( Mi[x] , Mi[ch[x][1]] );
    }

    void Debug( int u , int par = 0 ){
        assert( fa[u] == par );
    	printf( "id is %d ,  Key is %d , Value is %d , size is %d , fa is %d , lson is %d , rson is %d\n" , u , Key[u] , Value[u] , s[u] , fa[u] , ch[u][0] , ch[u][1] );
    	if( ch[u][0] )
    		Debug( ch[u][0] , u );
    	if( ch[u][1] )
    		Debug( ch[u][1] , u );
    }

    void rotate( int x, int d ){
        int y = fa[x];
        ch[y][d ^ 1] = ch[x][d];
        if ( ch[x][d] ) fa[ch[x][d]] = y;  
        fa[x] = fa[y];
        if (fa[y]){
            if (y == ch[fa[y]][d])  ch[fa[y]][d] = x;
            else  ch[fa[y]][d ^ 1] = x;
        }
        ch[x][d] = y , fa[y] = x;
        up( y ) , up( x );
    }

    void Splay( int x , int target ){
    	while( fa[x] != target ){
    		int y = fa[x];
    		if( x == ch[y][0] ){
    			if( fa[y] != target && y == ch[fa[y]][0])
    				rotate( y , 1 );
    			rotate( x , 1 );
    		}else{
    			if( fa[y] != target && y == ch[fa[y]][1])
    				rotate( y , 0 );
    			rotate( x , 0 );
    		}
    	}
    	if( !target ) root = x;
    }

    void Insert( int & x , T1 w1 , T2 w2 , int par = 0 ){
    	if( x == 0 ){
    		x = allocate.top(); allocate.pop();
    		ch[x][0] = ch[x][1] = 0 , s[x] = 1 , Key[x] = w1 , Value[x] = w2 , lzy[x] = 0 , fa[x] = par;
    		Splay( x , 0 );
    	}else{
    		int cur = x;
    		if( w1 < Key[x] ) Insert( ch[x][0] , w1 , w2 , x );
    		else Insert( ch[x][1] , w1 , w2 , x );
    	}
    }

    void Delete(){
    	allocate.push( root );
    	if( !ch[root][0] && !ch[root][1] ){
    		root = 0;
    		return ;
    	}
    	if( !ch[root][0] )
    		root = ch[root][1] , fa[root] = 0;
    	else if( !ch[root][1] )
    		root = ch[root][0] , fa[root] = 0;
    	else{
    		int x = ch[root][0];
    		while( ch[x][1] )
    			x = ch[x][1];
    		Splay( x , root );
    		fa[ch[root][1]] = x;
    		ch[x][1] = ch[root][1];
    		root = x;
    		fa[root] = 0;
    		up( root );
    	}
    }

    int DFS( int o , int l ){
    	if( s[ch[o][0]] == l - 1 )
    		return o;
    	if( s[ch[o][0]] >= l )
    		return DFS( ch[o][0] , l );
    	else
    		return DFS( ch[o][1] , l - s[ch[o][0]] - 1 );
    }

    int PreDFS( int o ){
    	if( !ch[o][0] && !ch[o][1] )
    		return o;
    	int mi = ch[o][0] ? ch[o][0] : ch[o][1];
    	if( ch[o][1] && Mi[ch[o][1]] < Mi[mi] )
    		mi = ch[o][1];
    	if( Mi[mi] > Value[o] || ( Mi[mi] == Value[o] && mi == ch[o][1] ) ){
    		ks += s[ch[o][0]];
    		return o;
    	}
    	if( mi == ch[o][1] )
    		ks += s[ch[o][0]]+1;
    	return PreDFS( mi );
    }
};

const int maxn = 1e5 + 50;

SplayTree < int , int > Tree;
stack < int > stk;

int n;

int main( int argc , char * argv[] ){
	for(int i = 1 ; i < maxn ; ++ i)
		allocate.push( i );
	scanf( "%d" , & n );
	Tree.Insert( Tree.root , 0 , 1 << 30 );
	for(int i = 1 ; i <= n ; ++ i){
		int x;
		scanf( "%d" , & x );
		Tree.Insert( Tree.root , i , x );
	}
	//Tree.Debug( Tree.root );
	long long ans = 1;
	for(int i = 1 ; i < n ; ++ i){
		ks = 0;
		int z = Tree.PreDFS( Tree.root );
		ans += ks;
		int x = Tree.DFS( Tree.root , 1 );
		int y = Tree.DFS( Tree.root , ks + 1 );
		Tree.Splay( x , 0 );
		Tree.Splay( y , x );
		if( Tree.ch[y][0] ){
			int w = Tree.ch[y][0];
			Tree.fa[w] = 0;
			Tree.ch[y][0] = 0;
			int er = x;
			while( Tree.ch[er][1] ){
				stk.push( er );
				er = Tree.ch[er][1];
			}
			stk.push( er );
			Tree.ch[er][1] = w;
			Tree.fa[w] = er;
			while( !stk.empty() )
				Tree.up( stk.top() ),
				stk.pop();
			Tree.Splay( w , 0 );
		}
		Tree.Splay( y , 0 );
		Tree.Delete();
	}
	printf( "%I64d\n" , ans );
    return 0;
}