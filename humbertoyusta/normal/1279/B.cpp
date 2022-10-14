#include<bits/stdc++.h>
#define maxn 200010
#define inf 1000000007
#define  f first
#define s second
#define lg2(x) 31 - __builtin_clz(x)
#define db(x) cerr << #x << ": " << (x) << '\n';
#define int long long
using namespace std;
typedef long double ld;
typedef pair<int,int> ii;

int a[100010];

int32_t main(){
    ios_base::sync_with_stdio(0);  cin.tie(0);
    cout.setf(ios::fixed);  cout.precision(0);

    //freopen("a.in","r",stdin);

    int tc;
    cin >> tc;
    while( tc-- ){
        int n, m;
        cin >> n >> m;
        int sum(0);
        ii mx({-1,-1}), ans({-1,-1});
        for(int i=1; i<=n; i++){
            cin >> a[i];
        }
        for(int i=1; i<=n; i++){
            sum += a[i];
            if( a[i] > mx.f )
                mx = { a[i] , i };
            if( sum - mx.f <= m )
                ans = max( ans , { i - 1 , mx.s } );
            if( sum <= m )
                ans = max( ans , { i , 0 } );
        }
        cout << ans.s << '\n';
    }

    return 0;
}