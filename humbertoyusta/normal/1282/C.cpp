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

int n, m, k, c[maxn], c1, c2, cnt0, cnt1;
ii a[maxn];

int32_t main(){
    ios_base::sync_with_stdio(0);  cin.tie(0);
    cout.setf(ios::fixed);  cout.precision(0);

    //freopen("a.in","r",stdin);

    int tc;
    cin >> tc;
    while( tc--){

        cin >> n >> m >> c1 >> c2;

        for(int i=1; i<=n; i++){
            cin >> a[i].s;
            if( a[i].s == 0 ) cnt0++;
                else cnt1++;
        }
        for(int i=1; i<=n; i++)
            cin >> a[i].f;
        sort( a + 1 , a + n + 1 );
        a[n+1].f = m + 1;

        int ans = 0;
        for(int i=0; i<=n; i++){
            if( i ){
                if( a[i].s == 0 ) cnt0--;
                    else cnt1--;
                c[i] = c[i-1] + c1 * ( a[i].s == 0 ) + c2 * ( a[i].s == 1 );
            }
            if( c[i] < a[i+1].f ){
                int add = 0;
                int lt = a[i+1].f - 1 - c[i];
                int can0 = min( lt / c1 , cnt0 );
                add += can0;
                lt -= can0 * c1;
                int can1 = min( lt / c2 , cnt1 );
                add += can1;
                lt -= can1 * c2;
                ans = max( ans , i + add );
            }
        }

        cout << ans << '\n';
    }

    return 0;
}