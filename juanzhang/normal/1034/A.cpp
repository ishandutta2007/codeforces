#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<queue>
#include<map>
using namespace std;
#define MAXN 300006
int n;
int A[MAXN];
int pri[5006] , en ;
void init() {
    for( int i = 2 ; i < 5006 ; ++ i ) {
        if( !pri[i] ) pri[++en] = i;
        for( int j = 1 ; j <= en && pri[j] * i < 5006 ; ++ j ) {
            pri[i*pri[j]] = 1;
            if( i % pri[j] == 0 ) break;
        }
    }
}
int gcd( int x , int y ) {
    return !y ? x : gcd( y , x % y );
}
map<int,int> M;
int ans[5006];
int main() {
    init();
    cin >> n;
    int t = 0;
    for( int i = 1 ; i <= n ; ++ i )
        scanf("%d",&A[i]) , t = gcd( t , A[i] );
    for( int i = 1 ; i <= n ; ++ i ) A[i] /= t;
    for( int i = 1 ; i <= en ; ++ i ) {
        for( int j = 1 ; j <= n ; ++ j ) {
            if (A[j] % pri[i] == 0) ++ans[i];
            while( A[j] % pri[i] == 0 ) A[j] /= pri[i];
        }
    }
    for( int i = 1 ; i <= n ; ++ i ) if( A[i] != 1 )
        ++ M[A[i]];
    int res = 0;
    for( auto it = M.begin() ; it != M.end() ; ++ it )
        res = max( res , it->second );
    for( int i = 1 ; i < 5006 ; ++ i )
        res = max( res , ans[i] );
    cout << ( res ? (n - res) : -1 ) << endl;
}