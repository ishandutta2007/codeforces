#include<bits/stdc++.h>
#define LL long long
using namespace std;
int const N=5e5+10,mo=998244353,inv3=332748118;
int n,n2,r[N];
LL g1[N],g2[N],h1[N],h2[N],H[N],G[N],F[N],f[N],i_2;
struct cpl{
    LL fi,se;
    cpl operator * (const cpl &b){
        return (cpl){(fi*b.fi%mo+i_2*se%mo*b.se%mo)%mo,(fi*b.se%mo+se*b.fi)%mo};
    }
}dq;
cpl qui1(cpl a,int b){
    cpl res=(cpl){1,1};
    while(b){
        if(b&1) res=res*a;
        b=b>>1;
        a=a*a;
    }
    return res;
}
LL qui(LL a,int b){
    LL res=1;
    while(b){
        if(b&1) res=res*a%mo;
        b=b>>1;
        a=a*a%mo;
    }
    return res;
}
inline bool check(LL a){
    return (qui(a,(mo-1)>>1)!=1);
}
LL sol0(LL x){
    LL y=rand()%mo,z;
    while(!y||!check((y*y+mo-x)%mo)) y=rand()%mo;
    i_2=(y*y+mo-x)%mo;
    dq=(cpl){y,1};
    dq=qui1(dq,(mo+1)>>1);
    return min(dq.fi,mo-dq.fi);
}
void get_(int n1){
    int l=0; n2=1;
    while(n2<n1) n2<<=1,l++;
    for(int i=1;i<n2;i++) r[i]=(r[i>>1]>>1)|((i&1)<<(l-1));
}
void NTT(LL *A,int op){
    for(int i=1;i<n2;i++) if(r[i]<i) swap(A[r[i]],A[i]);
    for(int mid=1;mid<n2;mid<<=1){
        LL Wn=qui((op==1?3:inv3),(mo-1)/(mid<<1));
        for(int j=0,R=(mid<<1);j<n2;j+=R){
            LL w=1;
            for(int k=0;k<mid;k++,w=w*Wn%mo){
                LL x=A[j+k],y=w*A[j+k+mid]%mo;
                A[j+k]=(x+y)%mo;
                A[j+k+mid]=(x+mo-y)%mo;
            }
        }
    }
    if(op<0){
        LL inv=qui(n2,mo-2);
        for(int i=0;i<n2;i++) A[i]=A[i]*inv%mo;
    }
}
void sol1(LL *A,LL *B,int n1){
    if(n1==1){
        B[0]=qui(A[0],mo-2); return;
    }
    sol1(A,B,(n1+1)>>1);
    get_(n1<<1);
    for(int i=0;i<n1;i++) h2[i]=A[i];
    for(int i=n1;i<n2;i++) h2[i]=0;
    NTT(B,1); NTT(h2,1);
    for(int i=0;i<n2;i++) B[i]=B[i]*(2-B[i]*h2[i]%mo+mo)%mo;
    NTT(B,-1);
    for(int i=n1;i<n2;i++) B[i]=0;
}
void sol2(LL *A,LL *B,int n1){//AB
    if(n1==1){
        B[0]=sol0(A[0]); return;
    }//G h1 
    sol2(A,B,(n1+1)>>1);//H B
    get_(n1<<1);
    for(int i=0;i<n2;i++) h1[i]=h2[i]=0;
    for(int i=0;i<n1;i++) H[i]=2ll*B[i]%mo;
    sol1(H,h1,n1);
    NTT(B,1);
    for(int i=0;i<n2;i++) B[i]=B[i]*B[i]%mo;
    NTT(B,-1);
    for(int i=0;i<n1;i++) B[i]=(A[i]+B[i])%mo;
    for(int i=n1;i<n2;i++) B[i]=0;
    NTT(B,1); NTT(h1,1);
    for(int i=0;i<n2;i++) B[i]=B[i]*h1[i]%mo;
    NTT(B,-1);
    for(int i=n1;i<n2;i++) B[i]=0;
}
int main(){//H h1 h2
    srand(time(0));
    int m;
    scanf("%d%d",&m,&n); n++;
    int x;// +1  +1+1
    for(int i=1;i<=m;i++) scanf("%d",&x),G[x]=1;
    for(int i=0;i<n;i++) G[i]=(mo-4*G[i])%mo;
    G[0]=1;
    sol2(G,F,n);//F
    get_(n<<1);
    for(int i=0;i<n2;i++) H[i]=h1[i]=h2[i]=0;
    F[0]=(F[0]+1)%mo;
    sol1(F,f,n);//f
    for(int i=0;i<n;i++) f[i]=(f[i]*2ll)%mo;
    for(int i=1;i<n;i++) printf("%lld\n",f[i]);
}