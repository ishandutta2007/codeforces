#include<bits/stdc++.h>
#define MAX   111
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
using namespace std;
const char imp[]="IMPOSSIBLE";
int f[MAX][MAX];
vector<int> leftNode[MAX],rightNode[MAX];
int n,m;
int leftChild[MAX],rightChild[MAX];
vector<int> res;
void init(void) {
    scanf("%d%d",&n,&m);
    char s[13];
    REP(love,m) {
        int u,v;
        scanf("%d%d%s",&u,&v,&s);
        if (s[0]=='L') leftNode[u].push_back(v);
        else rightNode[u].push_back(v);
    }
}
bool okLeave(int u) {
    return (leftNode[u].empty() && rightNode[u].empty());
}
bool okLeft(int u,int x) {
    if (!rightNode[u].empty()) return (false);
    FORE(it,leftNode[u]) if (!(u+1<=*it && *it<=x)) return (false);
    return (true);
}
bool okRight(int u,int x) {
    if (!leftNode[u].empty()) return (false);
    FORE(it,rightNode[u]) if (!(u+1<=*it && *it<=x)) return (false);
    return (true);
}
bool ok(int u,int v,int x) {
    FORE(it,leftNode[u]) if (!(u+1<=*it && *it<=v-1)) return (false);
    FORE(it,rightNode[u]) if (!(v<=*it && *it<=x)) return (false);
    return (true);
}
bool dp(int u,int x) {
    if (u>x) return (false);
    if (u==x) return (okLeave(u));
    if (f[u][x]>=0) return (f[u][x]);
    if (dp(u+1,x) && okLeft(u,x)) return (f[u][x]=true);
    if (dp(u+1,x) && okRight(u,x)) return (f[u][x]=true);
    FOR(v,u+2,x) if (dp(u+1,v-1) && dp(v,x) && ok(u,v,x)) return (f[u][x]=true);
    return (f[u][x]=false);
}
void trace(int u,int x) {
    //printf("Trace %d %d\n",u,x);
    assert(dp(u,x));
    if (u==x) {
        res.push_back(u);
        return;
    }
    if (dp(u+1,x) && okLeft(u,x)) {
        trace(u+1,x);
        res.push_back(u);
        return;
    }
    if (dp(u+1,x) && okRight(u,x)) {
        res.push_back(u);
        trace(u+1,x);
        return;
    }
    FOR(v,u+2,x) if (dp(u+1,v-1) && dp(v,x) && ok(u,v,x)) {
        trace(u+1,v-1);
        res.push_back(u);
        trace(v,x);
        return;
    }
    assert(false);
}
void process(void) {
    memset(f,-1,sizeof f);
    if (!dp(1,n)) {
        printf("%s\n",imp);
        return;
    }
    trace(1,n);
    FORE(it,res) printf("%d ",*it); printf("\n");
}
int main(void) {
    init();
    process();
    return 0;
}