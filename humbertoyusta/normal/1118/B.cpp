#include <bits/stdc++.h>
#define maxn 200010
#define inf 1000000007
#define f first
#define s second
#define lg2(x) ( 31 - __builtin_clz(x) )
#define db(x) cerr << #x << ": " << (x) << "\n";
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;

ll n,a[maxn],pse[maxn],pso[maxn],sse[maxn],sso[maxn],ans;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.setf(ios::fixed); cout.precision(0);

    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);

    cin >> n;

    for(int i=1; i<=n; i++){
        cin >> a[i];
        pse[i] = pse[i-1] + a[i] * ( i % 2 == 0 );
        pso[i] = pso[i-1] + a[i] * ( i % 2 == 1 );
    }

    for(int i=n; i>=1; i--){
        sse[i] = sse[i+1] + a[i] * ( i % 2 == 0 );
        sso[i] = sso[i+1] + a[i] * ( i % 2 == 1 );
    }

    for(int i=1; i<=n; i++)
        if( pse[i-1] + sso[i+1] == pso[i-1] + sse[i+1] )
            ans++;

    cout << ans << '\n';

    return 0;
}