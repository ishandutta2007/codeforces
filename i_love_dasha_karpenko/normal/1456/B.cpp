#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define x1 gdsfdsf
#define y1 fgdfgdfg
#define endl '\n'
const ll DIM = 2E5+7;
const ll INF = 1E15+7;
const ll LOG = 32;
ll A[DIM],mu[DIM];
ll clk(ll x){
    ll cnt = 0;
    ll mult = 1;
    while(mult*2<=x){
        mult*=2;
        ++cnt;
    }
    return cnt;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n;
    cin>>n;
    for(ll i = 1;i<=n;++i){
        cin>>A[i];
        mu[i] = clk(A[i]);
    }

    for(ll i = n;i>=3;--i){
        if (mu[i]==mu[i-1] && mu[i]==mu[i-2]){
            cout<<"1\n";
            return 0;
        }
    }
    ll ans = INF;
    for(ll j = 1;j<n;++j){
        ll res = 0,cur = A[j];
        for(ll beg = j-1;beg>=1;--beg){
            cur = A[beg]^cur;
            ++res;
            ll r1 = -1;
            ll c1 = 0;
            for(ll pos = j+1;pos<=n;++pos){
                c1^=A[pos];
                ++r1;
                if (c1<cur)ans = min(ans,res+r1);
            }
            if (cur>A[j+1])
                ans = min(ans,res);
        }
    }
    for(ll j = n;j>1;--j){
        ll res = 0,cur = A[j];
        for(ll beg = j+1;beg<=n;++beg){
            cur = cur^A[beg];
            ++res;
            ll r1 = -1,c1 = 0;
            for(ll pos = j-1;pos>=1;--pos){
                c1^=A[pos];
                ++r1;
                if (c1>cur)ans = min(ans,r1+res);
            }
            if (A[j-1]>cur)ans = min(ans,res);
        }
    }
    if (ans==INF)cout<<"-1\n";
    else cout<<ans<<endl;
    return 0;
}