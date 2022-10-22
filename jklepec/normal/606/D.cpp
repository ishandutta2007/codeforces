#include <bits/stdc++.h>
#define iter(i) set< i >::iterator
#define FOR( i, a, b ) for( int i = a; i < b; i++ )
#define REP( i, a ) for( int i = 0; i < a; i++ )
using namespace std;

typedef long long llint;
typedef pair< int, int > point;

const int MaxN = 100100, MOD = 1e9 + 7, B = 3137;

struct veza {

    int val, index;
    bool uzmi;

    veza( int x, int y, bool z ) {
        val = x; index = y; uzmi = z;
    }

    friend bool operator <( const veza &A, const veza &B ) {
        if( A.val == B.val ) return A.uzmi > B.uzmi;
        return A.val < B.val;
    }

};

int use, nxt[MaxN], tmp, zabacanje;
int n, m;

vector< veza > v;
point sol[MaxN];

int main() {

    ios_base::sync_with_stdio(false);

    cin >> n >> m;
    use = zabacanje = 1;
    FOR( i, 1, n+1 )
        nxt[i] = i + 2;

    REP( i, m ) {
        int a, b;
        cin >> a >> b;
        v.push_back( veza( a, i, b == 1 ) );
    }

    sort( v.begin(), v.end() );

    REP( i, m ) {
        veza edge = v[i];
        if( edge.uzmi ) {
            sol[ edge.index ] = point( use, use + 1 );
            use++;
            zabacanje = 1;
        }
        else{
            if( nxt[zabacanje] > use and nxt[zabacanje] <= n ) {
                cout << -1;
                return 0;
            }
            sol[ edge.index ] = point( zabacanje, nxt[ zabacanje ] );
            nxt[ zabacanje ] ++;
            if( nxt[ zabacanje ] > use ) zabacanje ++;
        }
    }

    REP( i, m )
        cout << sol[i].first << " " << sol[i].second << endl;
    return 0;
}