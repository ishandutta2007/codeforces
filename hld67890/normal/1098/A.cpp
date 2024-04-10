#include <stdio.h>
#include <algorithm>

using namespace std;

//long long
const long long maxn = 120000;
struct node {
    long long v;
    node *next;
} pool[maxn*2] , *g[maxn];
long long top;
long long n;
long long a[maxn] , s[maxn] , dep[maxn];
long long flag , ans;
void add ( long long u , long long v ) {
    node *tmp = &pool[++top];
    tmp -> v = v; tmp -> next = g[u]; g[u] = tmp;
}
void dfs ( long long i , long long from ) {
    long long f = 0;
    if ( s[i] != -1 ) {
        a[i] = s[i] - s[from];
    }
    else {
        a[i] = 2147483647777777ll;
    }
    //if ( i == 3 ) printf ( "%lld %lld\n" , a[3] , a[2] );
    for ( node *j = g[i] ; j ; j = j -> next ) if ( j -> v != from ) {
        if ( s[i] == -1 ) {
            if ( s[j->v] < s[from] ) {
                flag = 0;
                return ;
            }
            a[i] = min ( a[i] , s[j->v] );
        }
    }
    if ( dep[i] % 2 == 0 ) {
        if ( a[i] == 2147483647777777ll ) {
            a[i] = 0;
        }
        else a[i] -= s[from];
        if ( s[i] == -1 ) s[i] = a[i] + s[from];
    }
    for ( node *j = g[i] ; j ; j = j -> next ) if ( j -> v != from ) {
        dep[j->v] = dep[i] + 1;
        dfs ( j -> v , i );
    }
}
void work () {
    long long i , u;
    scanf ( "%lld" , &n );
    for ( i = 2 ; i <= n ; i++ ) {
        scanf ( "%lld" , &u );
        add ( u , i );
    }
    for ( i = 1 ; i <= n ; i++ ) scanf ( "%lld" , &s[i] );
    flag = 1;
    dep[1] = 1;
    dfs ( 1 , 0 );
    for ( i = 1 ; i <= n ; i++ ) {
        ans += a[i];
        //printf ( "%lld %lld\n" , s[i] , a[i] );
    }
    if ( flag == 0 ) {
        printf ( "-1\n" );
        return ;
    }
    printf ( "%lld\n" , ans );
}
int main () {
    work ();
    return 0;
}