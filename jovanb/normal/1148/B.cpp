#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const ll INF = 1000000000000000LL;

ll a[2000005];
ll b[2000005];

int main(){
    ios_base::sync_with_stdio(false);
    cout.precision(10);
    cout<<fixed;

    ll n, m, ta, tb, k;
    cin >> n >> m >> ta >> tb >> k;
    if(k >= n || k >= m){
        cout << -1;
        return 0;
    }
    for(ll i=1; i<=n; i++){
        cin >> a[i];
    }
    for(ll i=1; i<=m; i++){
        cin >> b[i];
    }
    ll mx = 0;
    for(ll k1=0; k1<=k; k1++){
        ll tm = ta + a[k1+1];
        ll l = 0, r = m, rs = 0;
        while(l <= r){
            ll mid = (l+r)/2;
            if(b[mid] < tm){
                rs = mid;
                l = mid+1;
            }
            else r = mid-1;
        }
        if(rs + (k-k1) >= m){
            cout << -1;
            return 0;
        }
        mx = max(mx, b[rs+1+k-k1] + tb);
    }
    cout << mx;
    return 0;
}