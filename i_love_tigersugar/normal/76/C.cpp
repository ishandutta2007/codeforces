#include<bits/stdc++.h>
#define MAXN   200200
#define MAXK   22
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define FORD(i,b,a) for (int i=(b),_a=(a);i>=_a;i=i-1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
#define ALL(v) (v).begin(),(v).end()
#define MASK(i) (1<<(i))
#define BIT(x,i) (((x)>>(i))&1)
#define fi   first
#define se   second
#define next   fjoasidj
using namespace std;
int n,m,lim;
char s[MAXN];
int adj[MAXK+7][MAXK+7],val[MAXK+7];
int totCost[MASK(MAXK)+7],maskCost[MASK(MAXK)+7];
int next[MAXN][MAXK+7];
void init(void) {
    scanf("%d%d%d",&n,&m,&lim);
    scanf("%s",s+1);
    REP(i,m) scanf("%d",&val[i]);
    REP(i,m) REP(j,m) scanf("%d",&adj[i][j]);
}
void prepare(void) {
    REP(i,m) next[n][i]=n+1;
    FORD(i,n-1,0) {
        REP(j,m) next[i][j]=next[i+1][j];
        next[i][s[i+1]-'A']=i+1;
    }
    FOR(i,1,n) {
        vector<pair<int,int> > ch;
        REP(j,m) if (next[i][j]<=n) ch.push_back(make_pair(next[i][j],j));
        sort(ALL(ch));
        int mask=0;
        FORE(it,ch) {
            int tmp=adj[s[i]-'A'][it->se];
            maskCost[mask]+=tmp;
            maskCost[mask|MASK(s[i]-'A')]-=tmp;
            maskCost[mask|MASK(it->se)]-=tmp;
            maskCost[mask|MASK(s[i]-'A')|MASK(it->se)]+=tmp;
            mask|=MASK(it->se);
            if (it->se==s[i]-'A') break;
        }
    }
}
void calcCost(int l,int r) {
    if (l+1==r) {
        totCost[l]=maskCost[l];
        return;
    }
    int m=(l+r)>>1;
    calcCost(l,m);
    calcCost(m,r);
    FOR(i,l,m-1) totCost[i+m-l]+=totCost[i];
}
void process(void) {
    calcCost(0,MASK(m));
    REP(i,MASK(m)) REP(j,m) if (BIT(i,j)) totCost[i]+=val[j];
    int charMask=0;
    FOR(i,1,n) charMask|=MASK(s[i]-'A');
    int res=0;
    REP(i,MASK(m)) if (i!=charMask && (i&charMask)==i && totCost[i]<=lim) res++;
    printf("%d\n",res);
}
int main(void) {
    init();
    prepare();
    process();
    return 0;
}