#include<bits/stdc++.h>
#define maxn 1000005
#define int long long
#define ii pair<int,int>
#define f first
#define s second
#define db(x) cerr<<#x<<": "<<(x)<<'\n'
using namespace std;
typedef long long ll;

int a[maxn], ans;

main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tc;
    cin >> tc;
    while( tc-- ){
        int n;
        cin >> n;
        ans = 0;
        for(int i=1; i<=n; i++)
            cin >> a[i];
        sort(a+1,a+n+1);
        reverse(a+1,a+n+1);
        for(int i=1; i<=n; i++)
            ans = max( ans , min( i , a[i] ) );
        cout << ans << '\n';
    }

    return 0;
}