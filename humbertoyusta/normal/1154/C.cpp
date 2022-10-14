#include<bits/stdc++.h>
#define maxn 100010
#define inf 1000000007
#define ii pair<int,int>
#define f first
#define s second
#define db(x) cerr << #x << ": " << (x) << '\n';
#define lg2(x) 31 - __builtin_clz(x)
#define int long long
using namespace std;

int a,b,c,ans,h1,h2,h3,p1,p2,p3,res;

bool can(int n,int start){

    int w = ( n - start ) / 7;
    p1 = w * 3, p2 = w * 2, p3 = w * 2;

    for(int i=start+w*7+1; i<=n; i++){
        if( i % 7 == 0 || i % 7 == 3 || i % 7 == 6 ) p1++;
        if( i % 7 == 1 || i % 7 == 5 ) p2++;
        if( i % 7 == 2 || i % 7 == 4 ) p3++;
    }

    if( p1 > a || p2 > b || p3 > c ) return false;
    return true;
}

main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.setf(ios::fixed); cout.precision(0);

    //freopen("a.in","r",stdin);
    //freopen("a.out","w".stdout);

    cin >> a >> b >> c;

    for(int st=0; st<7; st++){
        int l = st, r = 1000000000000ll;
        res = -1;
        while( l < r ){
            int mi = ( l + r ) / 2;
            if( can(mi,st) ) res = mi, l = mi + 1;
                else r = mi;
        }
        ans = max( ans , res - st );
    }

    cout << ans << '\n';

    return 0;
}