#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <map>

using namespace std;

const long long maxn = 3100;
const long long base = 29;
const long long mod = 1000000007;
const long long mod2 = 1000000009;
struct node {
	int len , ha , ha2 , l;
} s[maxn*maxn];
int top;
long long n;
long long a[maxn];
long long dp[maxn][maxn];
long long st[maxn] , st2[maxn];
bool ok[maxn][maxn];
long long ans;
bool cmp ( node x1 , node x2 ) {
	if ( x1.ha2 == x2.ha2 && x1.ha == x2.ha && x1.len == x2.len ) return x1.l < x2.l;
	if ( x1.ha2 == x2.ha2 && x1.ha == x2.ha ) return x1.len < x2.len;
	if ( x1.ha2 == x2.ha2 ) return x1.ha < x2.ha;
	return x1.ha2 < x2.ha2;
}
long long good ( long long i , long long j ) {
    if ( a[i] == 0 && a[i+1] == 0 && a[i+2] == 1 && a[i+3] == 1 ) return 0;
    if ( a[i] == 0 && a[i+1] == 1 && a[i+2] == 0 && a[i+3] == 1 ) return 0;
    if ( a[i] == 1 && a[i+1] == 1 && a[i+2] == 1 && a[i+3] == 0 ) return 0;
    if ( a[i] == 1 && a[i+1] == 1 && a[i+2] == 1 && a[i+3] == 1 ) return 0;
    return 1;
}
void work () {
    long long i , j , k;
    scanf ( "%lld" , &n );
    for ( i = 1 ; i <= n ; i++ ) {
        scanf ( "%lld" , &a[i] );
    }
    for ( i = 1 ; i <= n ; i++ ) {
        for ( j = i ; j <= n ; j++ ) {
            if ( j - i <= 3 ) {
                for ( k = i ; k < j ; k++ ) dp[i][j] += dp[i][k];
                if ( j - i != 3 ) dp[i][j]++;
                else if ( good ( i , j ) ) dp[i][j]++;
            }
            else {
                dp[i][j] = (dp[i][j-1] + dp[i][j-2] + dp[i][j-3]) % mod;
                if ( good ( j - 3 , j ) ) dp[i][j] = (dp[i][j] + dp[i][j-4]) % mod;
            }
        }
    }
    for ( i = 1 ; i <= n ; i++ ) {
    	st[i] = 23;
    	st2[i] = 17;
    }
    for ( i = 1 ; i <= n ; i++ ) {
        for ( j = 1 ; j <= i ; j++ ) {
            st[j] = (st[j] * base + a[i]) % mod;
            st2[j] = (st2[j] * base + a[i]) % mod2;
            top++;
            s[top].len = i-j+1; s[top].ha = st[j]; s[top].l = j;
            s[top].ha2 = st2[j];
        }
    }
	sort ( s + 1 , s + 1 + top , cmp );
	for ( i = 1 ; i <= top ; i++ ) {
		//printf ( "%lld %lld %lld\n" , s[i].ha , s[i].len , s[i].l );
		if ( i == 1 || (s[i].ha!=s[i-1].ha || s[i].len != s[i-1].len || s[i].ha2 != s[i-1].ha2) ) {
			ok[s[i].l][s[i].l+s[i].len-1] = 1;
		}
	}
	for ( i = 1 ; i <= n ; i++ ) {
		for ( j = 1 ; j <= i ; j++ ) {
			if ( ok[j][i] ) {
                ans = (ans + dp[j][i]) % mod;
                //printf ( "%lld %lld %lld\n" , i , j , dp[j][i] );
			}
		}
        printf ( "%lld\n" , ans % mod );
	}
}
int main () {
	work ();
	return 0;
}