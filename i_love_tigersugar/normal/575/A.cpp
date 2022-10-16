#include<bits/stdc++.h>
#define MAX   100100
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
#define ALL(v) (v).begin(),(v).end()
#define fi   first
#define se   second
using namespace std;
int mod;
struct Matrix {
    int m,n;
    int d[2][2];
    Matrix() {
        m=n=0;
        memset(d,0,sizeof d);
    }
    Matrix(int m,int n) {
        this->m=m;
        this->n=n;
        memset(d,0,sizeof d);
    }
    Matrix(int x1,int y1,int x2,int y2) {
        m=n=2;
        memset(d,0,sizeof d);
        d[0][0]=x1;
        d[0][1]=y1;
        d[1][0]=x2;
        d[1][1]=y2;
    }
    Matrix operator * (const Matrix &a) const {
        int x=m;
        int y=n;
        int z=a.n;
        Matrix res(x,z);
        REP(i,x) REP(j,y) REP(k,z) res.d[i][k]=(res.d[i][k]+1LL*d[i][j]*a.d[j][k])%mod;
        return (res);
    }
    Matrix operator ^ (long long k) const {
        Matrix res(n,n);
        Matrix mul=*this;
        REP(i,n) REP(j,n) res.d[i][j]=(i==j);
        while (k>0) {
            if (k&1) res=res*mul;
            mul=mul*mul;
            k>>=1;
        }
        return (res);
    }
};
int n,nDiff;
long long req;
pair<long long,int> diffVal[MAX];
int sameVal[MAX];
Matrix sameMat[MAX];
vector<long long> diffRound,diffPos;
vector<Matrix> diffMat;
int getVal(long long);
class SegmentTree {
    private:
    int n;
    vector<Matrix> tree;
    void build(int i,int l,int r) {
        if (l>r) return;
        if (l==r) {
            tree[i]=sameMat[l-1];
            return;
        }
        int m=(l+r)>>1;
        build(2*i,l,m);
        build(2*i+1,m+1,r);
        tree[i]=tree[2*i]*tree[2*i+1];
    }
    Matrix get(int i,int l,int r,int u,int v) const {
        if (l>v || r<u || l>r || v<u) return (Matrix(1,0,0,1));
        if (u<=l && r<=v) return (tree[i]);
        int m=(l+r)>>1;
        Matrix L=get(2*i,l,m,u,v);
        Matrix R=get(2*i+1,m+1,r,u,v);
        return (L*R);
    }
    public:
    SegmentTree() {
        n=0;
    }
    SegmentTree(int n) {
        this->n=n;
        tree.assign(4*n+7,Matrix());
        build(1,1,n);
    }
    Matrix get(int l,int r) const {
        return (get(1,1,n,l,r));
    }
};
SegmentTree myit;
void init(void) {
    cin>>req>>mod>>n;
    REP(i,n) cin>>sameVal[i];
    cin>>nDiff;
    REP(i,nDiff) cin>>diffVal[i].fi>>diffVal[i].se;
    sort(diffVal,diffVal+nDiff);
    REP(i,n) sameVal[i]%=mod;
    REP(i,nDiff) diffVal[i].se%=mod;
}
int getVal(long long pos) {
    int id=lower_bound(diffVal,diffVal+nDiff,make_pair(pos,-1))-diffVal;
    if (id<nDiff && diffVal[id].fi==pos) return (diffVal[id].se);
    return (sameVal[pos%n]);
}
void prepare(void) {
    REP(i,n) sameMat[i]=Matrix(0,sameVal[i%n],1,sameVal[(i+1)%n]);
    REP(i,nDiff) REP(j,2) {
        diffPos.push_back(diffVal[i].fi-j);
        diffRound.push_back(diffPos.back()/n);
    }
    sort(ALL(diffPos));
    diffPos.resize(unique(ALL(diffPos))-diffPos.begin());
    sort(ALL(diffRound));
    diffRound.resize(unique(ALL(diffRound))-diffRound.begin());
    FORE(it,diffPos) diffMat.push_back(Matrix(0,getVal(*it),1,getVal(*it+1)));
    myit=SegmentTree(n);
}
Matrix roundProduct(long long k) {
    if (!binary_search(ALL(diffRound),k)) return (myit.get(1,n));
    vector<int> pos;
    pos.push_back(-1);
    int id=lower_bound(ALL(diffPos),k*n)-diffPos.begin();
    while (id<diffPos.size() && diffPos[id]<(k+1)*n) {
        pos.push_back(diffPos[id]-k*n);
        id++;
    }
    pos.push_back(n);
    Matrix res(1,0,0,1);
    REP(i,(int)pos.size()-1) {
        if (i>0) {
            int id=lower_bound(ALL(diffPos),k*n+pos[i])-diffPos.begin();
            res=res*diffMat[id];
        }
        if (pos[i]+1<pos[i+1]) res=res*myit.get(pos[i]+2,pos[i+1]);
    }
    return (res);
}
int getValue(long long req) {
    if (req<2) return (req%mod);
    req--;
    vector<long long> round;
    round.push_back(-1);
    FORE(it,diffRound) if (*it<req/n) round.push_back(*it);
    round.push_back(req/n);
    Matrix res(1,0,0,1);
    REP(i,(int)round.size()-1) {
        if (i>0) res=res*roundProduct(round[i]);
        if (round[i]+1<round[i+1]) res=res*(myit.get(1,n)^(round[i+1]-round[i]-1));
    }
    for (long long i=req-req%n;i<=req;i=i+1) res=res*Matrix(0,getVal(i),1,getVal(i+1));
    Matrix sta(1,2);
    REP(i,2) sta.d[0][i]=i;
    res=sta*res;
    return (res.d[0][0]%mod);
}
void process(void) {
    cout<<getValue(req)<<endl;
}
int main(void) {
#ifdef SKY
    freopen("tmp.txt","r",stdin);
#endif // SKY
    ios::sync_with_stdio(false);cin.tie(NULL);
    init();
    prepare();
    process();
    return 0;
}