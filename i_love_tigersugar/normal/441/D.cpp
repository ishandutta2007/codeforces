#include<bits/stdc++.h>
#define MAX   3333
#define FOR(i,a,b) for (int i=(a);i<=(b);i=i+1)
#define REP(i,n) for (int i=0;i<(n);i=i+1)
using namespace std;
class DSU {
    private:
    vector<int> up;
    public:
    DSU(){}
    DSU(int n) {
        up.assign(n+7,-1);
    }
    int find(int x) {
        if (up[x]<0) return (x);
        up[x]=find(up[x]);
        return (up[x]);
    }
    void join(int a,int b) {
        int x=find(a);
        int y=find(b);
        if (x==y) return;
        up[y]=x;
    }
    bool same(int a,int b) {
        return (find(a)==find(b));
    }
};
DSU dsu;
int p[MAX];
bool vst[MAX];
int cycid[MAX];
vector<vector<int> > cyc;
int n,m;
void init(void) {
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d",&p[i]);
    scanf("%d",&m);
    m=n-m;
    dsu=DSU(n);
}
void getcyc(void) {
    FOR(i,1,n) if (!vst[i]) {
        int j=i;
        cyc.push_back(vector<int>());
        while (!vst[p[j]]) {
            vst[p[j]]=true;
            dsu.join(j,p[j]);
            cyc.back().push_back(p[j]);
            cycid[p[j]]=cyc.size()-1;
            j=p[j];
        }
    }
}
void lesscyc(void) {
    int t=cyc.size()-m;
    FOR(i,2,n) if (t>0 && !dsu.same(1,i)) {
        t--;
        printf("%d %d ",1,i);
        dsu.join(1,i);
    }
}
void split(int id,int i,int j) {
    int cur=i;
    int cid=cyc.size();
    cyc[id].clear();
    cyc.push_back(vector<int>());
    do {
        cur=p[cur];
        cyc[cid].push_back(cur);
        cycid[cur]=cid;
        if (cur==j) cid=id;
    }
    while (cur!=i);
    swap(p[i],p[j]);
}
void morecyc(void) {
    int t=m-cyc.size();
    FOR(i,1,n) FOR(j,i+1,n) if (cycid[i]==cycid[j] && t>0) {
        printf("%d %d ",i,j);
        split(cycid[i],i,j);
        t--;
    }
}
void process(void) {
    printf("%d\n",max(m-(int)cyc.size(),(int)cyc.size()-m));
    if (m>cyc.size()) morecyc();
    if (m<cyc.size()) lesscyc();
}
int main(void) {
    init();
    getcyc();
    process();
    return 0;
}