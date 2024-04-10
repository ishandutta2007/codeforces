#include<cstdio>
#include<cstdlib>
#include<map>
#include<vector>
#define MAX   100100
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
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
};
int a[MAX];
int n,x,y;
int res[MAX];
map<int,int> mp;
vector<int> gr[MAX];
DSU dsu;
void init(void) {
    scanf("%d%d%d",&n,&x,&y);
    FOR(i,1,n) scanf("%d",&a[i]);
    FOR(i,1,n) mp[a[i]]=i;
    dsu=DSU(n);
}
bool ok(const vector<int> &v,int x) {
    if (v.empty()) return (true);
    FORE(it,v) {
        if (mp.find(x-a[*it])==mp.end()) return (false);
        if (dsu.find(*it)!=dsu.find(mp[x-a[*it]])) return (false);
    }
    return (true);
}
void process(void) {
    FOR(i,1,n) {
        if (mp.find(x-a[i])!=mp.end()) dsu.join(i,mp[x-a[i]]);
        if (mp.find(y-a[i])!=mp.end()) dsu.join(i,mp[y-a[i]]);
    }
    FOR(i,1,n) gr[dsu.find(i)].push_back(i);
    FOR(i,1,n) if (!gr[i].empty()) {
        if (ok(gr[i],x)) {
            FORE(it,gr[i]) res[*it]=0;
        }
        else if (ok(gr[i],y)) {
            FORE(it,gr[i]) res[*it]=1;
        }
        else {
            printf("NO\n");
            return;
        }
    }
    printf("YES\n");
    FOR(i,1,n) printf("%d ",res[i]);
}
int main(void) {
    init();
    process();
    return 0;
}