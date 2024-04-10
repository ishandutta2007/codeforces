#pragma GCC Optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
const int N = 2e5+7;
const int MOD = 998244353;
void norm(ll &x){
    if (abs(x)>=MOD*2){
        x%=MOD;
        if (x<0)
            x+=MOD;
    }
    else{
        if (x<0)
            x+=MOD;
        if (x>=MOD)
            x-=MOD;
    }
}
ll Y[N],X[N],S[N],dp[N],pref[N];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int n;
    cin>>n;
    for(int i = 1;i<=n;++i){
        cin>>X[i]>>Y[i]>>S[i];
    }
    for(int i = 1;i<=n;++i){
        pref[i] = pref[i-1];
        int pos = lower_bound(X+1,X+1+n,Y[i])-X;
        dp[i] = pref[i]-pref[pos-1]+X[i]-Y[i];
        pref[i]+=dp[i];
        norm(dp[i]);
        norm(pref[i]);
    }
    ll res = 0;
    for(int i = 1;i<=n;++i){
        if (S[i]==1)
            res+=dp[i];
        norm(res);
    }
    res = res+X[n]+1;
    norm(res);
    cout<<res<<endl;

    return 0;
}