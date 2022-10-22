#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define razmak(x) cout << x << " _ "
#define red(x) cout << x << endl
using namespace std;

typedef long long llint;
typedef pair<llint, llint> point;
typedef set < llint >::iterator LITER;
typedef set < point >::iterator PITER;
set < llint > R;
set < point > K, L;

int n;
const int MaxN = 1e5 + 5;

llint k[MaxN], b[MaxN], x1, x2;

void solve() {

    REP( i, n ) {

        if( k[i] == 0 ) continue;

        llint y1 = min( k[i]*x1 + b[i], k[i]*x2 + b[i] );
        llint y2 = max( k[i]*x1 + b[i], k[i]*x2 + b[i] );

        if( k[i] > 0) {
            PITER itp = K.lower_bound( point( y1+1, -1000100000000 ) );
            if( itp != K.end() ) {
                point p = *itp;
                if( p.second < y2 ) {
                    cout << "YES";
                    return;
                }
            }

            PITER itL = L.lower_bound( point( y1, -1000100000000 ) );
            if( itL != L.end() ) {
                point p = *itL;
                if( p.first < y2 ) {
                    cout << "YES";
                    return;
                }
            }
        }else {
            PITER itp = L.lower_bound( point( y1+1, -1000100000000 ) );
            if( itp != L.end() ) {
                point p = *itp;
                if( p.second < y2 ) {
                    cout << "YES";
                    return;
                }
            }

            PITER itL = K.lower_bound( point( y1, -1000100000000 ) );
            if( itL != K.end() ) {
                point p = *itL;
                if( p.first < y2 ) {
                    cout << "YES";
                    return;
                }
            }
        }

        LITER itl = R.lower_bound( y1+1 );
        if( itl != R.end() ) {
            llint l = *itl;
            if( l < y2 ) {
                cout << "YES";
                return;
            }
        }

    }

    cout << "NO";
}

int main() {

    ios_base::sync_with_stdio( false );

    cin >> n;

    cin >> x1 >> x2;

    REP( i, n ) {
        cin >> k[i] >> b[i];
        if( !k[i] ) R.insert( b[i] );
        else {
            llint p1 = min( k[i]*x1 + b[i], k[i]*x2 + b[i] );
            llint p2 = max( k[i]*x1 + b[i], k[i]*x2 + b[i] );
            if( k[i] > 0 )
                K.insert( point( p1, p2 ) );
            else
                L.insert( point( p1, p2 ) );


        }
    }

    solve();

    return 0;
}