#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define endl '\n'
const ll DIM = 100*2000+7;
ll A[DIM],dp[DIM];
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n;
    cin>>n;
    ll gcd = 0;
    for(ll i = 1;i<=n;++i){
        cin>>A[i];
        if (gcd==0)
            gcd = A[i];
        gcd = __gcd(A[i],gcd);
    }
    ll sum = 0;
    for(ll i = 1;i<=n;++i){
        A[i]/=gcd;
        sum+=A[i];
    }
    dp[0] = 1;
    for(ll i = 1;i<=n;++i){
        for(ll w = DIM-1;w>=A[i];--w) {
            dp[w] = max(dp[w], dp[w - A[i]]);
        }
    }
    if (sum%2 || dp[sum/2]==0){
        cout<<"0\n";
        return 0;
    }
    for(ll i = 1;i<=n;++i){
        if (A[i]%2){
            cout<<"1\n"<<i<<endl;
            return 0;
        }
    }


    return 0;
}