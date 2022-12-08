#include <stdio.h>
#include <algorithm>

using namespace std;

const int mod = 998244353;
int w , h;
int ans;
void work () {
    int i;
    scanf ( "%d%d" , &w , &h );
    ans = 1;
    for ( i = 1 ; i <= w + h ; i++ ) {
        ans = (ans*2) % mod;
    }
    printf ( "%d\n" , ans );
}
int main () {
    work ();
    return 0;
}