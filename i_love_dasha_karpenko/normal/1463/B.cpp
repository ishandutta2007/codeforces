#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define x1 gdsfdsf
#define y1 fgdfgdfg
#define endl '\n'
#define po(x) (1ll<<x)
const ll DIM = 50+7;
ll A[DIM];
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
        ll prev = 1;
        for(ll i = 1;i<=n;++i){
            while(prev*2<=A[i])prev*=2;
            while(prev>A[i] && prev>1)prev/=2;
            cout<<prev<<' ';
        }
        cout<<endl;
    }
    return 0;
}