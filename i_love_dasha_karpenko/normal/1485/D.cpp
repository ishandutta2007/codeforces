//#pragma GCC optimize ("O3")
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
#define endl '\n'
#define x1 dfgfg
#define y1 dfgdfg
const ll DIM = 2E5+7;
const ll INF = 1E18;
const ll MOD = 1E9+7;
ll num[20];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll base = 720720;
    for(ll i = 1;i<=16;++i){
        for(ll j = 1;j*i<base;++j){
            ll val = sqrt(sqrt(base-j*i));
            if (val*val*val*val==base-j*i){
                num[i] = j;
                break;
            }
        }
    }
    ll n,m;
    cin>>n>>m;
    for(ll i = 1;i<=n;++i){
        for(ll j = 1;j<=m;++j){
            ll x;
            cin>>x;
            if ((i+j)%2){
                cout<<base<<' ';
                continue;
            }
            cout<<num[x]*x<<' ';
        }
        cout<<endl;
    }

    return 0;
}