#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define endl '\n'
const int N = 2e5+7;
ll A[N];
void solve(){
    ll n,k;
    cin>>n>>k;
    for(int i = 1;i<=n;i+=1){
        cin>>A[i];
        A[i] += A[i-1];
    }
    ll len = min(n,k);
    ll res = 0;
    for(int i = len;i<=n;i+=1){
        res = max(res,A[i]-A[i-len]);
    }
    if (k==len) {
        res += len * (len - 1) / 2;
    }
    else{
        res += n*(k-1) - (n-1)*n/2;
    }
    cout<<res<<endl;
}
signed main()
{


    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}