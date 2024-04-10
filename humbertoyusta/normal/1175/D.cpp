#include <bits/stdc++.h>
#define maxn 300010
#define inf (1ll<<60)
#define lg2(x) ( 31 - __builtin_clz(x) )
#define db(x) cerr << #x << ": " << (x) << "\n";
using namespace std;
typedef long long ll;
typedef long double ld;


ll n,k,a[maxn];
ll sum[maxn],ans;
vector<ll> ssum;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.setf(ios::fixed); cout.precision(0);

    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);

    cin >> n >> k;

    for(int i=1; i<=n; i++)
        cin >> a[i];
    for(int i=n; i>=1; i--){
        sum[i] = sum[i+1] + a[i];
        if( i > 1 ) ssum.push_back(sum[i]);
    }

    stable_sort(ssum.begin(),ssum.end());
    reverse(ssum.begin(),ssum.end());

    for(int i=0; i<k-1; i++)
        ans += ssum[i];

    cout << ans + sum[1] << '\n';

    return 0;
}