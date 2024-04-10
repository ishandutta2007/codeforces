//#pragma GCC optimize ("O3")
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
//#define endl '\n'
#define x1 dfgfg
#define y1 dfgdfg
const ll DIM = 5E3+7;
ll A[DIM],cnt[DIM];
void solve(){
    ll n;
    cin>>n;
    for(ll i = 1;i<=n;++i){
        cin>>A[i];
        cnt[i] = 0;
    }
    ll res = 0;

    for(ll i = 1;i<=n;++i){
        res+=max(0ll,A[i]-1-cnt[i]);
        cnt[i] = max(cnt[i],A[i]-1);
        cnt[i]-=max(0ll,A[i]+i-n);
        for(ll j = min(n,i+A[i]);j>i;--j){
            cnt[j]++;
            cnt[i]--;
        }
        cnt[i+1]+=cnt[i];
    }
    cout<<res<<endl;
    return;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t;
    cin>>t;
    while(t--)
        solve();

    return 0;
}