#include <stdio.h>
#include <algorithm>

using namespace std;

const long long mod = 998244353;
long long n , m;
long long a[1200000];
long long l[510] , r[510];
long long minn[510][510];
long long dp[510][510];
long long vis[510][510];
long long getdp ( long long i , long long j ) {
    if ( vis[i][j] ) return dp[i][j];
    vis[i][j] = 1;
    long long k , tmp1 , tmp2 , now = minn[i][j] , le , ri , s1 , s2 , tt;
    long long o;
    le = l[now]; ri = r[now];
    tmp1 = tmp2 = 0;
    tt = a[ri+1];
    if ( ri == r[j] ) {
    	tmp1 = 1;
    }
    else {
	    tmp1 = getdp ( a[ri+1] , j );
	    for ( k = ri + 1 ; k <= r[j] ; k++ ) {
	        if ( k == ri + 1 ) s1 = 1;
	        else {
	            s1 = getdp ( tt , a[k-1] );
	        }
	        s2 = getdp ( a[k] , j );
	        tmp1 = (tmp1 + s1*s2) % mod;
	        k = r[a[k]];
	    }
	}
	if ( le == l[i] ) {
		tmp2 = 1;
	}
	else {
	    tt = a[le-1];
	    tmp2 = getdp ( i , a[le-1] );
	    for ( k = le - 1 ; k >= l[i] ; k-- ) {
	        if ( k == le - 1 ) s2 = 1;
	        else {
	            s2 = getdp ( a[k+1] , tt );
	        }
	        s1 = getdp ( i , a[k] );
	        tmp2 = (tmp2 + s1*s2) % mod;
	        k = l[a[k]];
	    }
	}
    dp[i][j] = (tmp1*tmp2) % mod;
    for ( k = l[now] ; k <= r[now] ; k++ ) {
        if ( a[k] != now ) {
            o = r[a[k]];
            while ( o < r[now] && a[o+1] != now ) o = r[a[o+1]];
            dp[i][j] = ( dp[i][j] * getdp(a[k],a[o]) ) % mod;
            k = o;
        }
    }
    //printf ( "%lld %lld %lld %lld %lld\n" , i , j , dp[i][j] , tmp1 , tmp2 );
    return dp[i][j];
}
void work () {
    long long i , j , k;
    scanf ( "%lld%lld" , &n , &m );
    for ( i = 1 ; i <= n ; i++ ) l[i] = m;
    for ( i = 1 ; i <= m ; i++ ) {
        scanf ( "%lld" , &a[i] );
        l[a[i]] = min ( l[a[i]] , i );
        r[a[i]] = max ( r[a[i]] , i );
    }
    for ( i = 1 ; i <= n ; i++ ) {
        for ( j = 1 ; j <= n ; j++ ) {
            if ( l[i] < l[j] && l[j] < r[i] && r[i] < r[j] ) {
                printf ( "0\n" );
                return ;
            }
        }
    }
    for ( i = 1 ; i <= m ; i++ ) {
    	for ( j = a[i] + 1 ; j <= n ; j++ ) {
    		if ( l[j] <= i && i <= r[j] ) {
    			printf ( "0\n" );
    			return ;
    		}
    	}
    }
    for ( i = 1 ; i <= n ; i++ ) {
        for ( j = 1 ; j <= n ; j++ ) {
            if ( l[i] > r[j] ) continue;
            minn[i][j] = 9999;
            for ( k = 1 ; k <= n ; k++ ) {
                if ( l[i] <= l[k] && l[k] <= r[j] ) minn[i][j] = min ( minn[i][j] , k );
            }
        }
    }
    printf ( "%lld\n" , getdp ( a[1] , a[m] ) );
}
int main () {
    work ();
    return 0;
}