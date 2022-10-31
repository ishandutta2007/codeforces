#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define x1 gdsfdsf
#define y1 fgdfgdfg
#define endl '\n'
const ll DIM = 2E5+7;
const ll MAXN = 1E10;
const ll INF = 1E18;
pair<ll,ll> A[DIM];

int main()
{

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;

        for(ll i = 1;i<=n;++i){
            cin>>A[i].first;
            A[i].second = i;
        }
        sort(A+1,A+1+n);
        stack<ll> S;
        ll sum = 0;
        vector<ll> ans;
        ll mi = INF;
        ll l = 1,r = n;
        while(l!=r){
            ll tm = (l+r)/2;
            ll sum = A[tm].first;
            ll flag = 0;
            for(ll i = 1;i<=n;++i){
                if (i==tm)continue;
                if (sum<A[i].first){
                    flag = 1;
                    break;
                }
                sum+=A[i].first;
            }
            if (flag==0)r = tm;
            else l = tm+1;
        }
        for(ll i = l;i<=n;++i){
            ans.push_back(A[i].second);
        }
        sort(ans.begin(),ans.end());
        cout<<ans.size()<<endl;
        for(ll to:ans)cout<<to<<' ';
        cout<<endl;
    }
    return 0;
}