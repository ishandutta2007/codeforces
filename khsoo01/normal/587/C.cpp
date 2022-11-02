#include<bits/stdc++.h>
#define ll long long
using namespace std;
vector<ll>cg[100005],ppl[100005];
ll n,m,q,a,b,c,tt,tc,tmp[35],par[100005],sps[25][100005],dep[100005];
ll mel[25][100001][11],mc[25][100001],cur[25],cs;

inline ll min(ll A,ll B){return A<B?A:B;}

void dfs(ll idx,ll prev) {
    sps[0][idx]=prev;
    dep[idx]=(prev==-1?0:dep[prev]+1);
    for(ll i=0;i<cg[idx].size();i++) {
        if(prev!=cg[idx][i]) {
            dfs(cg[idx][i],idx);
        }
    }
}

void Find(ll A,ll B) {
    ll dd,i,j;
    if(dep[A]>dep[B]) {dd=A;A=B;B=dd;}
    dd=dep[B]-dep[A];
    for(i=17;i>=0;i--) {
        if((1<<i)<=dd) {
            dd-=(1<<i);
            for(j=0;j<mc[i][B];j++) {
                cur[cs++]=mel[i][B][j];
            }
            sort(cur,cur+cs);
            cs=min(10,cs);
            B=sps[i][B];
        }
    }
    if(A==B) goto finale;
    for(i=17;i>=0;i--) {
        if(dep[A]>=(1<<i) && sps[i][A]!=sps[i][B]) {
            for(j=0;j<mc[i][A];j++) {
                cur[cs++]=mel[i][A][j];
            }
            sort(cur,cur+cs);
            cs=min(10,cs);
            for(j=0;j<mc[i][B];j++) {
                cur[cs++]=mel[i][B][j];
            }
            sort(cur,cur+cs);
            cs=min(10,cs);
            A=sps[i][A];
            B=sps[i][B];
        }
    }
    for(i=0;i<mc[0][A];i++) {
        cur[cs++]=mel[0][A][i];
    }
    sort(cur,cur+cs);
    cs=min(10,cs);
    for(i=0;i<mc[0][B];i++) {
        cur[cs++]=mel[0][B][i];
    }
    sort(cur,cur+cs);
    cs=min(10,cs);
    A=sps[0][A];
    finale:
    tt=min(ppl[A].size(),10);
    for(i=0;i<tt;i++) {
        cur[cs++]=ppl[A][i];
    }
    sort(cur,cur+cs);
    cs=min(10,cs);
    return;
}

int main() {
    ll i,j,k;
    scanf("%I64d%I64d%I64d",&n,&m,&q);
    for(i=1;i<n;i++) {
        scanf("%I64d%I64d",&a,&b);
        cg[a].push_back(b);
        cg[b].push_back(a);
    }
    for(i=1;i<=m;i++) {
        scanf("%I64d",&a);
        ppl[a].push_back(i);
    }
    dfs(1,-1);
    for(j=1;j<18;j++) {
        for(i=1;i<=n;i++) {
            sps[j][i]=sps[j-1][sps[j-1][i]];
        }
    }
    for(i=1;i<=n;i++) {
        sort(ppl[i].begin(),ppl[i].end());
        tt=min(ppl[i].size(),10);
        for(j=0;j<tt;j++) {
            mel[0][i][j]=ppl[i][j];
        }
        mc[0][i]=tt;
    }
    for(j=1;j<18;j++) {
        for(i=1;i<=n;i++) {
            tt=min(10,mc[j-1][i]);
            for(k=0;k<tt;k++) {
                tmp[tc++]=mel[j-1][i][k];
            }
            tt=min(10,mc[j-1][sps[j-1][i]]);
            for(k=0;k<tt;k++) {
                tmp[tc++]=mel[j-1][sps[j-1][i]][k];
            }
            sort(tmp,tmp+tc);
            mc[j][i]=min(10,tc);
            for(k=0;k<mc[j][i];k++) {
                mel[j][i][k]=tmp[k];
            }
            tc=0;
        }
    }
    while(q--) {
        scanf("%I64d%I64d%I64d",&a,&b,&c);
        Find(a,b);
        tt=min(cs,c);
        printf("%I64d ",tt);
        for(i=0;i<tt;i++) {
            printf("%I64d ",cur[i]);
        }
        cs=0;
        puts("");
    }
}