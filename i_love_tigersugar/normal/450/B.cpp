#include<bits/stdc++.h>
#define FOR(i,a,b) for (int i=(a);i<=(b);i=i+1)
#define REP(i,n) for (int i=0;i<(n);i=i+1)
const int mod=(int)1e9+7;
struct matrix {
    int m,n;
    int d[2][2];
    matrix() {
        memset(d,0,sizeof d);
    }
    matrix(int m,int n) {
        this->m=m;
        this->n=n;
        memset(d,0,sizeof d);
    }
    matrix operator * (const matrix &a) const {
        int x=m;
        int y=n;
        int z=a.n;
        matrix res=matrix(x,z);
        REP(i,x) REP(j,z) REP(k,y) res.d[i][j]=(res.d[i][j]+1LL*d[i][k]*a.d[k][j])%mod;
        return (res);
    }
    matrix operator ^ (int k) const {
        matrix res=matrix(m,n);
        matrix mul=*this;
        REP(i,m) REP(j,n) res.d[i][j]=i==j;
        while (k>0) {
            if (k&1) res=res*mul;
            mul=mul*mul;
            k=k>>1;
        }
        return (res);
    }
};
void process(void) {
    int x,y,k;
    scanf("%d%d%d",&x,&y,&k);
    x=(x%mod+mod)%mod;
    y=(y%mod+mod)%mod;
    matrix fst=matrix(1,2);
    fst.d[0][0]=x;
    fst.d[0][1]=y;
    matrix mul=matrix(2,2);
    mul.d[0][0]=0;
    mul.d[0][1]=mod-1;
    mul.d[1][0]=1;
    mul.d[1][1]=1;
    fst=fst*(mul^(k-1));
    printf("%d",fst.d[0][0]);
}
int main(void) {
    process();
    return 0;
}