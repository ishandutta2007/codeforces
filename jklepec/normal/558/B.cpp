#include <algorithm>
#include <iostream>
#include <vector>
#include <cstdio>
#include <set>
#include <map>
using namespace std;

const int MaxN = 300100;
const int Max = 1000100;
typedef pair< int, int > point;
typedef long long ll;

#define x first
#define y second

vector<point> v;

int n;
int lt, rt, curr, mx;
int bio[ Max ];
int f[ Max ], l[ Max ];

int main() {

    ios_base::sync_with_stdio(false);
    cin >> n;
    curr = n + 1;
    for( int i=0; i<n; i++ ) {
        int x;
        cin >> x;
        bio[ x ] ++;
        f[ x ] = bio[ x ] == 1 ? i : f[ x ];
        l[ x ] = i;
        mx = max( mx, bio[ x ] );
    }
    for( int i=1; i<Max; i++ ) {
        if( bio[ i ] != mx ) continue;
        if( l[ i ] - f[ i ] < curr ) {
            curr = l[ i ] - f[ i ];
            lt = f[ i ];
            rt = l[ i ];
        }
    }
    cout << lt+1 << " " << rt+1;
    return 0;
}