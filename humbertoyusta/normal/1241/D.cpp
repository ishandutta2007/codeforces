#include<bits/stdc++.h>
#define maxn 300010
#define inf 1000000007
#define  f first
#define s second
#define lg2(x) 31 - __builtin_popcount(x)
#define db(x) cerr << #x << ": " << (x) << '\n';
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;

int tc, n, a[maxn], dp[maxn], b[maxn];
set<int> s;
ii v[maxn];

int main(){
    ios_base::sync_with_stdio(0);  cin.tie(0);
    cout.setf(ios::fixed);  cout.precision(0);

    cin >> tc;
    while( tc-- ){

        cin >> n;

        s.clear();

        for(int i=1; i<=n; i++){
            cin >> a[i];
            s.insert( a[i] );
            v[i].f = inf;
            v[i].s = 0;
        }

        int cnt = 0;
        for( auto it : s )
            b[it] = ++cnt;

        for(int i=1; i<=n; i++){
            a[i] = b[a[i]];
            v[a[i]].f = min( v[a[i]].f , i );
            v[a[i]].s = max( v[a[i]].s , i );
        }

        int ans = 0;
        for(int i=1; i<=cnt; i++){
            dp[i] = 1;
            if( v[i].f > v[i-1].s )
                dp[i] += dp[i-1];
            ans = max( ans , dp[i] );
        }

        cout << cnt - ans << '\n';
    }

    return 0;
}