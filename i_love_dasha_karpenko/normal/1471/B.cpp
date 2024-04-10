//#pragma GCC optimize ("O3")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define x1 gdsfdsf
#define y1 fgdfgdfg
#define endl '\n'
const ll DIM = 1E5+7;
const ll INF = 1E18;
ll A[DIM];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll t;
    cin>>t;
    while(t--){
        ll n,x;
        cin>>n>>x;
        ll mi = INF,pos = 0;
        for(ll i = 1;i<=n;++i){
             cin>>A[i];
             ll xx = A[i];
             ll cnt = 0;
             while(xx%x==0){
                xx/=x;
                ++cnt;
             }
             if (mi>cnt){
                mi = cnt;
                pos = i;
             }
        }
        ll res = 0;
        for(ll i = pos;i<=n;++i)res+=A[i]*(mi+1);
        for(ll i = 1;i<pos;++i)res+=A[i]*(mi+2);
        cout<<res<<endl;
    }

    return 0;
}