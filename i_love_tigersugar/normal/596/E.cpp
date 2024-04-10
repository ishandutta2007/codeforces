#include<bits/stdc++.h>
#define MAX   227
#define CELLID(x,y) (((x)-1)*n+(y))
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
using namespace std;
template<class X,class Y>
    void minimize(X &x,const Y &y) {
        if (x>y) x=y;
    }
template<class X,class Y>
    void maximize(X &x,const Y &y) {
        if (x<y) x=y;
    }
const char yes[]="YES";
const char no[]="NO";
char a[MAX][MAX],dig[MAX*MAX];
pair<int,int> dir[MAX];
int next[MAX*MAX];
int m,n,q,cnt,nComp;
int low[MAX*MAX],num[MAX*MAX],compSZ[MAX*MAX],compID[MAX*MAX],digit[MAX*MAX];
stack<int> st;
bool isRoot[MAX*MAX];
int maxMatch[MAX*MAX];
vector<int> child[MAX*MAX];
string query;
int firstPos[MAX];
bool inside(int x,int y) {
    if (x<1 || x>m || y<1 || y>n) return (false);
    return (true);
}
void init(void) {
    scanf("%d%d%d",&m,&n,&q);
    FOR(i,1,m) scanf("%s",a[i]+1);
    REP(i,10) scanf("%d%d",&dir[i].fi,&dir[i].se);
    FOR(i,1,m) FOR(j,1,n) {
        dig[CELLID(i,j)]=a[i][j];
        int x=i+dir[a[i][j]-'0'].fi;
        int y=j+dir[a[i][j]-'0'].se;
        if (inside(x,y)) next[CELLID(i,j)]=CELLID(x,y);
        else next[CELLID(i,j)]=CELLID(i,j);
        //printf("next %d is %d\n",CELLID(i,j),next[CELLID(i,j)]);
    }
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
        nComp++;
        int v;
        do {
            v=st.top();st.pop();
            compID[v]=nComp;
            compSZ[nComp]++;
            digit[nComp]|=MASK(dig[v]-'0');
        } while (v!=u);
    }
}
void prepare(void) {
    FOR(i,1,m*n) if (num[i]==0) dfs(i);
    FOR(i,1,m*n) isRoot[i]=(compSZ[compID[i]]>1) || (next[i]==i);
    FOR(i,1,m*n) if (!isRoot[i]) child[next[i]].push_back(i);
}
void dfsTree(int u) {
    //printf("NODE %d match %d\n",u,maxMatch[u]);
    FORE(it,child[u]) {
        int v=*it;
        maxMatch[v]=maxMatch[u]>=query.size()?maxMatch[u]:maxMatch[u]+(dig[v]==query[maxMatch[u]]);
        dfsTree(v);
    }
}
void answer(void) {
    cin>>query;
    reverse(ALL(query));
    memset(firstPos,0x3f,sizeof firstPos);
    REP(i,query.size()) minimize(firstPos[query[i]-'0'],i);
    memset(maxMatch,0x3f,sizeof maxMatch);
    FOR(i,1,m*n) if (isRoot[i]) REP(j,10) if (!BIT(digit[compID[i]],j))
        minimize(maxMatch[i],firstPos[j]);
    FOR(i,1,m*n) if (isRoot[i]) dfsTree(i);
    FOR(i,1,m*n) if (maxMatch[i]>=query.size()) {
        printf("%s\n",yes);
        return;
    }
    printf("%s\n",no);
}
void process(void) {
    REP(love,q) answer();
}
int main(void) {
#ifdef SKY
    freopen("tmp.txt","r",stdin);
#endif // SKY
    init();
    prepare();
    process();
    return 0;
}