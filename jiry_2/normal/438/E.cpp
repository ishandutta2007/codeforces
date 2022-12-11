#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
const int mo=998244353,g=3;
int n,G[30],nG[30],two[30],m;
int fir[4100000],rev[410000],A[410000],B[410000],root[410000],C[410000],H[10000010];
int quick(int k1,int k2){
    int k3=1;
    while (k2){
        if (k2&1) k3=1ll*k3*k1%mo; k1=1ll*k1*k1%mo; k2=k2/2;
    }
    return k3;
}
void fft(int *x,int n,int fl=1){
    for (int i=(n>>1),j=1;j<n;j++){
        if (i<j) swap(x[i],x[j]);
        int k;
        for (k=(n>>1);i&k;i^=k,k>>=1); i^=k;
    }
    int now=0;
    for (int m=2;m<=n;m<<=1){
        int w; now++; if (fl==1) w=G[now]; else w=nG[now];
        for (int i=0;i<n;i+=m){
            int cur=1;
            for (int j=i;j<i+(m>>1);j++){
                int u=x[j],v=1ll*x[j+(m>>1)]*cur%mo;
                x[j]=(u+v)%mo; x[j+(m>>1)]=(u-v+mo)%mo;
                cur=1ll*cur*w%mo;
            }
        }
    }
}
void getrev(int n){
    if (n==1){
        rev[0]=quick(fir[0],mo-2); return;
    }
    getrev((n+1)>>1); int len=1;
    while ((1<<len)<=(n<<1)) len++;
    for (int i=((n+1)>>1);i<(1<<len);i++) rev[i]=0;
    for (int i=0;i<n;i++) A[i]=fir[i];
    for (int i=n;i<(1<<len);i++) A[i]=0;
    fft(rev,1<<len); fft(A,1<<len);
    for (int i=0;i<(1<<len);i++) A[i]=(2-1ll*A[i]*rev[i]%mo+mo)%mo;
    for (int i=0;i<(1<<len);i++) rev[i]=1ll*rev[i]*A[i]%mo;
    fft(rev,1<<len,-1);
    for (int i=0;i<n;i++) rev[i]=1ll*rev[i]*two[len]%mo;
    for (int i=n;i<(1<<len);i++) rev[i]=0;
}
void getroot(int n){
    if (n==1){
        root[0]=1; return;
    }
    getroot((n+1)>>1); int len=1,m=((n+1)>>1),n2=two[1];
    while ((1<<len)<=(n<<1)) len++;
    for (int i=0;i<(1<<len);i++){rev[i]=0; fir[i]=0;}
    for (int i=0;i<m;i++) fir[i]=root[i]; 
/*  cout<<"solve"<<n<<endl;
    cout<<"fir "<<endl;
    for (int i=0;i<n;i++) cout<<fir[i]<<" "; cout<<endl;*/
    getrev(n);
/*  cout<<"rev "<<endl;
    for (int i=0;i<n;i++) cout<<rev[i]<<" "; cout<<endl;*/
    for (int i=0;i<(1<<len);i++) A[i]=0;
    for (int i=0;i<n;i++) A[i]=C[i];
    fft(fir,1<<len); fft(A,1<<len); fft(rev,1<<len);
//  for (int i=0;i<n;i++) A[i]=(1ll*fir[i]*n2%mo+1ll*A[i]*rev[i]%mo*n2%mo)%mo;
    for (int i=0;i<(1<<len);i++) A[i]=(1ll*fir[i]*n2%mo+1ll*A[i]*rev[i]%mo*n2%mo)%mo;
    fft(A,1<<len,-1);
    for (int i=0;i<n;i++) root[i]=1ll*A[i]*two[len]%mo;
    for (int i=n;i<(1<<len);i++) root[i]=0;
/*  cout<<"require"<<endl;
    for (int i=0;i<n;i++) cout<<C[i]<<" "; cout<<endl;
    cout<<"root"<<endl;
    for (int i=0;i<n;i++) cout<<root[i]<<" "; cout<<endl;*/
}
int main(){
    scanf("%d%d",&n,&m);
    int now=(mo-1)/2,ng=quick(g,mo-2),len=0;
    while (now%2==0){
        len++; G[len]=quick(g,now); nG[len]=quick(ng,now); two[len]=quick(1<<len,mo-2); now>>=1;
    }
    for (int i=1;i<=n;i++){
        int k1; scanf("%d",&k1); C[k1]=1;
    }
    for (int i=1;i<=m;i++) C[i]=(-4*C[i]+mo)%mo; C[0]=1;
    getroot(m+1);
    for (int i=0;i<=m;i++) fir[i]=root[i]; fir[0]++; getrev(m+1);
    for (int i=1;i<=m;i++) printf("%d\n",1ll*rev[i]*2%mo);
    return 0;
}