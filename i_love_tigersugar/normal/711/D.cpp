#include<bits/stdc++.h>
#define MAX   200200
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define FORD(i,b,a) for (int i=(b),_a=(a);i>=_a;i=i-1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
#define ALL(v) (v).begin(),(v).end()
#define fi   first
#define se   second
#define MASK(i) (1LL<<(i))
#define BIT(x,i) (((x)>>(i))&1)
#define div   ___div
#define next   ___next
#define prev   ___prev
#define left   ___left
#define right   ___right
#define __builtin_popcount __builtin_popcountll
using namespace std;
template<class X,class Y>
    void minimize(X &x,const Y &y) {
        if (x>y) x=y;
    }
template<class X,class Y>
    void maximize(X &x,const Y &y) {
        if (x<y) x=y;
    }
template<class T>
    T Abs(const T &x) {
        return (x<0?-x:x);
    }
const int mod=(int)1e9+7;
int next[MAX],low[MAX],num[MAX],compID[MAX],compSize[MAX];
int n,cnt,numComp;
stack<int> st;
int pw(int n,int k) {
    int res=1;
    int mul=n;
    while (k>0) {
        if (k&1) res=1LL*res*mul%mod;
        mul=1LL*mul*mul%mod;
        k>>=1;
    }
    return (res);
}
void loadGraph(void) {
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d",&next[i]);
}
void dfs(int u) {
    low[u]=num[u]=++cnt;
    st.push(u);
    int v=next[u];
    if (compID[v]==0) {
        if (num[v]==0) {
            dfs(v);
            minimize(low[u],low[v]);
        } else minimize(low[u],num[v]);
    }
    if (low[u]==num[u]) {
        numComp++;
        while (true) {
            int v=st.top();st.pop();
            compID[v]=numComp;
            compSize[numComp]++;
            if (v==u) break;
        }
    }
}
void process(void) {
    FOR(i,1,n) if (num[i]==0) dfs(i);
    int res=1;
    int treeEdge=n;
    FOR(i,1,numComp) if (compSize[i]>1) {
        treeEdge-=compSize[i];
        res=1LL*res*(pw(2,compSize[i])-2+mod)%mod;
    }
    res=1LL*res*pw(2,treeEdge)%mod;
    printf("%d\n",res);
}
int main(void) {
    loadGraph();
    process();
    return 0;
}