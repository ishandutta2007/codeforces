#include<bits/stdc++.h>
#define maxn 1000010
#define mod 998244353
#define  f first
#define s second
#define lg2(x) 31 - __builtin_clz(x)
#define db(x) cerr << #x << ": " << (x) << '\n';
#define int long long
using namespace std;
typedef long double ld;
typedef pair<int,int> ii;

int n, cnt[maxn], fc[maxn];
bool mk[maxn];
vector<int> v[maxn];

int qpow(int b,int e){
    if( e == 0ll ) return 1ll;
    if( e % 2ll == 1ll ) return ( qpow(b,e-1ll) * b ) % mod;
    int paw = qpow(b,e/2ll);
    return ( paw * paw ) % mod;
}

int inv(int x){
    return qpow(x,mod-2);
}

int32_t main(){
    ios_base::sync_with_stdio(0);  cin.tie(0);
    cout.setf(ios::fixed);  cout.precision(0);

    //freopen("a.in","r",stdin);

    cin >> n;

    int u;
    for(int i=1; i<=n; i++){
        cin >> cnt[i];
        for(int j=1; j<=cnt[i]; j++){
            cin >> u;
            v[i].push_back(u);
            fc[u]++;
        }
    }

    int ans = 0;
    for(int i=1; i<=n; i++){
        for( auto j : v[i] ){
            ans = ( ans + ( ( ( inv(n) * inv(cnt[i]) ) % mod ) * ( ( ( fc[j] ) * inv(n) ) % mod ) ) % mod ) % mod;
        }
    }

    cout << ans << '\n';

    return 0;
}