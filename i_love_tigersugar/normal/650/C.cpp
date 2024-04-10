#include<bits/stdc++.h>
#define MAX   1000100
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define FORD(i,b,a) for (int i=(b),_a=(a);i>=_a;i=i-1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
#define ALL(v) (v).begin(),(v).end()
#define fi   first
#define se   second
#define MASK(i) (1LL<<(i))
#define BIT(x,i) (((x)>>(i))&1)
#define next   ___next
#define prev   ___prev
#define left   ___left
#define right   ___right
#define POS(x,y) ((x)*n+(y)+1)
using namespace std;
template<class X,class Y>
    void minimize(X &x,const Y &y) {
        if (x>y) x=y;
    }
template<class X,class Y>
    void maximize(X &x,const Y &y) {
        if (x<y) x=y;
    }
vector<vector<int> > board;
int m,n;
vector<pair<int,int> > adj[MAX];
vector<int> revAdj[MAX],comp[MAX];
int low[MAX],num[MAX],compID[MAX],cnt,nComp;
int f[MAX];
stack<int> st;
void loadGraph(void) {
    scanf("%d%d",&m,&n);
    board.assign(m+1,vector<int>(n+1,0));
    REP(i,m) REP(j,n) scanf("%d",&board[i][j]);
    REP(i,m) {
        vector<pair<int,int> > row;
        REP(j,n) row.push_back(make_pair(board[i][j],j));
        sort(ALL(row));
        REP(j,n-1) {
            int cur=POS(i,row[j].se);
            int next=POS(i,row[j+1].se);
            if (row[j].fi<row[j+1].fi) {
                adj[cur].push_back(make_pair(next,1));
            } else {
                adj[cur].push_back(make_pair(next,0));
                adj[next].push_back(make_pair(cur,0));
            }
        }
    }
    REP(j,n) {
        vector<pair<int,int> > col;
        REP(i,m) col.push_back(make_pair(board[i][j],i));
        sort(ALL(col));
        REP(i,m-1) {
            int cur=POS(col[i].se,j);
            int next=POS(col[i+1].se,j);
            if (col[i].fi<col[i+1].fi) {
                adj[cur].push_back(make_pair(next,1));
            } else {
                adj[cur].push_back(make_pair(next,0));
                adj[next].push_back(make_pair(cur,0));
            }
        }
    }
    FOR(i,1,m*n) FORE(jt,adj[i]) if (jt->se==1)
        revAdj[jt->fi].push_back(i);
}
void dfs(int u) {
    low[u]=num[u]=++cnt;
    st.push(u);
    FORE(it,adj[u]) if (compID[it->fi]==0) {
        int v=it->fi;
        if (num[v]==0) {
            dfs(v);
            minimize(low[u],low[v]);
        } else minimize(low[u],num[v]);
    }
    if (low[u]==num[u]) {
        nComp++;
        int v;
        do {
            v=st.top();st.pop();
            compID[v]=nComp;
            comp[nComp].push_back(v);
        } while (v!=u);
    }
}
int dp(int u) {
    if (f[u]>=0) return (f[u]);
    f[u]=1;
    FORE(it,comp[u]) FORE(jt,revAdj[*it]) maximize(f[u],dp(compID[*jt])+1);
    return (f[u]);
}
void process(void) {
    FOR(i,1,m*n) if (num[i]==0) dfs(i);
    memset(f,-1,sizeof f);
    REP(i,m) {
        REP(j,n) printf("%d ",dp(compID[POS(i,j)]));
        printf("\n");
    }
}
int main(void) {
    loadGraph();
    process();
    return 0;
}