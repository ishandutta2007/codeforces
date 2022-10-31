#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define x1 dfds
#define y1 dsfdsfe
#define endl '\n'
const ll INF = 1E17;
const ll DIM = 2E5+7;
ll A[DIM];
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t;
    cin>>t;
    while(t--){
        ll n,w;
        cin>>n>>w;
        ll flag = 0;
        ll l = (w+1)/2;
        for(ll i = 1;i<=n;++i){
            cin>>A[i];

        }
        for(ll i = 1;i<=n;++i){
            if (A[i]>=l && A[i]<=w){
                flag = 1;
                cout<<1<<endl;
                cout<<i<<endl;
                break;
            }
        }
        if (flag)continue;
        ll sum = 0;
        vector<ll> ans;
        for(ll i = 1;i<=n;++i){
            if (A[i]<=w){
                sum+=A[i];
                ans.push_back(i);

            }
            if (sum>=l)break;
        }
        if (sum<l)cout<<-1<<endl;
        else{
            cout<<ans.size()<<endl;
            for(ll to:ans)cout<<to<<' ';
            cout<<endl;
        }


    }

    return 0;
}