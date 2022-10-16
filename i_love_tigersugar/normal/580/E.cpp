#include<bits/stdc++.h>
#define MAX   100100
#define NMOD   2
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define FORD(i,b,a) for (int i=(b),_a=(a);i>=_a;i=i-1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
#define ALL(v) (v).begin(),(v).end()
#define fi   first
#define se   second
#define MASK(i) (1LL<<(i))
#define BIT(x,i) (((x)>>(i))&1)
#define left    ___left
#define right    ___right
using namespace std;
const char yes[]="YES";
const char no[]="NO";
int mod[NMOD];
int pw[NMOD][MAX];
vector<int> sumPW[NMOD][MAX];
bool isPrime(int x) {
    for (int i=2;1LL*i*i<=x;i=i+1) if (x%i==0) return (false);
    return (true);
}
void genHashMod(void) {
    srand(time(NULL));
    vector<int> prime;
    FOR(i,(int)1e9+1,(int)1e9+2207) if (isPrime(i)) prime.push_back(i);
    random_shuffle(ALL(prime));
    REP(i,NMOD) mod[i]=prime[i];
    REP(i,NMOD) cerr<<mod[i]<<endl;
}
void precount(void) {
    REP(j,NMOD) {
        pw[j][0]=1;
        FOR(i,1,MAX-1) pw[j][i]=(1LL*pw[j][i-1]<<8)%mod[j];
        FOR(i,1,MAX-1) {
            sumPW[j][i].push_back(1);
            for (int k=1;1LL*k*i<MAX;k=k+1)
                sumPW[j][i].push_back((sumPW[j][i].back()+pw[j][i*k])%mod[j]);
        }
    }
}
struct Hash {
    int len,val[NMOD];
    Hash() {
        len=0;
        memset(val,0,sizeof val);
    }
    Hash(int x,int n) {
        len=n;
        REP(i,NMOD) val[i]=1LL*x*sumPW[i][1][n-1]%mod[i];
    }
    Hash operator + (const Hash &x) const {
        Hash res;
        res.len=len+x.len;
        REP(i,NMOD) res.val[i]=(val[i]+1LL*x.val[i]*pw[i][len])%mod[i];
        return (res);
    }
    bool operator == (const Hash &x) const {
        REP(i,NMOD) if (val[i]!=x.val[i]) return (false);
        return (true);
    }
    bool operator != (const Hash &x) const {
        REP(i,NMOD) if (val[i]!=x.val[i]) return (true);
        return (false);
    }
};
class SegmentTree {
    private:
    vector<Hash> tree;
    vector<int> lazy;
    int n;
    void build(char s[],int i,int l,int r) {
        if (l>r) return;
        if (l==r) {
            tree[i]=Hash(s[l],1);
            return;
        }
        int m=(l+r)>>1;
        build(s,2*i,l,m);
        build(s,2*i+1,m+1,r);
        tree[i]=tree[2*i]+tree[2*i+1];
    }
    void pushdown(int i,int l,int r) {
        if (lazy[i]<0) return;
        lazy[2*i]=lazy[2*i+1]=lazy[i];
        int m=(l+r)>>1;
        tree[2*i]=Hash(lazy[i],m-l+1);
        tree[2*i+1]=Hash(lazy[i],r-m);
        lazy[i]=-1;
    }
    void assign(int i,int l,int r,int u,int v,int c) {
        if (l>v || r<u || l>r || v<u) return;
        if (u<=l && r<=v) {
            tree[i]=Hash(c,r-l+1);
            lazy[i]=c;
            return;
        }
        int m=(l+r)>>1;
        pushdown(i,l,r);
        assign(2*i,l,m,u,v,c);
        assign(2*i+1,m+1,r,u,v,c);
        tree[i]=tree[2*i]+tree[2*i+1];
    }
    Hash getHash(int i,int l,int r,int u,int v) {
        if (l>v || r<u || l>r || v<u) return (Hash());
        if (u<=l && r<=v) return (tree[i]);
        int m=(l+r)>>1;
        pushdown(i,l,r);
        Hash L=getHash(2*i,l,m,u,v);
        Hash R=getHash(2*i+1,m+1,r,u,v);
        return (L+R);
    }
    public:
    SegmentTree() {
        n=0;
    }
    SegmentTree(char s[],int n) {
        this->n=n;
        tree.assign(4*n+7,Hash());
        lazy.assign(4*n+7,-1);
        build(s,1,1,n);
    }
    void update(int l,int r,int c) {
        assign(1,1,n,l,r,c);
    }
    Hash getHash(int l,int r) {
        return (getHash(1,1,n,l,r));
    }
};
char s[MAX];
int n,m,k;
SegmentTree myit;
bool ok(int l,int r,int d) {
    if (d==r-l+1) return (true);
    if ((r-l+1)%d!=0) {
        int t=(r-l+1)%d;
        if (myit.getHash(l,l+t-1)!=myit.getHash(r-t+1,r)) return (false);
        r-=t;
    }
    Hash tmp=myit.getHash(l,l+d-1);
    REP(i,NMOD) tmp.val[i]=1LL*tmp.val[i]*sumPW[i][d][(r-l+1)/d-1]%mod[i];
    tmp.len*=(r-l+1)/d;
    return (tmp==myit.getHash(l,r));
}
void process(void) {
    scanf("%d%d%d",&n,&m,&k);
    scanf("%s",s+1);
    myit=SegmentTree(s,n);
    REP(love,m+k) {
        int t,l,r,c;
        scanf("%d%d%d%d",&t,&l,&r,&c);
        if (t==1) myit.update(l,r,c+'0');
        else printf("%s\n",ok(l,r,c)?yes:no);
    }
}
int main(void) {
    genHashMod();
    precount();
    process();
    return 0;
}