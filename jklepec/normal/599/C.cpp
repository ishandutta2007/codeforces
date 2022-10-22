#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#define FOR( i, a, b ) for( int i = (a); i < (b); i++ )
#define REP( i, a ) for( int i = 0; i < (a); i++ )
using namespace std;

const int MaxN = 300100;
typedef pair< int, int > point;

int n;
int a[MaxN], MN[MaxN], open[MaxN], close[MaxN];
map< int, int > m, ind;
vector< point > v;


int main() {

    ios_base::sync_with_stdio( false );

    cin >> n;
    for( int i=0; i<n; i++ )
        cin >> a[i];

    MN[n] = 1e9;
    for( int i = n-1; i >= 0; i-- )
        MN[i] = min( MN[i+1], a[i] );

    for( int i = 0; i < n; i++ ) {
        int lo = i + 1, hi = n - 1;

        while( lo < hi ) {
            int mid = ( lo + hi + 1 ) / 2;
            if( MN[mid] < a[i] )
                lo = mid;
            else
                hi = mid - 1;
        }

        if( a[lo] < a[i] )
            v.push_back( make_pair( i, lo ) );
    }

    for( int i = 0; i < v.size(); i++ ) {
        open[ v[i].first ] += 1;
        close[ v[i].second ] += 1;
    }

    int in = 0, solution = 0;
    for( int i=0; i<n; i++ ) {
        if( in == 0 ) solution ++;
        in += open[i] - close[i];
    }
    cout << solution << endl;

    return 0;
}