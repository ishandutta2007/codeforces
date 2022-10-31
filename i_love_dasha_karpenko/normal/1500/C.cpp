//#pragma GCC optimize ("O3")
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
#define endl '\n'
#define x1 dfgfg
#define y1 dfgdfg
const ll DIM = 1507;
ll A[DIM][DIM],B[DIM][DIM],cut[DIM],vis[DIM],pos[DIM],in_pos[DIM],cnt[DIM];
vector<ll> need[DIM];
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n,m;
    cin>>n>>m;
    for(ll i = 1;i<=n;++i) {
        for(ll j = 1;j<=m;++j)
            cin>>A[i][j];
    }
    for(ll i = 1;i<=n;++i){
        for(ll j = 1;j<=m;++j)
            cin>>B[i][j];
    }
    queue<ll> Q;
    cut[1] = 1;
    for(ll j = 1;j<=m;++j){
        ll flag = 0;
        for(ll i = 1;i<=n;++i){
            if (B[i][j]<B[i-1][j]){
                flag = 1;
                need[i].push_back(j);
                ++cnt[j];
            }
        }
        if (!flag)vis[j] = 1,Q.push(j);
    }
    vector<ll> ans;
    while(!Q.empty()){
        ll t = Q.front();
        Q.pop();
        ans.push_back(t);
        ll fl = 0;
        for(ll i = 1;i<=n;++i){
            if (B[i][t]!=B[i-1][t] && cut[i]==0){
                cut[i] = 1,fl = 1;
                for(ll to:need[i]){
                    cnt[to]--;
                    if (vis[to]==0 && cnt[to]==0) {
                        Q.push(to);
                        vis[to] = 1;
                    }
                }
            }
        }

    }
    reverse(ans.begin(),ans.end());
    for(ll i = 1;i<=n;++i)pos[i] = in_pos[i] = i;
    for(ll to:ans){
        vector<pair<pair<ll,ll>,ll> > V;
        for(ll i = 1;i<=n;++i){
            V.push_back({{A[in_pos[i]][to],i},in_pos[i]});

        }
        sort(V.begin(),V.end());
        ll ptr = 1;
        for(auto to:V){
            in_pos[ptr] = to.second;
            pos[to.second] = ptr;
            ++ptr;
        }
    }
    for(ll i = 1;i<=n;++i){
        for(ll j = 1;j<=m;++j){
            if (A[in_pos[i]][j]!=B[i][j]){
                cout<<"-1\n";
                return 0;
            }
        }
    }
    cout<<ans.size()<<endl;
    for(ll to:ans)cout<<to<<' ';
    cout<<endl;
    return 0;
}