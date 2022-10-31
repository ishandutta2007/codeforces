//#pragma GCC optimize ("O3")
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
#define endl '\n'
#define x1 dfgfg
#define y1 dfgdfg
const ll DIM = 5E6+7;
ll A[DIM];
pair<ll,ll> sum[DIM];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n;
    cin>>n;
    for(ll i = 1;i<=n;++i) {
        cin >> A[i];
    }
    for(ll i = 1;i<=n;++i){
        for(ll j = i-1;j>=1;--j){
            if (sum[A[i]+A[j]].first!=0 && sum[A[i]+A[j]].first!=j && sum[A[i]+A[j]].second!=j && sum[A[i]+A[j]].first!=i & sum[A[i]+A[j]].second!=i){
                cout<<"YES\n";
                cout<<sum[A[i]+A[j]].first<<' '<<sum[A[i]+A[j]].second<<' '<<j<<' '<<i<<endl;
                return 0;
            }
            else if (sum[A[i]+A[j]].first==0)sum[A[i]+A[j]] = {i,j};
        }
    }
    cout<<"NO\n";

    return 0;
}