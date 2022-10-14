#include <bits/stdc++.h>
#define maxn 100010
#define inf 1000000007
#define f first
#define s second
#define lg2(x) ( 31 - __builtin_clz(x) )
#define db(x) cerr << #x << ": " << (x) << "\n";
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;

int n, m, l, r, ans(inf);

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.setf(ios::fixed); cout.precision(0);

    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);

    cin >> n >> m >> l >> r;

    if( l == 1 && r == n)
        ans = 0;
    if( l == 1 )
        ans = min( ans , abs(m-r) + 1 );
    if( r == n )
        ans = min( ans , abs(m-l) + 1 );

    ans = min( ans , abs(m-l) + 1 + abs(l-r) + 1 );
    ans = min( ans , abs(m-r) + 1 + abs(l-r) + 1 );

    cout << ans << '\n';

    return 0;
}