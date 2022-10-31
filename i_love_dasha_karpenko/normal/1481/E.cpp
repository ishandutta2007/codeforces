//#pragma GCC optimize ("O3")
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
#define endl '\n'
#define x1 dfgfg
#define y1 dfgdfg
const ll DIM = 5E5+7;
const ll INF = 1E18;
ll A[DIM],beg[DIM],cnt[DIM],num[DIM],dp[DIM];

void solve(){
    ll n;
    cin>>n;
    ll base = n;
    for(ll i = 1;i<=n;++i) {
        cin >> A[i];
        ++cnt[A[i]];
        ++num[A[i]];
    }

    reverse(A+1,A+1+n);

    for(ll i = 1;i<=n;++i){
        dp[i] = dp[i-1]+1;
        --cnt[A[i]];
        if (beg[A[i]]==0)beg[A[i]] = i;
        if (cnt[A[i]]==0){
            dp[i] = min(dp[i],dp[beg[A[i]]-1]+(i-beg[A[i]]+1)-num[A[i]]);
        }
        else{
            dp[i] = min(dp[i],i-(num[A[i]]-cnt[A[i]]));
        }
    }
    ll res = dp[n];

    vector<ll> V;
    ll ptr = 1;
    while(ptr<n && A[ptr+1]==A[1])++ptr;
    ll sum = num[A[1]]-ptr;
    for(ll i = 1;i<=n;++i) {
        dp[i] = 0;
        cnt[i] = num[i] = beg[i] = 0;
        if (A[i]!=A[1])V.push_back(A[i]);
    }
    n = V.size();
    for(ll i = 1;i<=n;++i){
        A[i] = V[i-1];
        ++cnt[A[i]];
        ++num[A[i]];

    }

    for(ll i = 1;i<=n;++i){
        dp[i] = dp[i-1]+1;
        --cnt[A[i]];
        if (beg[A[i]]==0)beg[A[i]] = i;
        if (cnt[A[i]]==0){
            dp[i] = min(dp[i],dp[beg[A[i]]-1]+(i-beg[A[i]]+1)-num[A[i]]);
        }

    }
    res = min(res,dp[n]+sum);
    for(ll i = 1;i<=base;++i){
        cnt[i] = num[i] = dp[i] = 0;
    }
    cout<<res<<endl;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t;
    t = 1;
    while(t--)
        solve();

    return 0;
}