#pragma GCC Optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
#define all(var) var.begin(),var.end()
#define mp make_pair
#define gi(x) int(x-'a'+1)
const int N = 2e5+7;
int dp[N];
ll cnt[N];
const ll MOD = 1e9+123;
const int base = 31;
#define hash szfesf
struct hash{
    unsigned long long h1;
    long long h2;
    const bool operator == (hash cmp){
        return cmp.h1==h1 && cmp.h2==h2;
    }
} H[N],po[N];
hash get(int l,int r){
    if (l==0)
        return H[r];
    hash L = {H[l-1].h1*po[r-l+1].h1,H[l-1].h2*po[r-l+1].h2%MOD};
    return {H[r].h1-L.h1,(H[r].h2-L.h2+MOD)%MOD};
}
void solve(){
    string L,R;
    cin>>L>>R;
    int l1 = L.size(),l2 = R.size();
    string S = R + "#";
    for(int i = 1;i<L.size();++i)
        S+=L[i];
    int len = S.size()-1;
    H[0] = {gi(S[0]),gi(S[0])};
    for(int i = 1;i<=len;++i){
        H[i].h1 = H[i-1].h1*base+gi(S[i]);
        H[i].h2 = (H[i-1].h2*base+gi(S[i]))%MOD;
    }
    for(int i = l2+1;i<=len;++i){
        int l = -1,r = len-i;
        while(l!=r){
            int mid = (l+r+1)>>1;
            if (get(0,mid)==get(i,i+mid))
                l = mid;
            else r = mid-1;
        }
        cnt[l+1]++;
    }
    dp[0] = 0;
    for(int i = 1;i<=len;++i){
        dp[i] = dp[i-1];
        while(dp[i]>0 && S[i]!=S[dp[i]])
            dp[i] = dp[dp[i]-1];
        if (S[dp[i]]==S[i])
            ++dp[i];
    }
    for(int i = l2;i>=1;--i)
        cnt[i-1]+=cnt[i];
    ll res = ll(l1)*l2;
    for(int i = 1;i<l2;++i){
        if (dp[i])
            res-=cnt[i-dp[i]+1];
    }

    cout<<res<<endl;
}
int main(){
    po[0] = {1,1};
    for(int i = 1;i<N;++i)
        po[i].h1 = po[i-1].h1*base,po[i].h2 = po[i-1].h2*base%MOD;
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    //cin>>t;

    while(t--)
        solve();
}