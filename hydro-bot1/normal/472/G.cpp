// Hydro submission #62c42e78c3a9fda56227f58f@1657024121203
#include<stdio.h>
#define ull unsigned long long
#pragma GCC target("popcnt")
const int max_n=200005,S=64;
bool Begin;
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

int n,m;
ull A[S][(max_n>>6)+S],B[S][(max_n>>6)+S],a[max_n],b[max_n];

#define File ""
bool End;
signed main(){
    // #ifndef ONLINE_JUDGE
    // freopen(File ".in","r",stdin);
    // freopen(File ".out","w",stdout);
    // #endif
    // cerr<<"Memory : "<<(&Begin-&End)/1024.0/1024<<"\n";
    char c=getchar();
    while(c!='0' && c!='1') c=getchar();
    while(c=='0' || c=='1') a[n++]=(c^48),c=getchar();
    while(c!='0' && c!='1') c=getchar();
    while(c=='0' || c=='1') b[m++]=(c^48),c=getchar();
    for(register int i=0;i<S;++i)
        for(register int j=i;j<n;j+=S)
            for(register int k=0;k<S;++k)
                A[i][j>>6]+=(1ull<<k)*a[j+k];
    for(register int i=0;i<S;++i)
        for(register int j=i;j<m;j+=S)
            for(register int k=0;k<S;++k)
                B[i][j>>6]+=(1ull<<k)*b[j+k];
    for(register int T=read();T;--T){
        int p1=read(),p2=read(),ln=read();
        int ps=0,a1=0,a2=0,a3=0,a4=0,a5=0,a6=0,a7=0,a8=0;
        ull *f1=A[p1&63]+(p1>>6),*f2=B[p2&63]+(p2>>6);
        for(;ps+511<ln;ps+=512,f1+=8,f2+=8){
            a1+=__builtin_popcountll(f1[0]^f2[0]),
            a2+=__builtin_popcountll(f1[1]^f2[1]),
            a3+=__builtin_popcountll(f1[2]^f2[2]),
            a4+=__builtin_popcountll(f1[3]^f2[3]),
            a5+=__builtin_popcountll(f1[4]^f2[4]),
            a6+=__builtin_popcountll(f1[5]^f2[5]),
            a7+=__builtin_popcountll(f1[6]^f2[6]),
            a8+=__builtin_popcountll(f1[7]^f2[7]);
        }
        for(;ps<ln;++ps)
            a1+=(a[p1+ps]^b[p2+ps]);
        write(a1+a2+a3+a4+a5+a6+a7+a8),putchar('\n');
    }
    return 0;
}