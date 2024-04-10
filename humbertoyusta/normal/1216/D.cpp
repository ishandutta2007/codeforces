#include<bits/stdc++.h>
#define ii pair<int,int>
#define f first
#define s second
using namespace std;

int a[200010], mx;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for(int i=1; i<=n; i++){
        cin >> a[i];
        mx = max ( mx , a[i] );
    }

    int gcd = mx - a[1];
    for(int i=1; i<=n; i++){
        a[i] = mx - a[i];
        gcd = __gcd( a[i] , gcd );
    }

    long long ans = 0;
    for(int i=1; i<=n; i++)
        ans += a[i] / gcd;

    cout << ans << ' ' << gcd << '\n';

    return 0;
}