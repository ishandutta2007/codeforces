#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define x1 gdsfdsf
#define y1 fgdfgdfg
#define endl '\n'
#define exp fgfdgd
const ll DIM = 1E5+7;
const ll INF = 1E18;

int main()
{

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        ll sum = 0,flag = 0,prev = -1;
        for(ll i = 1;i<=n;++i){
            ll x;
            cin>>x;
            if (x<=prev){
                if (sum<prev-x+1){
                    flag = 1;
                }
                else{
                    sum-=prev+1-x;
                    x = prev+1;
                }
            }
            else{
                sum+=x-prev-1;
                x = prev+1;
            }
            prev = x;
        }
        if (flag==0)cout<<"Yes\n";
        else cout<<"No\n";
    }
    return 0;
}