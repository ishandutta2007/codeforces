//This code is based on hza's solution
#include<bits/stdc++.h>
#define MAX   4000400
#define FOR(i,a,b) for (int i=(a);i<=(b);i=i+1)
#define REP(i,n) for (int i=0;i<(n);i=i+1)
#define fi   first
#define se   second
using namespace std;
typedef long long ll;
typedef pair<ll,int> ii;
int n,k,nseg,ncan,cnt;
bool inq[MAX];
ll a[MAX],seg[MAX];
ii can[MAX],pivot;
int prev[MAX],next[MAX],del[MAX];
queue<int> q;
ll Labs(ll x) {
    if (x<0) return (-x); else return (x);
}
void init(void) {
    scanf("%d",&n);
    scanf("%d",&k);
    FOR(i,1,n) scanf("%I64d",&a[i]);
    nseg=0;
    FOR(i,2,n) if (a[i]!=a[i-1]) {
        nseg++;
        seg[nseg]=a[i]-a[i-1];
        if (nseg<2 && seg[nseg]<0) nseg--;
        if (nseg>1 && (seg[nseg]>0)==(seg[nseg-1]>0)) {
            nseg--;
            seg[nseg]+=seg[nseg+1];
        }
    }
    if (nseg>0 && seg[nseg]<0) nseg--;
    FOR(i,1,nseg) {
        prev[i]=i-1;
        next[i-1]=i;
    }
    prev[0]=nseg;
}
void addqueue(int u) {
    if (ii(Labs(seg[u]),u)<=pivot && !inq[u]) {
        q.push(u);
        inq[u]=true;
    }
}
void merge(int u) {
    int l=prev[u];
    int r=next[u];
    if (l>0 && Labs(seg[l])<=Labs(seg[u])) return;
    if (r>0 && Labs(seg[r])<Labs(seg[u])) return;
    if (del[u]==cnt) return;
    if (l>0) prev[u]=prev[l]; else prev[u]=0;
    if (r>0) next[u]=next[r]; else next[u]=0;
    next[prev[u]]=u;
    prev[next[u]]=u;
    del[l]=cnt;
    del[r]=cnt;
    seg[u]+=seg[l]+seg[r];
    if (l==0) {
        del[u]=cnt;
        next[0]=next[r];
        prev[next[r]]=0;
    }
    if (r==0) {
        del[u]=cnt;
        prev[0]=prev[l];
        next[prev[l]]=0;
    }
    if (prev[u]>0) addqueue(prev[u]);
    if (next[u]>0) addqueue(next[u]);
    addqueue(u);
}
void process(void) {
    while (true) {
        cnt++;
        ncan=0;
        for (int i=next[0];i>0;i=next[i]) {
            ncan++;
            can[ncan]=ii(Labs(seg[i]),i);
        }
        if (ncan<2*k) break;
        int mid=(ncan-2*k+1)/2;
        nth_element(can+1,can+mid,can+ncan+1);
        pivot=can[mid];
        while (!q.empty()) q.pop();
        for (int i=next[0];i>0;i=next[i]) addqueue(i);
        while (!q.empty()) {
            int u=q.front();q.pop();
            inq[u]=false;
            merge(u);
        }
    }
    ll ans=0LL;
    for (int i=next[0];i>0;i=next[i]) if (seg[i]>0) ans+=seg[i];
    printf("%I64d",ans);
}
int main(void) {
#ifndef ONLINE_JUDGE
    freopen("tmp.txt","r",stdin);
#endif
    init();
    process();
    return 0;
}