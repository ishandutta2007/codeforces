#pragma GCC Optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long
#define endl '\n'
const ll INF = 1e10+7;
const int N = 2e5+7;
ll X[N],A[N];
vector<ll> L[N],R[N],dp[N];
void solve(){
    int n,m;
    cin>>n>>m;
    vector<pair<ll,int> > events;

    for(int i = 1;i<=n;++i){
        cin>>X[i];
        events.push_back({X[i],0});
    }
    sort(X+1,X+1+n);
    for(int i = 1;i<=m;++i){
        int l,r;
        cin>>l>>r;
        int pos = lower_bound(X+1,X+1+n,l)-X;
        if (pos>=1 && pos<=n && X[pos]<=r && X[pos]>=l)
            continue;
        events.push_back({l,-i});
        A[i] = r;
    }
    sort(events.begin(),events.end());
    int ptr = 0;
    vector<ll> lb,rb;
    vector<pair<int,int> > segms;
    for(pair<ll,int> to:events){
        if (to.second==0){
            ++ptr;
            for(pair<int,int> sg:segms){
                lb.push_back(sg.first);
                rb.push_back(A[sg.second]);
            }
            R[ptr-1] = lb;
            L[ptr] = rb;
            lb.clear();
            rb.clear();
            segms.clear();
        }
        else {
            segms.push_back({to.first,-to.second});
        }

    }
    for(pair<int,int> sg:segms){
        lb.push_back(sg.first);
        rb.push_back(A[sg.second]);
    }
    R[ptr] = lb;
    for(int i = 1;i<=n;++i){
        dp[i].resize(R[i].size()+1,0);
    }
    dp[0].resize(R[0].size()+1,INF);
    dp[0][0] = 0;
    for(int cur = 1;cur<=n;++cur){
        ll mi1 = INF,mi2 = INF;
        int lsz = L[cur].size(),rsz = R[cur].size();
        int r = X[cur];
        for(int i = lsz-1;i>=0;--i){
            r = min(r,L[cur][i]);
            mi1 = min(mi1,dp[cur-1][i]+X[cur]-r);
            mi2 = min(mi2,dp[cur-1][i]+(X[cur]-r)*2);
        }
        mi1 = min(mi1,dp[cur-1][lsz]);
        mi2 = min(mi2,dp[cur-1][lsz]);
        dp[cur][0] = mi1;
        for(int i = 1;i<=rsz;++i){
            dp[cur][i] = min(mi1+(R[cur][i-1]-X[cur])*2,mi2+(R[cur][i-1]-X[cur]));
        }
    }
    cout<<dp[n][R[n].size()]<<endl;
    for(int i = 0;i<=n;++i){
        dp[i].clear();
        L[i].clear();
        R[i].clear();
    }

}
signed main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t = 1;
    cin>>t;
    while(t--)
        solve();
    return 0;
}