#include<bits/stdc++.h>
#define ii pair<int,int>
#define f first
#define s second
using namespace std;

ii a[1010];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for(int i=1; i<=n; i++){
        cin >> a[i].f;
        a[i].s = i;
    }

    sort( a + 1 , a + n + 1 );
    reverse( a + 1 , a + n + 1 );

    int ans = 0;
    for(int i=1; i<=n; i++)
        ans += ( i - 1 ) * a[i].f + 1;

    cout << ans << '\n';

    for(int i=1; i<=n; i++)
        cout << a[i].s << ' ';

    cout << '\n';

    return 0;
}