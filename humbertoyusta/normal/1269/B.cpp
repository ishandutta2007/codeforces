#include<bits/stdc++.h>
#define maxn 2020
#define mod 1000000007
#define  f first
#define s second
#define lg2(x) 31 - __builtin_clz(x)
#define db(x) cerr << #x << ": " << (x) << '\n';
#define int long long
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;

int n, m, a[maxn], b[maxn], c[maxn], mx;
set<int> s;

int32_t main(){
    ios_base::sync_with_stdio(0);  cin.tie(0);
    cout.setf(ios::fixed);  cout.precision(0);

    //freopen("a.in","r",stdin);

    cin >> n >> m;

    for(int i=1; i<=n; i++){
        cin >> a[i];
    }
    for(int i=1; i<=n; i++){
        cin >> b[i];
        mx = max( mx , b[i] );
    }
    stable_sort( b + 1 , b + n + 1 );

    for(int i=1; i<=n; i++){
        if( a[i] <= mx ) s.insert(mx-a[i]);
            else s.insert(mx+m-a[i]);
    }

    for( auto it : s ){
        for(int i=1; i<=n; i++)
            c[i] = ( a[i] + it ) % m;
        stable_sort( c + 1 , c + n + 1 );
        int cnt = 0;
        for(int i=1; i<=n; i++)
            if( b[i] == c[i] )
                cnt++;
        if( cnt == n ){
            cout << it << '\n';
            return 0;
        }
    }

    return 0;
}