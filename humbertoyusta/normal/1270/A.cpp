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

int32_t main(){
    ios_base::sync_with_stdio(0);  cin.tie(0);
    cout.setf(ios::fixed);  cout.precision(0);

    //freopen("a.in","r",stdin);

    int tc;
    cin >> tc;
    while( tc-- ){
        int n, m, k;
        cin >> n >> m >> k;
        int u, mx1=0, mx2=0;
        for(int i=1; i<=m; i++){
            cin >> u;
            mx1 = max( mx1 , u );
        }
        for(int i=1; i<=k; i++){
            cin >> u;
            mx2 = max( mx2 , u );
        }
        if( mx1 > mx2 ) cout << "YES\n";
            else cout << "NO\n";
    }

    return 0;
}