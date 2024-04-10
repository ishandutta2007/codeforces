#include <algorithm>
#include <iostream>
#include <vector>
#include <cstdio>
#include <set>
#include <map>
using namespace std;

const int MaxN = 300100;
typedef pair< int, int > point;
typedef long long ll;

#define x first
#define y second

vector <point> poz, neg;

int sol;

int main() {

    int n;
    cin >> n;

    for( int i=0; i<n; i++ ) {
        int x, y;
        cin >> x >> y;
        if( x > 0 )
            poz.push_back( point ( x, y ) );
        else
            neg.push_back( point( -x, y ) );
    }

    sort( poz.begin(), poz.end() );
    sort( neg.begin(), neg.end() );

    int mx = min( poz.size(), neg.size() );

    for( int i=0; i<(int)min( (int)poz.size(), mx + 1 ); i++ )
        sol += poz[i].y;

    for( int i=0; i<(int)min( (int)neg.size(), mx + 1 ); i++ )
        sol += neg[i].y;

    cout << sol;
    return 0;
}