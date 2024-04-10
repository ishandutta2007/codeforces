#include<bits/stdc++.h>
#define MAX   100100
using namespace std;
typedef long long ll;
ll val[MAX];
ll bigsum[MAX];
ll bigadd[MAX];
bool isele[MAX];
vector<int> bigsub;
vector<int> common[MAX];
vector<int> subset[MAX];
int n,sz,m,q;
void init(void) {
    scanf("%d",&n);
    scanf("%d",&m);
    scanf("%d",&q);
    sz=0;
    int i,j,k,t;
    while (sz*sz<n) sz++;
    for (i=1;i<=n;i=i+1) scanf("%I64d",&val[i]);
    for (i=1;i<=m;i=i+1) {
        scanf("%d",&k);
        for (j=1;j<=k;j=j+1) {
            scanf("%d",&t);
            subset[i].push_back(t);
        }
    }
    for (i=1;i<=m;i=i+1)
        if (subset[i].size()>sz) {
            bigsub.push_back(i);
            bigsum[i]=0LL;
            memset(isele,false,sizeof isele);
            for (j=0;j<subset[i].size();j=j+1) {
                bigsum[i]+=val[subset[i][j]];
                isele[subset[i][j]]=true;
            }
            common[i].push_back(i);
            for (j=1;j<=m;j=j+1) {
                common[i].push_back(0);
                for (k=0;k<subset[j].size();k=k+1) common[i][j]+=isele[subset[j][k]];
            }
        }
}
void add(const int &id,const ll &del) {
    int i;
    for (i=0;i<bigsub.size();i=i+1)
        bigsum[bigsub[i]]+=del*common[bigsub[i]][id];
    if (subset[id].size()>sz) bigadd[id]+=del;
    else
        for (i=0;i<subset[id].size();i=i+1) val[subset[id][i]]+=del;
}
ll sum(const int &id) {
    if (subset[id].size()>sz) return (bigsum[id]);
    else {
        int i;
        ll res=0LL;
        for (i=0;i<subset[id].size();i=i+1) res+=val[subset[id][i]];
        for (i=0;i<bigsub.size();i=i+1) res+=bigadd[bigsub[i]]*common[bigsub[i]][id];
        return (res);
    }
}
void process(void) {
    int i,u;
    char type;
    ll del;
    for (i=1;i<=q;i=i+1) {
        scanf(" %c",&type);
        scanf("%d",&u);
        if (type=='+') {
            scanf("%I64d",&del);
            add(u,del);
        }
        else printf("%I64d\n",sum(u));
    }
}
int main(void) {
#ifndef ONLINE_JUDGE
    freopen("tmp.txt","r",stdin);
#endif
    init();
    process();
    return 0;
}