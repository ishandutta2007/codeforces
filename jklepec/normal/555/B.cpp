#include <algorithm>
#include <iostream>
#include <vector>
#include <set>

#define x first
#define y second
using namespace std;

typedef long long ll;
typedef pair<ll, ll> point;
const int MaxN = 200100;

struct raz {
    ll x, y;
    int index;
    raz (ll x, ll y, int index) : x(x), y(y), index(index) {};
    inline friend bool operator < ( const raz &A, const raz &B ) {
        return A.y < B.y;
    }
};

int n, m;
int sol[MaxN];
point a[MaxN];
string S;
vector < raz > v;

set < point > ms;
set < point >::iterator it;

void load() {
    ios_base::sync_with_stdio(0);

    cin >> n >> m;
    for( int i=0; i<n; i++ )
        cin >> a[i].x >> a[i].y;

    for( int i=1; i<=m; i++ ) {
        ll val;
        cin >> val;
        ms.insert(point(val, i));
    }
}

void make_int() {
    for( int i=1; i<n; i++ ) {
        ll low = a[i].x - a[i-1].y;
        ll hig = a[i].y - a[i-1].x;
        v.push_back( raz( low, hig, i) );
    }
    sort( v.begin(), v.end() );
}

void solve() {
    for( int i=0; i<v.size(); i++ ) {

        it = ms.lower_bound( point( v[i].x, -1 ) );
        ll most = (*it).x;

        if( most <= v[i].y ) {
            sol[v[i].index] = (*it).y;
            ms.erase( it );
        }else S = "No";
    }
}

int main() {

    S = "Yes";
    load();
    make_int();
    solve();
    cout << S << endl;
    if( S == "No" ) return 0;
    for( int i=1; i<n; i++ ) cout << sol[i] << " ";
    return 0;
}