#include <bits/stdc++.h>

using namespace std;
typedef int ll;
#define endl '\n'
const ll DIM = 1E5+7;
const ll SZ = 1000;
const ll SQRT = DIM/SZ+100;
ll A[DIM],ans[DIM],dp[DIM],last[DIM],near[DIM],vis[DIM];
struct node{
    ll l,r,pos;
};
vector<node> Q[SQRT];
vector<node> qq[DIM];
bool mc(node &a,node &b){
    return a.r<b.r;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<ll> simp;
    for(ll i = 2;i<DIM;++i){
        if (vis[i])continue;
        simp.push_back(i);
        for(long long j = (long long)(i)*i;j<DIM;j+=i){
            vis[j] = 1;
        }
    }
    //cout<<simp.size()<<endl;
    ll n,q;
    cin>>n>>q;
    for(ll i = 1;i<=n;++i){
        cin>>A[i];
    }
    map<ll,ll> M;
    for(ll i = 1;i<=n;++i){
        ll x = A[i];
        for(ll to:simp){
            if ((long long)(x)<(long long)(to)*to)break;
            if (x%to)continue;

            if (M.count(to)==0)
                M[to] = 0;
            near[i] = max(near[i],M[to]);
            M[to] = i;
            while(x%to==0)
                x/=to;
        }
        if (x!=1){
            if (M.count(x)==0)
                M[x] = 0;
            near[i] = max(near[i],M[x]);
            M[x] = i;
        }
    }

    for(ll i = 1;i<=q;++i){
        ll l,r;
        cin>>l>>r;
        Q[(l-1)/SZ].push_back({l,r,i});
    }
    for(ll bl = 0;bl*SZ+1<=n;++bl){
        //cout<<Q[bl].size()<<endl;
        sort(Q[bl].begin(),Q[bl].end(),mc);
        ll ptr = 0;
        for(ll r = SZ*bl+1;r<=min(n,SZ*(bl+1));++r){
            last[r] = r;
            for(ll st = SZ*bl+1;st<=r;++st){
                if (near[r]>=last[st]){
                    dp[st]++;
                    last[st] = r;
                }
            }
            while(ptr<Q[bl].size() && Q[bl][ptr].r==r){
                ans[Q[bl][ptr].pos]+=dp[Q[bl][ptr].l];
                ++ptr;
            }
        }
        for(ll i = ptr;i<Q[bl].size();++i){
            qq[Q[bl][i].l].push_back(Q[bl][i]);
        }
        vector<pair<ll,ll> > V;
        for(ll st = SZ*bl+1;st<=SZ*(bl+1);++st){
            V.push_back({last[st],st});
        }
        sort(V.begin(),V.end(),greater<pair<ll,ll> >());
        for(ll i = SZ*(bl+1)+1;i<=n;++i){
            while(!V.empty() && V.back().first<=near[i]){
                for(auto to:qq[V.back().second]){
                    if (to.r<i){
                        ans[to.pos]+=dp[to.l];
                        continue;
                    }
                    Q[(i-1)/SZ].push_back({i,to.r,to.pos});
                    ans[to.pos]+=dp[to.l]+1;
                }
                V.pop_back();
            }
        }
    }
    for(ll i = 1;i<=q;++i)
        cout<<ans[i]+1<<endl;
    return 0;
}