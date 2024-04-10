#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define x1 gdsfdsf
#define y1 fgdfgdfg
#define endl '\n'
const ll DIM = 2E5+7;
ll A[DIM];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        for(ll i = 1;i<=n;++i)cin>>A[i];
        ll cnt = 0,res = 0;
        A[n+1] = 2*n+1;
        for(ll i = n;i>=1;--i){
            cnt+=A[i+1]-A[i]-1;
            if (cnt>0){
                ++res;
                --cnt;
            }
        }
        cnt = 0;
        for(ll i = 1;i<=n;++i){
            cnt+=A[i]-A[i-1]-1;
            if (cnt>0){
                ++res;
                --cnt;
            }
        }
        res-=n;
        cout<<res+1<<endl;
    }
    return 0;
}