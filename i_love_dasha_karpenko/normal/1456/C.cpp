#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define x1 gdsfdsf
#define y1 fgdfgdfg
#define endl '\n'
const ll DIM = 5E5+7;
ll A[DIM];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n,k;
    cin>>n>>k;
    for(ll i = 1;i<=n;++i){
        cin>>A[i];
    }
    sort(A+1,A+1+n,greater<ll>());
    ll res = 0,sum = 0;
    ll beg = n+1;
    for(ll i = 1;i<=n;++i){
        res+=sum;
        sum+=A[i];
        if (sum<0){
            beg = i;
            A[i] = sum;
            break;
        }
    }
    ll ptr = 0,mult = 0;
    for(ll i = n;i>=beg;--i){
        res+=mult*A[i];
        ++ptr;
        if (ptr>k){
            ptr = 0;
            mult++;
        }
    }
    cout<<res<<endl;
    return 0;
}