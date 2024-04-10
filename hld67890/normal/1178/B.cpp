#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

//long long
char z[1200000];
long long n;
long long s[1200000] , p[1200000];
long long ans;
void work () {
    long long i;
    scanf ( "%s" , z + 1 );
    n = strlen ( z + 1 );
    for ( i = 1 ; i <= n ; i++ ) {
        p[i] = p[i-1];
        if ( z[i] == 'v' && z[i+1] == 'v' ) p[i]++;
    }
    for ( i = n ; i >= 1 ; i-- ) {
        s[i] = s[i+1];
        if ( z[i] == 'v' && z[i+1] == 'v' ) s[i]++;
    }
    for ( i = 1 ; i <= n ; i++ ) {
        if ( z[i] == 'o' ) {
            ans += (p[i]*s[i]);
        }
    }
    printf ( "%lld\n" , ans );
}
int main () {
    work ();
    return 0;
}