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

int a[maxn], b[maxn], id[maxn];

int32_t main(){
    ios_base::sync_with_stdio(0);  cin.tie(0);
    cout.setf(ios::fixed);  cout.precision(0);

    //freopen("a.in","r",stdin);

    int tc;
    cin >> tc;
    while( tc-- ){
        int n, m;
        cin >> n >> m;
        for(int i=1; i<=n; i++){
            cin >> a[i];
            id[a[i]] = i;
        }
        for(int i=1; i<=m; i++)
            cin >> b[i];
        int mx = 0, ans = 0;
        for(int i=1; i<=m; i++){
            if( id[b[i]] > mx ){
                mx = id[b[i]];
                ans += ( id[b[i]] - 1 - ( i - 1 ) ) * 2 + 1;
                continue;
            }
            ans++;
        }
        cout << ans << '\n';
    }

    return 0;
}