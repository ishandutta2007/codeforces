#include <bits/stdc++.h>
#define maxn 23
#define maxN 1000100
#define inf 1000000007
#define f first
#define s second
#define lg2(x) ( 31 - __builtin_clz(x) )
#define db(x) cerr << #x << ": " << (x) << "\n";
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;

int dp[1<<maxn],a[maxN],b[maxN],n;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.setf(ios::fixed); cout.precision(0);

    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);

    cin >> n;

    memset( dp , -1 , sizeof dp );

    for(int i=1; i<=n; i++){
        cin >> a[i];
        dp[a[i]] = a[i];

        b[i] = a[i];
        for(int j=0; j<22; j++)
            b[i] ^= (1<<j);
    }

    for(int i=0; i<22; i++)
        for(int j=1; j<(1<<22); j++)
            if( ( j & (1<<i) ) == 0 && dp[j] != -1 )
                dp[j^(1<<i)] = dp[j];

    for(int i=1; i<=n; i++){
        cout << dp[b[i]] << ' ';
    }

    return 0;
}