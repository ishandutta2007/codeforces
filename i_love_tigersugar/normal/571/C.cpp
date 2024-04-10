#include<bits/stdc++.h>
#define MAX   200200
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
#define ALL(v) (v).begin(),(v).end()
#define MASK(i) (1<<(i))
#define BIT(x,i) (((x)>>(i))&1)
#define fi   first
#define se   second
using namespace std;
const char yes[]="YES";
const char no[]="NO";
struct Edge {
    int u,v;
    Edge() {
        u=v=0;
    }
    Edge(int _u,int _v) {
        u=_u;v=_v;
    }
    int other(int x) const {
        assert(u==x || v==x);
        return (u^v^x);
    }
};
Edge edge[MAX];
int numVar,numGroup;
vector<int> varIn[MAX],group[MAX],adj[MAX];
bool cleared[MAX];
int answer[MAX];
int par[MAX];
int Abs(int x) {
    return (x<0?-x:x);
}
void init(void) {
    scanf("%d%d",&numGroup,&numVar);
    FOR(i,1,numGroup) {
        int sz;
        scanf("%d",&sz);
        if (sz==0) cleared[i]=true;
        REP(love,sz) {
            int val;
            scanf("%d",&val);
            group[i].push_back(val);
            if (val>0) varIn[val].push_back(i);
            else varIn[-val].push_back(-i);
        }
    }
    memset(answer,-1,sizeof answer);
}
int haveType(int i) {
    int res=0;
    FORE(it,varIn[i]) {
        if (*it<0) res|=MASK(0);
        else res|=MASK(1);
    }
    return (res);
}
void clearGroup(void) {
    set<pair<int,int> > s;
    FOR(i,1,numVar) s.insert(make_pair(haveType(i),i));
    while (!s.empty()) {
        if (s.begin()->fi==3) break;
        pair<int,int> tmp=*s.begin();
        s.erase(s.begin());
        if (tmp.fi==0) {
            answer[tmp.se]=1;
            continue;
        }
        //printf("Clear %d %d\n",tmp.se,tmp.fi);
        answer[tmp.se]=tmp.fi==2?1:0;
        FORE(it,varIn[tmp.se]) {
            int cur=Abs(*it);
            cleared[cur]=true;
            //printf("\tClear group %d: ",cur);
            //FORE(jt,group[cur]) printf("%d ",*jt); printf("\n");
            FORE(jt,group[cur]) if (answer[Abs(*jt)]<0) {
                int var=Abs(*jt);
                //printf("\t\tClear var %d\n",var);
                s.erase(make_pair(haveType(var),var));
                if (find(ALL(varIn[var]),cur)!=varIn[var].end())
                    varIn[var].erase(find(ALL(varIn[var]),cur));
                if (find(ALL(varIn[var]),-cur)!=varIn[var].end())
                    varIn[var].erase(find(ALL(varIn[var]),-cur));
                s.insert(make_pair(haveType(var),var));
            }
        }
    }
}
void loadGraph(void) {
    FOR(i,1,numVar) if (answer[i]<0) {
        int u=-1;
        int v=-1;
        FORE(it,varIn[i]) {
            if (*it>0) u=*it;
            if (*it<0) v=-*it;
        }
        assert(u>0 && v>0);
        adj[u].push_back(i);
        adj[v].push_back(i);
        edge[i]=Edge(u,v);
        //printf("Add edge %d from %d to %d\n",i,u,v);
    }
    memset(par,-1,sizeof par);
}
void revPath(int u,int s) {
    while (u!=s) {
        answer[par[u]]^=1;
        u=edge[par[u]].other(u);
    }
}
void bfs(int s) {
    queue<int> q;
    par[s]=0;
    q.push(s);
    int traceEdge=-1;
    while (!q.empty()) {
        int u=q.front();q.pop();
        FORE(it,adj[u]) {
            int v=edge[*it].other(u);
            if (par[v]<0) {
                par[v]=*it;
                q.push(v);
                answer[*it]=edge[*it].u==v?1:0;
            } else if (par[u]!=*it) {
                //printf("AT %d %d choose %d\n",u,v,*it);
                traceEdge=*it;
            }
        }
    }
    //printf("Trace of %d is %d\n",s,traceEdge);
    if (traceEdge<0) {
        printf("%s\n",no);
        exit(0);
    }
    answer[traceEdge]=1;
    revPath(edge[traceEdge].u,s);
}
void process(void) {
    FOR(i,1,numGroup) if (!cleared[i] && par[i]<0) bfs(i);
    FOR(i,1,numVar) if (answer[i]<0) answer[i]=1;
    FOR(i,1,numVar) assert(answer[i]==0 || answer[i]==1);
    printf("%s\n",yes);
    FOR(i,1,numGroup) {
        bool ok=false;
        FORE(it,group[i]) {
            if (*it<0 && answer[-*it]==0) ok=true;
            if (*it>0 && answer[*it]==1) ok=true;
        }
        assert(ok);
    }
    FOR(i,1,numVar) printf("%d",answer[i]);
    printf("\n");
}
int main(void) {
    init();
    clearGroup();
    loadGraph();
    process();
    return 0;
}