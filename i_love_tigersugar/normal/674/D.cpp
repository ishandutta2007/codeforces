#include<bits/stdc++.h>
#define MAX   100100
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
template<class Type>
    Type minValue(const set<Type> &s) {
        assert(!s.empty());
        return (*s.begin());
    }
template<class Type>
    Type maxValue(const set<Type> &s) {
        assert(!s.empty());
        __typeof(s.begin()) it=s.end();
        return (*(--it));
    }
int par[MAX],deg[MAX],n,q;
long long capa[MAX],ownIncome[MAX],childIncome[MAX];
set<pair<long long,int> > child[MAX],global;
pair<long long,int> operator + (const pair<long long,int> &p,long long x) {
    return (make_pair(p.fi+x,p.se));
}
void init(void) {
    cin>>n>>q;
    FOR(i,1,n) cin>>capa[i];
    FOR(i,1,n) cin>>par[i];
}
void addGlobal(int node) {
    if (child[node].empty()) return;
    long long fromNode=capa[node]/(deg[node]+1);
    global.insert(minValue(child[node])+fromNode);
    global.insert(maxValue(child[node])+fromNode);
}
void removeGlobal(int node) {
    if (child[node].empty()) return;
    long long fromNode=capa[node]/(deg[node]+1);
    global.erase(minValue(child[node])+fromNode);
    global.erase(maxValue(child[node])+fromNode);
}
void prepare(void) {
    FOR(i,1,n) {
        deg[i]++;
        deg[par[i]]++;
    }
    FOR(i,1,n) childIncome[par[i]]+=capa[i]/(deg[i]+1);
    FOR(i,1,n) ownIncome[i]=capa[i]-capa[i]/(deg[i]+1)*deg[i];
    FOR(i,1,n) assert(child[par[i]].insert(make_pair(ownIncome[i]+childIncome[i],i)).se);
    FOR(i,1,n) addGlobal(i);
}
long long getIncome(int node) {
    return (ownIncome[node]+childIncome[node]);
}
void update(int node,int oldPar,int newPar) {
    int parOldPar=par[oldPar];
    int parNewPar=par[newPar];
    //remove old global elements
    removeGlobal(oldPar);
    removeGlobal(newPar);
    removeGlobal(parOldPar);
    removeGlobal(parNewPar);
    removeGlobal(par[parOldPar]);
    removeGlobal(par[parNewPar]);
    //remove old child elememts
    child[oldPar].erase(make_pair(getIncome(node),node));
    child[parOldPar].erase(make_pair(getIncome(oldPar),oldPar));
    child[parNewPar].erase(make_pair(getIncome(newPar),newPar));
    child[par[parOldPar]].erase(make_pair(getIncome(parOldPar),parOldPar));
    child[par[parNewPar]].erase(make_pair(getIncome(parNewPar),parNewPar));
    //change degree & ownIncome
    deg[oldPar]--;
    deg[newPar]++;
    ownIncome[oldPar]=capa[oldPar]-capa[oldPar]/(deg[oldPar]+1)*deg[oldPar];
    ownIncome[newPar]=capa[newPar]-capa[newPar]/(deg[newPar]+1)*deg[newPar];
    //change childIncome
    childIncome[oldPar]-=capa[node]/(deg[node]+1);
    childIncome[newPar]+=capa[node]/(deg[node]+1);
    childIncome[parOldPar]+=capa[oldPar]/(deg[oldPar]+1)-capa[oldPar]/(deg[oldPar]+2);
    childIncome[parNewPar]+=capa[newPar]/(deg[newPar]+1)-capa[newPar]/deg[newPar];
    //add new child elements
    child[newPar].insert(make_pair(getIncome(node),node));
    child[parOldPar].insert(make_pair(getIncome(oldPar),oldPar));
    child[parNewPar].insert(make_pair(getIncome(newPar),newPar));
    child[par[parOldPar]].insert(make_pair(getIncome(parOldPar),parOldPar));
    child[par[parNewPar]].insert(make_pair(getIncome(parNewPar),parNewPar));
    //add new global elements
    addGlobal(oldPar);
    addGlobal(newPar);
    addGlobal(parOldPar);
    addGlobal(parNewPar);
    addGlobal(par[parOldPar]);
    addGlobal(par[parNewPar]);
}
void selfCheck(void) {
    FOR(i,1,n) {
        int tmp=1;
        FOR(j,1,n) if (par[j]==i) tmp++;
        assert(tmp==deg[i]);
        assert(ownIncome[i]==capa[i]-capa[i]/(deg[i]+1)*deg[i]);
        long long sum=0;
        FOR(j,1,n) if (par[j]==i) {
            sum+=capa[j]/(deg[j]+1);
            assert(child[i].find(make_pair(getIncome(j),j))!=child[i].end());
        }
        assert(child[i].size()==deg[i]-1);
        assert(childIncome[i]==sum);
    }
}
#ifdef SKY
void debug(void) {
    printf("STATUS\n");
    FOR(i,1,n) {
        printf("NODE %d:\nParent %d | Degree %d | Own %lld | Child %lld\n",i,par[i],deg[i],ownIncome[i],childIncome[i]);
        printf("Children: ");
        FORE(it,child[i]) printf("(%lld,%d) ",it->fi,it->se); printf("\n");
    }
    printf("GLOBAL:\n");
    FORE(it,global) printf("(%lld,%d) ",it->fi,it->se); printf("\n");
    printf("___END___\n");
}
#endif // SKY
long long getParIncome(int node) {
    node=par[node];
    return (capa[node]/(deg[node]+1));
}
void process(void) {
#ifdef SKY
    debug();
    selfCheck();
#endif // SKY
    REP(love,q) {
        int type; cin>>type;
        if (type==1) {
            int node,newPar; cin>>node>>newPar;
            update(node,par[node],newPar);
            par[node]=newPar;

#ifdef SKY
            debug();
            selfCheck();
#endif // SKY
        } else if (type==2) {
            int node; cin>>node;
            cout<<getIncome(node)+getParIncome(node)<<"\n";
        } else {
            cout<<minValue(global).fi<<" "<<maxValue(global).fi<<"\n";
        }
    }
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