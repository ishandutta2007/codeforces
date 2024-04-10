#pragma GCC optimize ("O3")
#include <bits/stdc++.h>

using namespace std;

typedef int ll;
typedef unsigned long long ull;
typedef pair<ull,ll> upp;

#define x1 gdsfdsf
#define y1 fgdfgdfg
#define endl '\n'
const ll DIM = 1E6+7;
const ll INF = 1E18;

ll M[DIM];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;

        ll ct = 0;
        vector<ll> vv;
        for(ll i = 1;i<=n;++i){
            ll x;
            cin>>x;
            ll num = 1;
            for(ll i = 2;i<=sqrt(x);++i){
                if (x%i!=0)continue;
                ll cnt = 0;
                while(x%i==0){
                    ++cnt;
                    x/=i;
                }
                if (cnt&1){
                    num*=i;
                }
            }
            if (x!=1){
                num*=x;
            }
            if (num==1)++ct;
            else{
                M[num]++;
                vv.push_back(num);
            }
        }
        ll mx = ct,sumodd = 0;
        for(auto to:vv){
            mx = max(mx,M[to]);
            if (M[to]%2==0)sumodd+=M[to];
            M[to] = 0;
        }

        ll q;
        cin>>q;
        while(q--){
            long long w;
            cin>>w;
            if (w==0)cout<<mx<<endl;
            else{
                cout<<max(mx,sumodd+ct)<<endl;
            }
        }
    }

    return 0;
}