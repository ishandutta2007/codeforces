#include<bits/stdc++.h>
#define int long long
using namespace std;

int ans[4];

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, a, b;
    cin >> n >> a >> b;

    for(int i=1; i<=n; i++){
        int u, v;
        cin >> u >> v;
        if( u < a  ) ans[0]++;
        if( u > a  ) ans[1]++;
        if( v < b  ) ans[2]++;
        if( v > b  ) ans[3]++;
    }

    if( ans[0] >= ans[1] && ans[0] >= ans[2] && ans[0] >= ans[3] ){ cout << ans[0] << '\n' << a-1 << ' ' << b << '\n'; return 0; }
    if( ans[1] >= ans[0] && ans[1] >= ans[2] && ans[1] >= ans[3] ){ cout << ans[1] << '\n' << a+1 << ' ' << b << '\n'; return 0; }
    if( ans[2] >= ans[0] && ans[2] >= ans[1] && ans[2] >= ans[3] ){ cout << ans[2] << '\n' << a << ' ' << b-1 << '\n'; return 0; }
    if( ans[3] >= ans[0] && ans[3] >= ans[1] && ans[3] >= ans[2] ){ cout << ans[3] << '\n' << a << ' ' << b+1 << '\n'; return 0; }

    return 0;
}