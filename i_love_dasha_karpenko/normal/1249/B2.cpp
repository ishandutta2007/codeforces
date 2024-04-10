//#pragma GCC optimize ("O3")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ull,ll> upp;

#define x1 gdsfdsf
#define y1 fgdfgdfg
#define endl '\n'
const ll DIM = 2E5+7;
ll A[DIM],comp[DIM],compsz[DIM];
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
            comp[i] = compsz[i] = 0;
        }
        ll ptr = 0;
        for(ll i = 1;i<=n;++i){
            if (comp[i]==0){
                comp[i] = ++ptr;
                ll pos = A[i];
                compsz[ptr] = 1;
                while(1){
                    if (comp[pos])break;
                    ++compsz[ptr];
                    comp[pos] = ptr;
                    pos = A[pos];
                }
            }
            cout<<compsz[comp[i]]<<' ';
        }
        cout<<endl;
    }
    return 0;
}