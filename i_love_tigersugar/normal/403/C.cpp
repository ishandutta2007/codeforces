#include<bits/stdc++.h>
#define MAX   2228
#define FOR(i,a,b) for (int i=(a);i<=(b);i=i+1)
#define REP(i,n) for (int i=0;i<(n);i=i+1)
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
using namespace std;
vector<int> g[MAX];
bool fre[MAX];
int low[MAX],num[MAX];
int n,nc,cnt;
stack<int> st;
void init(void) {
    scanf("%d",&n);
    FOR(i,1,n) FOR(j,1,n) {
        int v;
        scanf("%d",&v);
        if (v>0) g[i].push_back(j);
    }
}
void dfs(int u) {
    cnt++;
    low[u]=num[u]=cnt;
    st.push(u);
    FORE(it,g[u]) if (fre[*it]) {
        int v=*it;
        if (num[v]==0) {
            dfs(v);
            low[u]=min(low[u],low[v]);
        }
        else low[u]=min(low[u],num[v]);
    }
    if (low[u]==num[u]) {
        nc++;
        while (true) {
            int v=st.top();st.pop();
            fre[v]=false;
            if (v==u) break;
        }
    }
}
void process(void) {
    FOR(i,1,n) fre[i]=true;
    FOR(i,1,n) if (num[i]==0) dfs(i);
    if (nc==1) printf("YES"); else printf("NO");
}
int main(void) {
    init();
    process();
    return 0;
}