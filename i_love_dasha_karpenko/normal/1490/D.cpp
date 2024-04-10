#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define x1 gdsfdsf
#define y1 fgdfgdfg
#define endl '\n'
const ll DIM = 2E5+7;
const ll MAXN = 1E10;
ll A[DIM],depth[DIM];
void solve(ll l,ll r,ll d){
    if (l>r)return;
    ll mi = l;
    for(ll i = l;i<=r;++i){
        if (A[i]>A[mi])mi = i;
    }
    depth[mi] = d;
    solve(l,mi-1,d+1);
    solve(mi+1,r,d+1);
}
int main()
{

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        for(ll i = 1;i<=n;++i){
            cin>>A[i];
        }
        solve(1,n,0);
        for(ll i = 1;i<=n;++i){
            cout<<depth[i]<<' ';
        }
        cout<<endl;
    }
    return 0;
}