#include<bits/stdc++.h>
#define MAX   300300
#define NMOD   1
#define FOR(i,a,b) for (int i=(a);i<=(b);i=i+1)
#define REP(i,n) for (int i=0;i<(n);i=i+1)
using namespace std;
const int mod[]={(int)1e9+2277,(int)1e9+5277,(int)1e9+8277,(int)1e9+9277};
int pw[2][MAX];
class IT {
    private:
    struct hash {
        int code[2],len;
        hash() {
            REP(i,NMOD) code[i]=0;
            len=0;
        }
        hash(int l) {
            REP(i,NMOD) code[i]=0;
            len=l;
        }
        hash operator + (const hash &x) const {
            hash res;
            res.len=len+x.len;
            REP(i,NMOD) res.code[i]=(1LL*code[i]*pw[i][x.len]+x.code[i])%mod[i];
            return (res);
        }
        bool operator == (const hash &x) const {
            REP(i,NMOD) if (code[i]!=x.code[i]) return (false);
            return (len==x.len);
        }
    };
    vector<hash> fh,bh;
    int n;
    void build(int i,int l,int r) {
        fh[i]=bh[i]=hash(r-l+1);
        if (l==r) return;
        int m=(l+r)>>1;
        build(2*i,l,m);
        build(2*i+1,m+1,r);
    }
    void update(int i,int l,int r,int u) {
        if (l>r) return;
        if (l==r) {
            REP(j,NMOD) {
                fh[i].code[j]=1;
                bh[i].code[j]=1;
            }
            return;
        }
        int m=(l+r)>>1;
        if (u>m) update(2*i+1,m+1,r,u);
        else update(2*i,l,m,u);
        fh[i]=fh[2*i]+fh[2*i+1];
        bh[i]=bh[2*i+1]+bh[2*i];
    }
    hash get(int i,int l,int r,int u,int v,bool mode) {
        if (l>v) return (hash());
        if (r<u) return (hash());
        if (l>r) return (hash());
        if (v<u) return (hash());
        if (u<=l && r<=v) return (mode?bh[i]:fh[i]);
        int m=(l+r)>>1;
        hash L=get(2*i,l,m,u,v,mode);
        hash R=get(2*i+1,m+1,r,u,v,mode);
        return (mode?R+L:L+R);
    }
    public:
    IT() {
        n=0;
    }
    IT(int n) {
        this->n=n;
        fh.assign(4*n+7,hash());
        bh.assign(4*n+7,hash());
        build(1,1,n);
    }
    void update(int u) {
        update(1,1,n,u);
    }
    bool palin(int u) {
        int L=1;
        int R=n;
        if (u-L>R-u) L=2*u-R;
        if (R-u>u-L) R=2*u-L;
        return (get(1,1,n,L,u-1,false)==get(1,1,n,u+1,R,true));
    }
};
int a[MAX],n;
IT myit;
void init(void) {
    scanf("%d",&n);
    REP(j,NMOD) {
        pw[j][0]=1;
        FOR(i,1,n) pw[j][i]=(pw[j][i-1]<<1)%mod[j];
    }
    FOR(i,1,n) scanf("%d",&a[i]);
}
void process(void) {
    myit=IT(n);
    FOR(i,1,n) {
        myit.update(a[i]);
        if (!myit.palin(a[i])) {
            printf("YES");
            return;
        }
    }
    printf("NO");
}
int main(void) {
    init();
    process();
    return 0;
}