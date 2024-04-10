#include<bits/stdc++.h>
#define maxn 100010
#define ii pair<int,int>
#define lg2(x) 31 - __builtin_clz(x)
#define db(x) cerr << #x << ": " << (x) << '\n';
using namespace std;
typedef long long ll;
typedef long double ld;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tc;
    cin >> tc;
    while( tc-- ){
        int n, h, u, v, mc = 0, bc = 0;
        cin >> n >> h;

        for(int i=1; i<=n; i++){
            cin >> u >> v;
            if( u > mc ) mc = u;
            if( u - v > bc ) bc = u - v;
        }

        if( bc == 0 ){
            if( mc >= h ){ cout << 1 << '\n'; continue; }
                else { cout << -1 << '\n'; continue; }
        }
        cout << max( 0 , ( h - mc + bc - 1 ) / bc ) + 1 << '\n';
    }

    return 0;
}