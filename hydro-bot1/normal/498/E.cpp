// Hydro submission #62b51ec802aab04f3f82c5f2@1656037064594
#include<bits/stdc++.h>
// #define int long long
using namespace std;
bool Begin;
const int max_n=133,mod=1000000007;
inline int read(){
    int x=0;bool w=0;char c=getchar();
    while(c<'0' || c>'9') w|=c=='-',c=getchar();
    while(c>='0' && c<='9') x=(x<<1)+(x<<3)+(c^48),c=getchar();
    return w?-x:x;
}
inline void write(int x){
    if(x<0) putchar('-'),x=-x;
    if(x>9) write(x/10);
    putchar(x%10^48);
}

int N;

struct Matrix{
    int a[max_n][max_n];
    inline void init(){
        memset(a,0,sizeof(a));
    }
    Matrix operator * (const Matrix &b) const{
        Matrix a=*this,res;
        res.init();
        for(register int i=0;i<=N;++i)
            for(register int j=0;j<=N;++j)
                for(register int k=0;k<=N;++k)
                    res.a[i][j]=(res.a[i][j]+1LL*a.a[i][k]*b.a[k][j]%mod)%mod;
        return res;
    }
}F,G,res;
inline Matrix Pow(Matrix A,int p){
    res.init();
    for(register int i=0;i<=N;++i)
        res.a[i][i]=1;
    while(p){
        if(p&1) res=res*A;
        A=A*A,p>>=1;
    }
    return res;
}

bool End;
#define File ""
signed main(){
    // #ifndef ONLINE_JUDGE
    // freopen(File ".in","r",stdin);
    // freopen(File ".out","w",stdout);
    // #endif
    // cerr<<"Memory : "<<(&Begin-&End)/1024.0/1024<<"\n";
    F.init();
    for(register int i=0;i<=N;++i)
        F.a[i][i]=1;
    for(N=2;N<=128;N<<=1){
        int x=read();
        if(!x) continue;
        G.init();
        for(register int i=0;i<N;++i)
            for(register int j=0;j<N;++j)
                for(register int k=0;(k<<1)<N;++k)
                    G.a[i][j]+=((i|j|k|(k<<1))==N-1);
        F=Pow(G,x)*F;
    }
    write(F.a[0][0]);
    return 0;
}