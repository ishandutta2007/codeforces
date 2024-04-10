#include<cstdio>
#include<cstring>
#include<iostream>
#include<map>
#include<stack>
#include<string>
#include<vector>
#define MAX   300300
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
#define fi   first
#define se   second
using namespace std;
const int INF=(int)1e9+7;
typedef pair<int,int> ii;
class Compare {
    public:
    bool operator () (const string &s,const string &t) const {
        if (s.size()!=t.size()) return (s.size()<t.size());
        REP(i,s.size()) {
            if (s[i]<t[i]) return (true);
            if (s[i]>t[i]) return (false);
        }
        return (false);
    }
};
map<string,int> wid;
ii val[MAX],vcp[MAX],f[MAX];
vector<int> g[MAX],h[MAX];
int low[MAX],num[MAX],cpid[MAX];
vector<int> tid;
bool fre[MAX];
int nw,nc,cnt;
stack<int> st;
template<class T>
    inline void minimize(T &x,const T &y) {
        if (x>y) x=y;
    }
inline int nextint(void) {
    int x;
    cin>>x;
    return (x);
}
inline string nextstring(void) {
    string s;
    cin>>s;
    FORE(it,s) if ('a'<=*it && *it<='z') *it-='a'-'A';
    return (s);
}
inline ii value(const string &s) {
    int res=0;
    FORE(it,s) if (*it=='R') res++;
    return (ii(res,s.size()));
}
inline int strid(const string &s) {
    __typeof(wid.begin()) it=wid.find(s);
    if (it==wid.end()) {
        wid[s]=++nw;
        val[nw]=value(s);
        return (nw);
    }
    return (it->se);
}
void init(void) {
    REP(zz,nextint()) tid.push_back(strid(nextstring()));
    REP(zz,nextint()) {
        int u=strid(nextstring());
        int v=strid(nextstring());
        g[u].push_back(v);
    }
    FOR(i,1,nw) fre[i]=true;
}
void visit(int u) {
    low[u]=num[u]=++cnt;
    st.push(u);
    FORE(it,g[u]) if (fre[*it]) {
        int v=*it;
        if (num[v]==0) {
            visit(v);
            minimize(low[u],low[v]);
        }
        else minimize(low[u],num[v]);
    }
    if (low[u]==num[u]) {
        int v;
        nc++;
        do {
            v=st.top();st.pop();
            cpid[v]=nc;
            fre[v]=false;
        }
        while (v!=u);
    }
}
void tarjan(void) {
    FOR(i,1,nw) if (num[i]==0) visit(i);
    FOR(i,1,nc) vcp[i]=ii(INF,INF);
    FOR(i,1,nw) minimize(vcp[cpid[i]],val[i]);
    FOR(i,1,nc) f[i]=ii(-1,-1);
    FOR(i,1,nw) FORE(it,g[i]) {
        int j=*it;
        if (cpid[i]!=cpid[j]) h[cpid[i]].push_back(cpid[j]);
    }
}
ii dp(int u) {
    if (f[u].fi>=0) return (f[u]);
    f[u]=vcp[u];
    FORE(it,h[u]) minimize(f[u],dp(*it));
    return (f[u]);
}
void process(void) {
    long long cnt=0;
    long long len=0;
    FORE(it,tid) {
        ii tmp=dp(cpid[*it]);
        cnt+=tmp.fi;
        len+=tmp.se;
    }
    cout<<cnt<<" "<<len;
}
int main(void) {
    ios::sync_with_stdio(false);
    init();
    tarjan();
    process();
    return 0;
}