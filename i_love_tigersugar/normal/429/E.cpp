#include<algorithm>
#include<cstdio>
#include<vector>
#define MAX   100100
#define FOR(i,a,b) for (int i=(a);i<=(b);i=i+1)
#define REP(i,n) for (int i=0;i<(n);i=i+1)
#define fi   first
#define se   second
using namespace std;
typedef pair<int,int> ii;
inline int nextInt(void) {
    int x;
    scanf("%d",&x);
    return (x);
}
class EulerCycle {
    private:
    int n,m;
    vector<ii> edge;
    vector<vector<int> > g;
    vector<bool> used,col;
    vector<int> more;
    inline int getedge(vector<int> &v) {
        while (!v.empty()) {
            if (used[v.back()]) v.pop_back();
            else return (v.back());
        }
        return (-1);
    }
    inline int getvertex(void) {
        while (!more.empty()) {
            if (getedge(g[more.back()])<0) more.pop_back();
            else return (more.back());
        }
        return (-1);
    }
    void findway(int s) {
        int u=s;
        while (true) {
            int id=getedge(g[u]);
            used[id]=true;
            int v=edge[id].fi^edge[id].se^u;
            col[id]=v>u;
            u=v;
            if (u==s) return;
        }
    }
    void moreedge(void) {
        vector<int> odd;
        FOR(i,1,n) if (g[i].size()%2) odd.push_back(i);
        sort(odd.begin(),odd.end());
        while (!odd.empty()) {
            int u=odd.back();odd.pop_back();
            int v=odd.back();odd.pop_back();
            addedge(u,v);
        }
    }
    public:
    EulerCycle() {
        n=m=0;
    }
    EulerCycle(int n) {
        this->n=n;
        this->m=0;
        g.assign(n+7,vector<int>());
        FOR(i,1,n) more.push_back(i);
    }
    int addedge(int u,int v) {
        edge.push_back(ii(u,v));
        g[u].push_back(m);
        g[v].push_back(m);
        used.push_back(false);
        col.push_back(false);
        return (m++);
    }
    void eulercycle(void) {
        moreedge();
        while (true) {
            int s=getvertex();
            if (s<0) return;
            findway(s);
        }
    }
    bool color(int x) const {
        return (col[x]);
    }
};
ii a[MAX];
vector<int> v;
int n;
int id[MAX];
EulerCycle EC;
void init(void) {
    n=nextInt();
    FOR(i,1,n) {
        a[i].fi=nextInt();
        a[i].se=nextInt();
        v.push_back(a[i].fi);
        v.push_back(a[i].se+1);
    }
    sort(v.begin(),v.end());
    v.resize(unique(v.begin(),v.end())-v.begin());
}
void process(void) {
    EC=EulerCycle(v.size());
    FOR(i,1,n) {
        int x=lower_bound(v.begin(),v.end(),a[i].fi)-v.begin()+1;
        int y=lower_bound(v.begin(),v.end(),a[i].se+1)-v.begin()+1;
        id[i]=EC.addedge(x,y);
    }
    EC.eulercycle();
    FOR(i,1,n) printf("%d ",EC.color(id[i]));
}
int main(void) {
    init();
    process();
    return 0;
}