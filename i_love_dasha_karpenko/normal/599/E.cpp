//#pragma GCC Optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
const int N = 13+1;
const int MASK_SZ = 1<<N;
ll dp[MASK_SZ][N][N],all[MASK_SZ],tot[MASK_SZ][N],SS[MASK_SZ];
ll edg[N],po[N],cnt[MASK_SZ];
struct node{
    int a,b,c;
};
vector<node> Q;
int n,m,q;
 
ll clk[N],fact[N],F[MASK_SZ][2];
const int CH_SZ = 1594323+100;
ll VAL[CH_SZ];
int check(int mask1,int mask2,int root){
    mask1-=mask1&po[root];
    mask2-=mask2&po[root];
    return (VAL[F[mask1][1]+F[mask2][0]]&po[root])!=0;
}
vector<pair<int,int> > E;
void calc(int mask1,int mask2){
 
    int flag = 0;
    ll s1 = F[mask1][0]+F[mask2][1],s2 = F[mask1][1]+F[mask2][0];
    VAL[s1] = MASK_SZ-1;
    if (mask1==1 && mask2==2){
        int h;
        ++h;
    }
    for(auto [a,b,c]:Q){
        if ((mask1&po[a]) && (mask2&po[b]) )
            VAL[s1]&=po[c];
        if ((mask1&po[b]) && (mask2&po[a]))
            VAL[s1]&=po[c];
        if ((mask1&po[a]) && b!=c){
            VAL[s1]&=(MASK_SZ-1-po[b]);
        }
        if ((mask1&po[b]) && a!=c){
            VAL[s1]&=(MASK_SZ-1-po[a]);
        }
        if ((mask2&po[a]) && b!=c){
            VAL[s1]&=(MASK_SZ-1-po[b]);
        }
        if ((mask2&po[b]) && a!=c){
            VAL[s1]&=(MASK_SZ-1-po[a]);
        }
 
    }
    for(auto [a,b]:E){
        if ((mask1&po[a]) && (mask2&po[b]))
            flag = 1;
        if ((mask1&po[b]) && (mask2&po[a]))
            flag = 1;
    }
    if (flag)
        VAL[s1] = 0;
    VAL[s2] = VAL[s1];
}
 
signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    po[0] = 1;
    fact[0] = 1;
    for(int i = 1;i<N;++i)
        po[i] = po[i-1]*2,fact[i] = fact[i-1]*i;
 
    cin>>n>>m>>q;
    for(int i = 1;i<=m;++i){
        int u,v;
        cin>>u>>v;
        --u;
        --v;
        E.push_back({u,v});
        edg[u]|=po[v];
        edg[v]|=po[u];
    }
    Q.resize(q);
    for(int i = 0;i<q;++i){
        cin>>Q[i].a>>Q[i].b>>Q[i].c;
        --Q[i].a;
        --Q[i].b;
        --Q[i].c;
        if (Q[i].a==Q[i].b && Q[i].c!=Q[i].a){
            cout<<"0\n";
            exit(0);
        }
    }
    int masksz = 1<<n;
    for(int mask = 0;mask<masksz;++mask)
        cnt[mask] = __builtin_popcount(mask);
    for(int mask = 0;mask<masksz;++mask){
        for(int bit = 0;bit<n;++bit){
            F[mask][0]*=3;
            F[mask][1]*=3;
            if (mask&po[bit]){
                F[mask][0]++;
                F[mask][1]+=2;
            }
        }
    }
    for(int mask = 1;mask<masksz;++mask){
        for(int sub = mask;sub>0;sub=mask&(sub-1)){
            calc(sub,mask^sub);
        }
    }
    all[0] = 1;
    for(int mask = 1;mask<masksz;++mask){
        if (cnt[mask]==1){
            all[mask] = 1;
            for(int root = 0;root<n;++root){
                if (po[root] == mask){
                    tot[mask][root] = 1;
                    dp[mask][root][0] = 1;
                    break;
                }
            }
            continue;
        }
        if (mask==14){
            int h;
            ++h;
        }
        for(int root = 0;root<n;++root){
            if (!(mask&po[root]))
                continue;
            {
                for (int msk = mask; msk > 0; msk = (msk - 1) & mask)
                    SS[msk] = 0;
                for (int subroot = 0; subroot < n; ++subroot) {
                    if ((edg[root] & po[subroot]) && (po[subroot] & mask)) {
                        int mxsub = mask ^po[root] ^(edg[root] & mask) ^po[subroot];
                        for (int sub = mxsub; sub > 0; sub = mxsub & (sub - 1)) {
                            SS[sub] += tot[sub][subroot] * check(mask ^ sub, sub, root);
                        }
                    }
                }
            }
            vector<int> V;
            for (int sub = mask; sub > 0; sub = mask & (sub - 1)) {
                if (SS[sub])
                    V.push_back(sub);
            }
            for(int cld = 1;cld<=cnt[mask]-1;++cld) {
 
                int mxsub = mask ^po[root] ;
                for(int sub:V) {
                    dp[mask][root][cld] += SS[sub] * dp[mask ^ sub][root][cld-1];
                }
                mxsub = mask ^po[root] ^(mask & edg[root]);
                for (int sub = mxsub; sub > 0; sub = mxsub & (sub - 1)) {
                    dp[mask][root][cld] += all[sub] * dp[mask ^ sub][root][cld-1] * check(mask^sub, sub, root);
                }
                tot[mask][root] += dp[mask][root][cld]/fact[cld];
            }
            all[mask]+=tot[mask][root];
        }
    }
    cout<<tot[masksz-1][0]<<endl;
    return 0;
}