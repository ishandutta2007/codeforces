#include<bits/stdc++.h>
using namespace std;

int a[200005], b[200005];

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    for(int i=1; i<=n; i++)
        cin >> a[i];
    for(int i=1; i<=m; i++)
        cin >> b[i];

    int step = 1, ans = 0;
    for(int i=1; i<=n; i++)
        if( b[step] >= a[i] ) ans++, step++;

    cout << ans << '\n';

    return 0;
}