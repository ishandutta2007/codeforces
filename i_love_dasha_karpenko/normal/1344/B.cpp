#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef int ll;
typedef double ld;
typedef pair<ll,ll> pp;
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> super_set;

#define x1 dfds
#define y1 dsfdsfe
#define pb push_back
#define forn(i,n) for(ll i = 1;i<=n;++i)
#define fi first
#define sc second
#define endl '\n'
#define po(x) (1ll<<x)
const ll DIM = 1E3+7;
const ll INF = 1E18;

ll n,m,A[DIM][DIM],ro[2][DIM][DIM],col[2][DIM][DIM],S[DIM][DIM];
ll mro[2][DIM][DIM],mcol[2][DIM][DIM],vis[DIM][DIM];
pp P[DIM][DIM],H[DIM][DIM],HP[DIM][DIM];
pp F(pp x){
    if (P[x.fi][x.sc]==x)return x;
    return P[x.fi][x.sc] = F(P[x.fi][x.sc]);
}
pp HF(pp x){
    if (HP[x.fi][x.sc]==x)return x;
    return HP[x.fi][x.sc] = HF(HP[x.fi][x.sc]);
}
void Hunite(pp a,pp b){
    a = F(a);
    b = F(b);
    if (rand()%2)swap(a,b);
    HP[a.fi][a.sc] = b;
}
ll res = 0;
pp cur;
ll vv = 0;
void unite(pp a,pp b){
    a = F(a);
    b = F(b);
    if (rand()%2)swap(a,b);
    P[a.fi][a.sc] = b;
    H[b.fi][b.sc] = cur;
}
ll CH(pp a,pp b){
    a = HF(a);
    b = HF(b);
    return a==b;
}
void dfs(pp v,ll fl){

    if (CH(H[F(v).fi][F(v).sc],v) && !CH(v,cur)){
        res-=vis[v.fi][v.sc];
        unite(v,cur);

    }
    if (vis[v.fi][v.sc]==1)return;
    if (fl==1)Hunite(v,cur);
    vv++;
    vis[v.fi][v.sc] = 1;
    if (mro[0][v.fi][v.sc]){
        if (mro[1][v.fi][v.sc-1])
        dfs({v.fi,v.sc-1},fl);
        else dfs({v.fi,v.sc-1},0);
    }
    if (mro[1][v.fi][v.sc]){
        if (mro[0][v.fi][v.sc+1])
        dfs({v.fi,v.sc+1},fl);
        else
        dfs({v.fi,v.sc+1},0);
    }
    if (mcol[0][v.fi][v.sc]){
        if (mcol[1][v.fi-1][v.sc])
        dfs({v.fi-1,v.sc},fl);
        else dfs({v.fi-1,v.sc},0);
    }
    if (mcol[1][v.fi][v.sc])
    {
        if (mcol[0][v.fi+1][v.sc])
        dfs({v.fi+1,v.sc},fl);
        else dfs({v.fi+1,v.sc},0);
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    forn(i,n){
        forn(j,m){
            char ch;
            cin>>ch;
            if (ch=='#')A[i][j] = 1;
        }
    }
    forn(i,n){
        forn(j,m){
            ro[0][i][j] = ro[0][i][j-1];
            if (A[i][j]==0 && A[i][j-1]==1)ro[0][i][j] = 1;
        }
        for(ll j = m;j>=1;--j){
            ro[1][i][j] = ro[1][i][j+1];
            if (A[i][j]==0 && A[i][j+1]==1)ro[1][i][j] = 1;
        }
    }
    forn(j,m){
        forn(i,n){
            col[0][i][j] = col[0][i-1][j];
            if (A[i][j]==0 && A[i-1][j]==1)col[0][i][j] = 1;
        }
        for(ll i = n;i>=1;--i){
            col[1][i][j] = col[1][i+1][j];
            if (A[i][j]==0 && A[i+1][j]==1)col[1][i][j] = 1;
        }
    }
    forn(i,n){
        forn(j,m){
            if (ro[0][i][j]==0 && ro[1][i][j]==0 && col[0][i][j]==0 && col[1][i][j]==0)S[i][j] = 1;
        }
    }
    //////////////////
    forn(i,n){
        forn(j,m){
            mro[0][i][j] = mro[0][i][j-1];
            if (S[i][j-1]==1)mro[0][i][j] = 1;
        }
        for(ll j = m;j>=1;--j){
            mro[1][i][j] = mro[1][i][j+1];
            if (S[i][j+1]==1)mro[1][i][j] = 1;
        }
    }
    forn(j,m){
        forn(i,n){
            mcol[0][i][j] = mcol[0][i-1][j];
            if (S[i-1][j]==1 )mcol[0][i][j] = 1;
        }
        for(ll i = n;i>=1;--i){
            mcol[1][i][j] = mcol[1][i+1][j];
            if (S[i+1][j]==1)mcol[1][i][j] = 1;
        }
    }
    forn(i,n){
        forn(j,m){
            P[i][j] = {i,j};
            H[i][j] = {i,j};
            HP[i][j] = {i,j};
        }
    }
    ll cnt = 0;
    forn(i,n){
        forn(j,m){
            if (A[i][j]==1)cnt++;
            if (A[i][j]==0)continue;
            if (vis[i][j]==1)continue;
            cur = {i,j};
            res++;
            dfs({i,j},1);
        }
    }
    ll flag = 0;
    forn(i,n){
        ll ff = 0;
        forn(j,m){
            ff = max(ff,S[i][j]);
        }
        if (ff==0)flag = 1;
    }
    forn(j,m){
        ll ff = 0;
        forn(i,n){
            ff = max(ff,S[i][j]);
        }
        if (ff==0)flag = 1;
    }

    if (vv!=cnt || flag)cout<<"-1\n";
    else
    cout<<res<<endl;
    return 0;
}