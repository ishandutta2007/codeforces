#include<bits/stdc++.h>
#define MAX   555
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
using namespace std;
const string noAnswer="Impossible";
string a[MAX];
bool adj[MAX][MAX],vst[MAX];
int low[MAX],num[MAX],compID[MAX];
int n,cnt,nComp;
stack<int> st;
string res;
bool isPrefix(const string &s,const string &t) {
    if (s.size()>t.size()) return (false);
    return (t.substr(0,s.size())==s);
}
int diffPos(const string &s,const string &t) {
    REP(i,min(s.size(),t.size())) if (s[i]!=t[i]) return (i);
    assert(false);
}
void init(void) {
    cin>>n;
    FOR(i,1,n) cin>>a[i];
    FOR(i,1,n-1) {
        if (isPrefix(a[i+1],a[i])) {
            cout<<noAnswer<<endl;
            exit(0);
        }
        if (isPrefix(a[i],a[i+1])) continue;
        int pos=diffPos(a[i],a[i+1]);
        adj[a[i][pos]][a[i+1][pos]]=true;
    }
}
void visit(int u) {
    low[u]=num[u]=++cnt;
    st.push(u);
    FOR(v,'a','z') if (adj[u][v] && compID[v]==0) {
        if (num[v]==0) {
            visit(v);
            low[u]=min(low[u],low[v]);
        } else low[u]=min(low[u],num[v]);
    }
    if (low[u]==num[u]) {
        nComp++;
        int sz=0;
        int v;
        do {
            v=st.top();st.pop();
            compID[v]=nComp;
            sz++;
        } while (v!=u);
        if (sz>1) {
            cout<<noAnswer<<endl;
            exit(0);
        }
    }
}
void dfs(int u) {
    vst[u]=true;
    FOR(v,'a','z') if (adj[u][v] && !vst[v]) dfs(v);
    res.push_back(u);
}
void process(void) {
    FOR(i,'a','z') if (num[i]==0) visit(i);
    FOR(i,'a','z') if (!vst[i]) dfs(i);
    reverse(res.begin(),res.end());
    cout<<res<<endl;
}
int main(void) {
    init();
    process();
    return 0;
}