#include<cstdio>
#include<cstring>
#include<queue>
#include<vector>
#define MAX   5050
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
#define fi   first
#define se   second
using namespace std;
const int INF=(int)1e9+7;
typedef pair<int,int> ii;
vector<ii> fg[MAX],bg[MAX],g[MAX];
int n,m;
int res[MAX],d[MAX];
bool fd[MAX],bd[MAX];
inline int nextint(void) {
    int x;
    scanf("%d",&x);
    return (x);
}
void loadgraph(void) {
    n=nextint();
    m=nextint();
    REP(i,m) {
        int u=nextint();
        int v=nextint();
        fg[u].push_back(ii(v,i));
        bg[v].push_back(ii(u,i));
    }
}
void BFS(int s,vector<ii> g[],bool d[]) {
    queue<int> q;
    q.push(s);
    d[s]=true;
    while (!q.empty()) {
        int u=q.front();q.pop();
        FORE(it,g[u]) {
            int v=it->fi;
            if (!d[v]) {
                d[v]=true;
                q.push(v);
            }
        }
    }
}
void setupgraph(void) {
    BFS(1,fg,fd);
    BFS(n,bg,bd);
    FOR(i,1,n) if (fd[i] && bd[i]) FORE(it,fg[i]) {
        int j=it->fi;
        if (fd[j] && bd[j]) {
            g[i].push_back(ii(j,2));
            g[j].push_back(ii(i,-1));
        }
    }
}
bool FordBellman(void) {
    memset(d,0x3f,sizeof d);
    d[1]=0;
    REP(zz,n-1) FOR(u,1,n) FORE(it,g[u]) {
        int v=it->fi;
        if (d[v]>d[u]+it->se) d[v]=d[u]+it->se;
    }
    FOR(u,1,n) FORE(it,g[u]) {
        int v=it->fi;
        if (d[v]>d[u]+it->se) return (false);
    }
    return (true);
}
void process(void) {
    if (!FordBellman()) {
        printf("No");
        return;
    }
    FOR(u,1,n) FORE(it,fg[u]) {
        int v=it->fi;
        if (fd[u] && bd[u] && fd[v] && bd[v]) {
            if (d[u]<INF) res[it->se]=d[v]-d[u];
            else res[it->se]=2;
        }
        else res[it->se]=1;
    }
    printf("Yes\n");
    REP(i,m) printf("%d\n",res[i]);
}
int main(void) {
    loadgraph();
    setupgraph();
    process();
    return 0;
}