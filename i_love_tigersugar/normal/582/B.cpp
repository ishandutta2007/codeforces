#include<bits/stdc++.h>
#define MAX   333
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
const int INF=(int)1e9+7;
template<class X,class Y>
    void minimize(X &x,const Y &y) {
        if (x>y) x=y;
    }
template<class X,class Y>
    void maximize(X &x,const Y &y) {
        if (x<y) x=y;
    }
int a[MAX],n,lim;
vector<int> val;
int len[MAX][MAX],tmp[MAX],cnt[MAX];
int left[MAX][MAX],right[MAX][MAX];
void init(void) {
    scanf("%d%d",&n,&lim);
    FOR(i,1,n) scanf("%d",&a[i]);
    FOR(i,1,n) val.push_back(a[i]);
    sort(ALL(val));
    val.resize(unique(ALL(val))-val.begin());
    FOR(i,1,n) a[i]=lower_bound(ALL(val),a[i])-val.begin()+1;
    FOR(i,1,n) cnt[a[i]]++;
}
void process(void) {
    FOR(l,1,val.size()) FOR(r,l,val.size()) {
        FOR(i,1,n) tmp[i]=a[i]>=l?1:-INF;
        FOR(i,1,n) if (l<=a[i] && a[i]<=r)
            FOR(j,1,i-1) if (l<=a[j] && a[j]<=a[i]) maximize(tmp[i],tmp[j]+1);
        FOR(i,1,n) if (l<=a[i] && a[i]<=r) maximize(len[l][r],tmp[i]);
    }
    memset(left,-0x3f,sizeof left);
    memset(right,-0x3f,sizeof right);
    FOR(i,1,val.size()) left[i][0]=right[i][0]=0;
    REP(i,val.size()) FOR(j,1,val.size()) FOR(k,j+1,val.size())
        maximize(left[k][i+1],left[j][i]+len[j][k]);
    REP(i,val.size()) FOR(j,1,val.size()) FOR(k,1,j-1)
        maximize(right[k][i+1],right[j][i]+len[k][j]);
    int res=0;
    FOR(i,1,val.size()) REP(j,val.size()+1) REP(k,val.size()+1) if (j+k<=lim)
        maximize(res,cnt[i]*(lim-j-k)+left[i][j]+right[i][k]);
    printf("%d\n",res);
}
int main(void) {
    init();
    process();
    return 0;
}