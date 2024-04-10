#pragma GCC Optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
const int N = 3e5+7;
const ll INF = 1e18;
int H[N],B[N];
ll T[N*4];
bool mod[N*4];
void push(int t){
    if (!mod[t])
        return;
    mod[t] = false;
    mod[t*2+1] = mod[t*2+2] = true;
    T[t*2+1] = T[t*2+2] = -INF;
}
void del(int t,int tl,int tr,int l,int r){
    if (tl>r || l>tr)
        return;
    if (l<=tl && tr<=r){
        mod[t] = true;
        T[t] = -INF;
        return;
    }
    push(t);
    int tm = (tl+tr)>>1;
    del(t*2+1,tl,tm,l,r);
    del(t*2+2,tm+1,tr,l,r);
    T[t] = max(T[t*2+1],T[t*2+2]);
}
void update(int t,int tl,int tr,int pos,ll val){
    if (tl>pos || tr<pos)
        return;
    if (tl==tr){
        T[t] = val;
        return;
    }
    push(t);
    int tm = (tl+tr)>>1;
    update(t*2+1,tl,tm,pos,val);
    update(t*2+2,tm+1,tr,pos,val);
    T[t] = max(T[t*2+1],T[t*2+2]);
}
ll mx_dp[N],dp[N];
void solve(){
    int n;
    cin>>n;
    for(int i = 1;i<=n;++i){
        cin>>H[i];
    }
    for(int i = 1;i<=n;++i){
        cin>>B[i];
    }
    del(0,1,n,1,n);
    stack<int> S;
    for(int i = 1;i<=n;++i){
        if (i!=1)
            mx_dp[i] = -INF;
        while(!S.empty() && H[S.top()]>H[i]){
            mx_dp[i] = max(mx_dp[i],mx_dp[S.top()]);
            S.pop();
        }
        if (S.empty())
            mx_dp[i] = max(mx_dp[i],0ll);
        else{
            mx_dp[i] = max(mx_dp[i],dp[S.top()]);
        }
        S.push(i);
        del(0,1,n,H[i],n);
        update(0,1,n,H[i],mx_dp[i]+B[i]);
        dp[i] = T[0];
        mx_dp[i] += max(0,B[i]);
    }
    cout<<T[0]<<endl;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t = 1;
    //cin>>t;
    while(t--)
        solve();
    return 0;
}