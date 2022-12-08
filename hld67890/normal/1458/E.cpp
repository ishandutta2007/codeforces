#include <stdio.h>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

struct so {
    long long x , y , i;
} sx[210000] , sy[320000];
long long n , m;
map < pair<long long,long long> , long long > cut;
map < long long , pair<long long,long long> > lines;
set < long long > cutx , cuty;
long long used[210000];
bool cmp1 ( so x1 , so x2 ) {
    return x1.x < x2.x;
}
bool cmp2 ( so x1 , so x2 ) {
    return x1.y < x2.y;
}
void work () {
    long long i , x , y , xi , yi;
    long long nowx , nowy , nx , ny , len , delx , dely;
    scanf ( "%lld%lld" , &n , &m );
    cut[make_pair(0,0)] = 1;
    cutx.insert ( 0 );
    cuty.insert ( 0 );
    for ( i = 1 ; i <= n ; i++ ) {
        scanf ( "%lld%lld" , &x , &y );
        cut[make_pair(x,y)] = 1;
        sx[i].x = x; sx[i].y = y; sx[i].i = i;
        sy[i].x = x; sy[i].y = y; sy[i].i = i;
    }
    sort ( sx + 1 , sx + 1 + n , cmp1 );
    sort ( sy + 1 , sy + 1 + n , cmp2 );
    cutx.insert ( 214748364777ll );
    cuty.insert ( 214748364777ll );
    nowx = nowy = 0;
    xi = yi = 1;
    while ( 1 ) {
		while ( xi <= n && nowx >= sx[xi].x ) {
            cuty.insert ( sx[xi].y );
            xi++;
        }
        while ( yi <= n && nowy >= sy[yi].y ) {
            cutx.insert ( sy[yi].x );
            yi++;
        }
        nx = *cutx.lower_bound ( nowx );
        ny = *cuty.lower_bound ( nowy );
        if ( xi <= n && nx > sx[xi].x ) {
        	nx = sx[xi].x;
        }
        if ( yi <= n && ny > sy[yi].y ) {
        	ny = sy[yi].y;
        }
        //printf ( "%lld %lld\n" , nowx , nowy );
        len = min ( nx - nowx , ny - nowy );
        if ( len >= 2147483647ll ) {
            lines[nowx] = make_pair(nowy,21474836477ll );
            break;
        }
        if ( nowx == nx ) delx = 1;
        else delx = 0;
        if ( nowy == ny ) dely = 1;
        else dely = 0;
        if ( len != 0 ) {
            lines[nowx] = make_pair(nowy,len);
        }
        //printf ( "nowx%lld nowy%lld nx%lld ny%lld len%lld\n" , nowx , nowy , nx , ny , len );
        nowx += len + delx;
        nowy += len + dely;
    }
    lines[0] = make_pair(0,1);
    /*for ( auto id : lines ) {
        printf ( "%lld %lld %lld\n" , id.first , id.second.first , id.second.second );
    }*/
    for ( i = 1 ; i <= m ; i++ ) {
        scanf ( "%lld%lld" , &x , &y );
        if ( cut.find ( make_pair(x,y) ) != cut.end () ) {
            printf ( "LOSE\n" );
            continue;
        }
        auto nn = lines.upper_bound ( x );
        nn--;
        //printf ( "%lld %lld %lld\n" , nn -> first , nn -> second.first , nn -> second.second );
        if ( x - y == nn->first-nn->second.first && x <= nn -> first + nn -> second.second - 1 ) {
            printf ( "LOSE\n" );
            continue;
        }
        printf ( "WIN\n" );
    }
}
int main () {
	//
    work ();
    return 0;
}