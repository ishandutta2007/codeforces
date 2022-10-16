#include<bits/stdc++.h>
#define MAXD   100
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
#define MASK(i) (1<<(i))
#define BIT(x,i) (((x)>>(i))&1)
using namespace std;
typedef long long ll;
const int mod=(int)1e9+7;
const ll INF=(ll)2e18+7LL;
struct Matrix {
    int m,n;
    vector<vector<ll> > d;
    Matrix() {
        m=n=0;
        d.clear();
    }
    Matrix(int m,int n) {
        this->m=m;
        this->n=n;
        d.assign(m,vector<ll>(n,0));
    }
    Matrix operator * (const Matrix &a) const {
        int x=m;
        int y=n;
        int z=a.n;
        Matrix res(x,z);
        REP(i,x) REP(j,y) REP(k,z) {
            res.d[i][k]+=d[i][j]*a.d[j][k];
            if (res.d[i][k]>=INF) res.d[i][k]%=mod;
        }
        REP(i,x) REP(k,z) res.d[i][k]%=mod;
        return (res);
    }
};
Matrix fst,mul[111];
int n,lim,cnt[111];
void process(void) {
    scanf("%d%d",&n,&lim);
    REP(love,n) {
        int x;
        scanf("%d",&x);
        cnt[x]++;
    }
    fst=Matrix(1,MAXD+1);
    REP(i,MAXD+1) fst.d[0][i]=1;
    FOR(i,1,MAXD-1) REP(j,i) fst.d[0][i]=(fst.d[0][i]+1LL*fst.d[0][j]*cnt[i-j])%mod;
    if (lim<MAXD) {
        cout<<fst.d[0][lim]<<endl;
        return;
    }
    mul[0]=Matrix(MAXD+1,MAXD+1);
    FOR(i,1,MAXD-1) mul[0].d[i][i-1]=1;
    REP(i,MAXD) mul[0].d[i][MAXD-1]=cnt[MAXD-i];
    mul[0].d[MAXD][MAXD]=mul[0].d[MAXD][MAXD-1]=1;
    int tmp=lim-MAXD+1;
    FOR(i,0,30) {
        if (i>0) mul[i]=mul[i-1]*mul[i-1];
        if (BIT(tmp,i)) fst=fst*mul[i];
    }
    cout<<fst.d[0][MAXD-1]<<endl;
}
int main(void) {
#ifdef SKY
    freopen("tmp.txt","r",stdin);
#endif // SKY
    process();
    return 0;
}