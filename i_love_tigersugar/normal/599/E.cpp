#include<bits/stdc++.h>
#define MAX  14
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
int reqEdge[MAX];
vector<pair<int,int> > reqLCA[MAX];
int reqChild[MAX];
long long f[MAX][MASK(MAX)+7][MAX];
bool validMask[MAX][MASK(MAX)+7];
vector<int> validSubMask[MAX][MASK(MAX)+7];
int n,m,q;
void init(void) {
    scanf("%d%d%d",&n,&m,&q);
    REP(love,m) {
        int u,v;
        scanf("%d%d",&u,&v);
        u--;v--;
        reqEdge[u]|=MASK(v);
        reqEdge[v]|=MASK(u);
    }
    REP(love,q) {
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        u--;v--;w--;
        reqLCA[w].push_back(make_pair(u,v));
        if (u!=w) reqChild[u]|=MASK(w);
        if (v!=w) reqChild[v]|=MASK(w);
    }
}
long long dp(int root,int mask,int minChild) {
    if (f[root][mask][minChild]>=0) return (f[root][mask][minChild]);
    if (!validMask[root][mask]) return (0);
    long long &res=f[root][mask][minChild];
    if (mask==MASK(root)) return (res=1);
    res=0;
    FORE(it,validSubMask[root][mask]) FOR(subRoot,minChild,n-1) if (BIT(*it,subRoot))
        if ((reqEdge[root]&*it&~MASK(subRoot))==0) {
            //long long tmp=dp(subRoot,*it,0)*dp(root,mask^*it,subRoot+1);
            res+=dp(subRoot,*it,0)*dp(root,mask^*it,subRoot+1);
            //if (tmp>0) printf("ADD %lld (%d,%d,%d)*(%d,%d,%d) to (%d,%d,%d)\n",tmp,
                //subRoot,*it,0,root,mask^*it,subRoot+1,root,mask,minChild);
        }

    //printf("DP %d %d %d is %lld\n",root,mask,minChild,res);
    return (res);
}
bool isValidMask(int root,int mask) {
    if (!BIT(mask,root)) return (false);
    if ((reqChild[root]&mask)>0) return (false);
    return (true);
}
int chooseRoot(int mask,int sub) {
    int mustRoot=0;
    int canRoot=mask^sub;
    REP(i,n) if (BIT(mask,i)) FORE(it,reqLCA[i]) if (BIT(mask,it->fi) && BIT(mask,it->se)) {
        int j=it->fi;
        int k=it->se;
        if (BIT(sub,i) && BIT(sub,j) && BIT(sub,k)) continue;
        if (!BIT(sub,i) && !BIT(sub,j) && !BIT(sub,k)) continue;
        mustRoot|=MASK(i);
    }
    if (__builtin_popcount(mustRoot)>1) return (0);
    if (mustRoot==0) return (canRoot);
    return ((canRoot|mustRoot)==canRoot?mustRoot:0);
}
bool isValidSubMask(int root,int mask,int sub) {
    FORE(it,reqLCA[root]) if (BIT(sub,it->fi) && BIT(sub,it->se)) return (false);
    REP(i,n) if (BIT(sub,i) && (reqEdge[i]|sub|MASK(root))!=(sub|MASK(root))) return (false);
    return (true);
}
void process(void) {
    REP(i,n) REP(j,MASK(n)) validMask[i][j]=isValidMask(i,j);
    REP(j,MASK(n)) REP(k,MASK(n)) if ((j|k)==j) {
        int tmp=chooseRoot(j,k);
        REP(i,n) if (BIT(tmp,i) && isValidSubMask(i,j,k))
            validSubMask[i][j].push_back(k);
    }
    memset(f,-1,sizeof f);
    cout<<dp(0,MASK(n)-1,0)<<endl;
    //cout<<dp(1,14,0)<<endl;
    //cout<<dp(0,1,2)<<endl;
}
int main(void) {
#ifdef SKY
    freopen("tmp.txt","r",stdin);
#endif // SKY
    init();
    process();
    return 0;
}