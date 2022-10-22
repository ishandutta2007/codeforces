#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
#include <map>
using namespace std;

const int MaxN = 100100;

int n, mx, sol;
int a[ MaxN ];
int LOGMAN[ MaxN ];
bool bio[ MaxN ];

vector <int> mog;

int best( int val ) {

    int vrati = 0;

    for( int i=0; i<n; i++ ) {
        int x = a[i];
        bool correct = true;
        while( correct ) {
            if( val % x == 0 and ( LOGMAN[ val/x ] > 0 or val == x ) ) {
                vrati += LOGMAN[ val/x ];
                correct = false;
                break;
            }else x /= 2;
            vrati++;
            if( x == 0 ) return 1000000000;
        }
    }

    return vrati;

}

int main() {

    ios_base::sync_with_stdio( false );

    cin >> n;
    sol = 1000000000;

    for( int i=2; i<MaxN; i*=2 ) LOGMAN[i] = LOGMAN[i/2] + 1;

    for( int i=0; i<n; i++ ) {
        cin >> a[i];
        mx = max( mx, a[i] );
    }

    int MX = mx;

    while( mx > 0 ) {

        int ret = mx;
        while( mx <= MX ) {
            if( !bio[ mx ] ) {
                mog.push_back(mx);
                bio[mx] = true;
            }
            mx*=2;
        }
        mx = ret/2;

    }

    for( int i=0; i<mog.size(); i++ )
        sol = min( sol, best( mog[i] ) );

    cout << sol;
    return 0;
}