#include<bits/stdc++.h>
using namespace std;

int a[200005];
bool ans[200005];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tc;
    cin >> tc;
    while( tc-- ){
        int n;
        cin >> n;

        for(int i=1; i<=n; i++){
            int u; cin >> u;
            a[u] = i;
        }

        int l = a[1]; int r = a[1];
        for(int i=1; i<=n; i++){
            l = min( l , a[i] );
            r = max( r , a[i] );
            ans[i] = ( r - l + 1 == i );
        }

        for(int i=1; i<=n; i++)
            cout << ans[i];
        cout << '\n';
    }

    return 0;
}