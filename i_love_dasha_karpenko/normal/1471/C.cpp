//#pragma GCC optimize ("O3")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define x1 gdsfdsf
#define y1 fgdfgdfg
#define endl '\n'
const ll DIM = 3E5+7;
const ll INF = 1E18;
ll A[DIM],B[DIM],prefA[DIM],prefB[DIM];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll t;
    cin>>t;
    while(t--){
        ll n,m;
        cin>>n>>m;
        for(ll i = 1;i<=n;++i)cin>>A[i];
        sort(A+1,A+1+n);
        for(ll i = 1;i<=m;++i)cin>>B[i];
        for(ll i = 1;i<=n;++i)prefA[i] = prefA[i-1]+B[A[i]];
        for(ll i = 1;i<=m;++i)prefB[i] = prefB[i-1]+B[i];
        ll res = INF;
        for(ll pres = 0;pres<=n;++pres){
            if (n-pres>m)continue;
            ll r = prefA[pres]+prefB[n-pres];
            res = min(res,r);
        }
        cout<<res<<endl;
    }

    return 0;
}