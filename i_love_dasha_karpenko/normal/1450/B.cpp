#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define x1 gdsfdsf
#define y1 fgdfgdfg
#define endl '\n'
const ll DIM = 107;
pair<ll,ll> A[DIM];
int main()
{

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t;
    cin>>t;
    while(t--){
        ll n,k;
        cin>>n>>k;
        ll flag = 0,ff = 0;

        for(ll i = 1;i<=n;++i){
            cin>>A[i].first>>A[i].second;
            if (!(A[i]==A[1]))ff = 1;
        }
        if (ff==0){
            cout<<0<<endl;
            continue;
        }
        for(ll i = 1;i<=n;++i){
            ll fl = 0;
            for(ll j = 1;j<=n;++j){
                if (abs(A[i].first-A[j].first)+abs(A[i].second-A[j].second)>k){
                    fl = 1;
                    break;
                }
            }
            if (fl==0){
                flag = 1;
                break;
            }
        }
        if (flag==1)cout<<1<<endl;
        else{
            cout<<-1<<endl;
        }
    }
    return 0;
}