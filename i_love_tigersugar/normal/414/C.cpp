#include<bits/stdc++.h>
#define FOR(i,a,b) for (int i=(a);i<=(b);i=i+1)
#define FORD(i,b,a) for (int i=(b);i>=(a);i=i-1)
#define REP(i,n) for (int i=0;i<(n);i=i+1)
#define fi   first
#define se   second
using namespace std;
typedef long long ll;
int a[(1<<20)+7];
ll cnt[(1<<20)+7][22][2];
ll s[27][2];
int n,q;
class BIT {
    private:
    int n;
    vector<int> v;
    int get(int x) const {
        int ret=0;
        for (;x>=1;x&=x-1) ret+=v[x];
        return (ret);
    }
    public:
    BIT() {
        n=0;
    }
    BIT(int n) {
        this->n=n;
        v.assign(n+7,0);
    }
    void update(int x) {
        for (;x<=n;x+=x&(-x)) v[x]++;
    }
    int countbig(int x) const {
        return (get(n)-get(x));
    }
    int countsmall(int x) const {
        return (get(x-1));
    }
};
void init(void) {
    scanf("%d",&n);
    REP(i,1<<n) scanf("%d",&a[i]);
}
void countinv(int l,int k) {
    //printf("Count inverse of %d %d\n",l,k);
    //REP(i,1<<k) printf("%d ",a[l+i]); printf("\n");
    vector<int> v;
    v.clear();
    REP(i,1<<k) v.push_back(a[l+i]);
    sort(v.begin(),v.end());
    v.resize(unique(v.begin(),v.end())-v.begin());
    BIT bit=BIT(v.size());
    FORD(i,(1<<k)-1,0) {
        int id=lower_bound(v.begin(),v.end(),a[l+i])-v.begin()+1;
        //cnt[l][k][0]+=bit.countsmall(id);
        //cnt[l][k][1]+=bit.countbig(id);
        s[k][0]+=bit.countsmall(id);
        s[k][1]+=bit.countbig(id);
        bit.update(id);
    }
}
void process(void) {
    FOR(i,1,n) REP(j,1<<(n-i)) countinv(j*(1<<i),i);
    //FOR(i,0,n) REP(j,2) printf("s(%d,%d)=%I64d\n",i,j,s[i][j]);
    scanf("%d",&q);
    REP(zz,q) {
        int t;
        scanf("%d",&t);
        ll del[2];
        REP(i,2) del[i]=s[t][i^1]-s[t][i];
        FOR(i,0,n) {
            if (i<=t) swap(s[i][0],s[i][1]);
            else REP(j,2) s[i][j]+=del[j];
        }
        printf("%I64d\n",s[n][0]);
    }
}
int main(void) {
#ifndef ONLINE_JUDGE
    freopen("tmp.txt","r",stdin);
#endif
    init();
    process();
    return 0;
}