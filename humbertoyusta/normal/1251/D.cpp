#include<bits/stdc++.h>
#define int long long
#define maxn 200010
#define mod 1000000007
#define  f first
#define s second
#define lg2(x) 31 - __builtin_popcount(x)
#define db(x) cerr << #x << ": " << (x) << '\n';
using namespace std;
typedef long double ld;
typedef pair<int,int> ii;

int n, a[maxn], b[maxn] , arr[maxn], hv;

bool can(int mi){
    if( arr[n/2+1] >= mi ) return true;

    vector<ii> v;
    for(int i=1; i<=n; i++)
        if( b[i] >= mi )
            v.push_back({a[i],i});

    sort(v.begin(),v.end());
    reverse(v.begin(),v.end());

    bool mk[ n + 1 ];
    memset( mk , 0 , sizeof mk );

    if( v.size() <= n / 2 ) return ( arr[n/2+1] >= mi );

    for(int i=0; i<=n/2; i++)
        mk[v[i].s] = 1;

    int nhv = hv;
    for(int i=1; i<=n; i++)
        if( !mk[i] ) nhv -= a[i];
            else nhv -= max( 0ll , a[i] - mi );

    return ( nhv >= ( n + 1 ) / 2 * mi );
}

main(){
    ios_base::sync_with_stdio(0);  cin.tie(0);
    cout.setf(ios::fixed);  cout.precision(0);

    int tc;
    cin >> tc;
    while( tc-- ){

        cin >> n >> hv;

        for(int i=1; i<=n; i++){
            cin >> a[i] >> b[i];
            arr[i] = a[i];
        }
        sort( arr + 1 , arr + n + 1 );

        int l = 0, r = 1000000000;
        while( l < r ){
            int mi = ( l + r ) >> 1;
            if( can(mi) ) l = mi + 1;
                else r = mi;
        }
        if( can(l+1) ) l++;
        if( !can(l) ) l--;

        cout << l << '\n';
    }

    return 0;
}