#include <iostream>
#include <set>
#define lb lower_bound
#define ub upper_bound
#define EXIT_SUCCESS 0
using namespace std;
typedef set< int >::iterator iter;

multiset < int > hor, ver;
multiset < int > hor_rez, ver_rez;

void init( int w, int h ) {
    hor.insert( h );
    ver.insert( w );
    hor_rez.insert( 0 );
    ver_rez.insert( 0 );
    hor_rez.insert( h );
    ver_rez.insert( w );
}

void do_one() {

    int x;
    char c;
    cin >> c >> x;

    if( c == 'H' ) {
        hor_rez.insert( x );
        iter it1 = hor_rez.ub( x );
        iter it2 = hor_rez.lb( x );
        it1 --; it1 --; it2 ++;
        hor.insert( x - *it1 );
        hor.insert( *it2 - x );
        iter it = hor.lb( *it2 - *it1 );
        hor.erase( it );
    }

    if( c == 'V' ) {
        ver_rez.insert( x );
        iter it1 = ver_rez.ub( x );
        iter it2 = ver_rez.lb( x );
        it1 --; it1--; it2++;
        ver.insert( x - *it1 );
        ver.insert( *it2 - x );
        iter it = ver.lb( *it2 - *it1 );
        ver.erase( it );
    }

    cout << (long long)*hor.rbegin() * (long long)*ver.rbegin() << endl;
}

int main() {

    ios_base::sync_with_stdio( false );
    int w, h, n;
    cin >> w >> h >> n;
    init( w, h );

    while( n-- )
        do_one();

    return EXIT_SUCCESS;
}