#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define x1 gdsfdsf
#define y1 fgdfgdfg
#define endl '\n'
const ll DIM = 2E6+7;
const ll INF = 1E18+7;
ll A[DIM];
int main()
{

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        ll mi = INF;
        for(ll i = 1;i<=n;++i){
            cin>>A[i];
            mi = min(mi,A[i]);
        }
        ll res = n;
        for(ll i = 1;i<=n;++i){
            if (A[i]==mi)--res;
        }
        cout<<res<<endl;
    }

    return 0;
}