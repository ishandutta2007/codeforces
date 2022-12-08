#include <stdio.h>
#include <algorithm>

using namespace std;

const int maxn = 210000;
struct info {
    int x , y , t , l;
} emp;
struct edge {
    int v;
    edge *next;
} poole[maxn*2] , *g[maxn];
struct node {
    int l , r;
    info c;
    node *ll , *rr;
} pool[maxn*4] , *t;
int top , tope;
int n , q;
int a[maxn] , pos[maxn];
int go[20][maxn] , dep[maxn] , siz[maxn] , son[maxn] , topp[maxn];
void add ( int u , int v ) {
    edge *tmp = &poole[++tope];
    tmp -> v = v; tmp -> next = g[u]; g[u] = tmp;
}
void dfs1 ( int i , int from ) {
	siz[i] = 1;
    for ( edge *j = g[i] ; j ; j = j -> next ) if ( j -> v != from ) {
        dep[j->v] = dep[i] + 1;
        dfs1 ( j -> v , i );
        if ( siz[j->v] > siz[son[i]] ) son[i] = j -> v;
        siz[i] += siz[j->v];
    }
}
void dfs2 ( int i , int from ) {
	if ( son[i] ) {
		topp[son[i]] = topp[i];
		dfs2 ( son[i] , i );
	}
	for ( edge *j = g[i] ; j ; j = j -> next ) if ( j -> v != from && j -> v != son[i] ) {
		topp[j->v] = j -> v;
		dfs2 ( j -> v , i );
	}
}
int lca ( int x , int y ) {
	while ( topp[x] != topp[y] ) {
		if ( dep[topp[x]] > dep[topp[y]] ) x = go[0][topp[x]];
		else y = go[0][topp[y]];
	}
	if ( dep[x] < dep[y] ) return x;
	return y;
}
/*void dfs ( int i , int from ) {
    for ( edge *j = g[i] ; j ; j = j -> next ) if ( j -> v != from ) {
        dep[j->v] = dep[i] + 1;
        dfs ( j -> v , i );
    }
}
int lca ( int x , int y ) {
    int i;
    if ( dep[x] < dep[y] ) swap ( x , y );
    for ( i = 19 ; i >= 0 ; i-- ) if ( dep[go[i][x]] >= dep[y] ) x = go[i][x];
    if ( x == y ) return x;
    for ( i = 19 ; i >= 0 ; i-- )
        if ( go[i][x] != go[i][y] ) {
            x = go[i][x];
            y = go[i][y];
        }
    return go[0][x];
}*/
bool inc ( info x , int y ) {
    //printf ( "inc %d %d %d %d\n" , x.x , x.y , l , y );
    if ( lca ( x.x , y ) == y && lca ( x.l , y ) == x.l ) return true;
    if ( lca ( x.y , y ) == y && lca ( x.l , y ) == x.l ) return true;
    return false;
}
info Union ( info x1 , info x2 ) {
    info ret;
    //printf ( "Un %d %d %d %d %d %d\n" , x1.x , x1.y , x1.t , x2.x , x2.y , x2.t );
    if ( x1.t == -2 ) return x2;
    if ( x2.t == -2 ) return x1;
    if ( x1.t == -1 || x2.t == -1 ) {
        ret.t = -1;
        return ret;
    }
    ret.t = max ( x1.t , x2.t );
    int x1y1 = lca ( x1.x , x1.y ) , x1x2 = lca ( x1.x , x2.x ) , x1y2 = lca ( x1.x , x2.y )
	  , y1x2 = lca ( x1.y , x2.x ) , y1y2 = lca ( x1.y , x2.y ) , x2y2 = lca ( x2.x , x2.y );
    ret.x = x1.x; ret.y = x1.y;
    if ( (x2.x==x1x2||x2.x==y1x2) && (x2.y==x1y2||x2.y==y1y2) && x1y1 == lca (x1y1,x2y2) ) return ret;
    ret.x = x1.x; ret.y = x2.x;
    if ( (x1.y==x1y1||x1.y==y1x2) && (x2.y==x1y2||x2.y==x2y2) && x1x2 == lca (x1x2,y1y2) ) return ret;
    ret.x = x1.x; ret.y = x2.y;
    if ( (x1.y==x1y1||x1.y==y1y2) && (x2.x==x1x2||x2.x==x2y2) && x1y2 == lca (x1y2,y1x2) ) return ret;
    ret.x = x1.y; ret.y = x2.x;
    //printf ( "$%d %d\n" , inc ( ret , x1.x ) , inc ( ret , x2.y )  );
    if ( (x1.x==x1y1||x1.x==x1x2) && (x2.y==y1y2||x2.y==x2y2) && y1x2 == lca (y1x2,x1y2) ) return ret;
    ret.x = x1.y; ret.y = x2.y;
    if ( (x1.x==x1y1||x1.x==x1y2) && (x2.x==y1x2||x2.x==x2y2) && y1y2 == lca (y1y2,x1x2) ) return ret;
    ret.x = x2.x; ret.y = x2.y;
    if ( (x1.x==x1x2||x1.x==x1y2) && (x1.y==y1x2||x1.y==y1y2) && x2y2 == lca (x2y2,x1y1) ) return ret;
    ret.t = -1;
    return ret;
}
void buildtree ( node *id , int l , int r ) {
    id -> l = l; id -> r = r;
    if ( l == r ) {
        id -> c.x = id -> c.y = pos[l];
        id -> c.t = l;
        return ;
    }
    int mid = (l+r)/2;
    id -> ll = &pool[++top]; id -> rr = &pool[++top];
    buildtree ( id -> ll , l , mid ); buildtree ( id -> rr , mid + 1 , r );
    id -> c = Union ( id -> ll -> c , id -> rr -> c );
}
void change ( node *id , int l , int x ) {
    if ( id -> l == id -> r ) {
        id -> c.x = id -> c.y = x;
        id -> c.t = l;
        return ;
    }
    int mid = (id->l+id->r)/2;
    if ( l <= mid ) change ( id -> ll , l , x );
    else change ( id -> rr , l , x );
    id -> c = Union ( id -> ll -> c , id -> rr -> c );
}
info query ( node *id , info now ) {
    //printf ( "%d %d %d %d %d\n" , id -> l , id -> r , now.x , now.y , now.t );
    info tmp = Union ( now , id -> c );
    if ( tmp.t == -1 ) {
        if ( id -> l == id -> r ) return now;
        tmp = Union ( now , id -> ll -> c );
        if ( tmp.t == -1 ) {
            return query ( id -> ll , now );
        }
        else return query ( id -> rr , tmp );
    }
    else return tmp;
}
void work () {
    int i , j , op , u , v;
    scanf ( "%d" , &n );
    for ( i = 1 ; i <= n ; i++ ) {
        scanf ( "%d" , &a[i] );
        a[i]++;
        pos[a[i]] = i;
    }
    for ( i = 2 ; i <= n ; i++ ) {
        scanf ( "%d" , &go[0][i] );
        add ( i , go[0][i] );
        add ( go[0][i] , i );
    }
    dep[1] = 1;
    dfs1 ( 1 , -1 );
    topp[1] = 1;
    dfs2 ( 1 , -1 );
    /*for ( i = 1 ; i <= 19 ; i++ )
        for ( j = 1 ; j <= n ; j++ ) go[i][j] = go[i-1][go[i-1][j]];*/
    t = &pool[++top];
    buildtree ( t , 1 , n );
    scanf ( "%d" , &q );
    emp.t = -2;
    for ( i = 1 ; i <= q ; i++ ) {
        scanf ( "%d" , &op );
        if ( op == 2 ) printf ( "%d\n" , query ( t , emp ).t );
        else {
            scanf ( "%d%d" , &u , &v );
            change ( t , a[u] , v );
            change ( t , a[v] , u );
            swap ( a[u] , a[v] );
        }
    }
}
int main () {
    work ();
    return 0;
}