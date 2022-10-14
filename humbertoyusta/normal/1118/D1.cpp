#include <bits/stdc++.h>
#define maxn 200002
#define inf 1000000007
#define f first
#define s second
#define lg2(x) ( 31 - __builtin_clz(x) )
#define db(x) cerr << #x << ": " << (x) << "\n";
#define int long long
using namespace std;
typedef long double ld;
typedef pair<int,int> ii;

int n,m,psum[maxn],a[maxn],mx;

bool can(int k){
    int res = 0;
    for(int i=1; i<=n; i++){
        res += max( 0ll , a[i] - (i-1)/k );
    }
    return res >= m;
}

 main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.setf(ios::fixed); cout.precision(0);

    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);

    cin >> n >> m;

    for(int i=1; i<=n; i++){
        cin >> a[i];
        mx = max( mx , a[i] );
    }
    stable_sort(a+1,a+n+1);
    reverse(a+1,a+n+1);

    int ans = -1;
    int l = 1 , r = n+1;
    while( l < r ){
        int mi = ( l + r ) >> 1;
        if( !can(mi) ) l = mi + 1;
            else ans = mi, r = mi;
    }

    cout << ans << '\n';

    return 0;
}