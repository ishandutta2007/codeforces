#include<bits/stdc++.h>
#define MAX   100100
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
#define ALL(v) (v).begin(),(v).end()
#define fi   first
#define se   second
using namespace std;
struct Fraction {
    int p,q;
    Fraction() {
        p=0;q=1;
    }
    Fraction(int _p,int _q) {
        p=_p;q=_q;
    }
    int cmp(const Fraction &x) const {
        long long a=1LL*p*x.q;
        long long b=1LL*q*x.p;
        return ((a>b)-(a<b));
    }
    #define DEF_OPER(x) bool operator x (const Fraction &a) const { return (cmp(a) x 0); }
    DEF_OPER(<) DEF_OPER(>) DEF_OPER(<=) DEF_OPER(>=) DEF_OPER(==) DEF_OPER(!=)
    #undef DEF_OPER
};
vector<Fraction> answer;
vector<int> adj[MAX];
bool block[MAX];
int unBlock[MAX];
int n,m,k;
Fraction rate[MAX];
bool del[MAX];
void loadGraph(void) {
    scanf("%d%d%d",&n,&m,&k);
    REP(love,k) {
        int x;
        scanf("%d",&x);
        block[x]=true;
    }
    REP(love,m) {
        int u,v;
        scanf("%d%d",&u,&v);
        adj[u].push_back(v);
        adj[v].push_back(u);
        if (!block[u]) unBlock[v]++;
        if (!block[v]) unBlock[u]++;
    }
    answer.push_back(Fraction(0,1));
    FOR(i,1,n) FOR(j,1,adj[i].size()) answer.push_back(Fraction(j,adj[i].size()));
    sort(ALL(answer));
    answer.resize(unique(ALL(answer))-answer.begin());
}
bool ok(const Fraction &x,vector<int> &v) {
    v.clear();
    memset(del,false,sizeof del);
    FOR(i,1,n) if (block[i]) del[i]=true;
    priority_queue<pair<Fraction,int>,vector<pair<Fraction,int> >,greater<pair<Fraction,int> > > q;
    FOR(i,1,n) if (!block[i]) {
        rate[i]=Fraction(unBlock[i],adj[i].size());
        q.push(make_pair(rate[i],i));
    }
    while (!q.empty()) {
        Fraction curRate=q.top().fi;
        int u=q.top().se;
        q.pop();
        if (del[u] || curRate!=rate[u]) continue;
        if (curRate>=x) {
            FOR(i,1,n) if (!del[i]) v.push_back(i);
            return (!v.empty());
        }
        del[u]=true;
        FORE(it,adj[u]) if (!del[*it]) {
            rate[*it].p--;
            q.push(make_pair(rate[*it],*it));
        }
    }
    return (false);
}
Fraction findResult(void) {
    vector<int> v;
    int L=0;
    int R=answer.size()-1;
    while (true) {
        if (L==R) return (answer[R]);
        if (R-L==1) return (ok(answer[R],v)?answer[R]:answer[L]);
        int M=(L+R)>>1;
        if (ok(answer[M],v)) L=M; else R=M-1;
    }
}
void process(void) {
    vector<int> v;
    assert(ok(findResult(),v));
    assert(!v.empty());
    printf("%d\n",(int)v.size());
    FORE(it,v) printf("%d ",*it); printf("\n");
}
int main(void) {
    loadGraph();
    process();
    return 0;
}