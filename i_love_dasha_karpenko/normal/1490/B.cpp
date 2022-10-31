#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define x1 gdsfdsf
#define y1 fgdfgdfg
#define endl '\n'
const ll DIM = 2E5+7;
const ll MAXN = 1E10;
ll A[DIM];
int main()
{

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        ll c[] = {0,0,0};
        for(ll i = 1;i<=n;++i){
            ll x;
            cin>>x;
            c[x%3]++;
        }
        ll res = 0;
        for(ll i = 0;i<=9;++i){
            if (c[i%3]>n/3){
                c[(i+1)%3]+=c[i%3]-n/3;
                res+=c[i%3]-n/3;
                c[i%3] = n/3;
            }
        }
        cout<<res<<endl;
    }
    return 0;
}