#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m,len;
long long a[1000100],b[1000100];
const double pi = 3.1415926535897932384626433832795028841971693993751058209749445923078;
struct atom{
    double a,b;
}A[2500000];
atom operator + (const atom k1,const atom k2){
    return (atom){k1.a+k2.a,k1.b+k2.b};
}
atom operator - (const atom k1,const atom k2){
    return (atom){k1.a-k2.a,k1.b-k2.b};
}
atom operator * (const atom k1,const atom k2){
    return (atom){k1.a*k2.a-k1.b*k2.b,k1.a*k2.b+k1.b*k2.a};
}
void dft(atom *a,int n,int fl=1){
    for (int i=n>>1,j=1;j<n;j++){
        if(i<j)swap(a[i],a[j]);
        int k;for (k=n>>1;i&k;i^=k,k>>=1);i^=k;
    }
    for (int m=2;m<=n;m<<=1){
        atom wm=(atom){cos(fl*2*pi/m),sin(fl*2*pi/m)};
        for (int i=0;i<n;i+=m){
            atom w=(atom){1,0};
            for (int j=i;j<i+(m>>1);j++,w=w*wm){
                atom u=a[j],v=w*a[j+(m>>1)];
                a[j]=u+v;
                a[j+(m>>1)]=u-v;
            }
        }
    }
    if(fl==-1)for (int i=0;i<n;i++)a[i].a/=n;
}
int main(){
    memset(A,0x00,sizeof A); memset(a,0x00,sizeof a); memset(b,0x00,sizeof b); len=0;
    scanf("%d%d",&n,&m); for (int i=1;i<=n;i++){int k1; scanf("%d",&k1); a[k1]=1;} while (2*m>=(1<<len)) len++;
    for (int i=1;i<=m;i++) A[i]=(atom){a[i],0}; dft(A,1<<len,1);
    for (int i=0;i<=(1<<len);i++) A[i]=A[i]*A[i]; dft(A,1<<len,-1); int flag=0;
    for (int i=1;i<=m;i++) if (A[i].a>1e-5&&a[i]==0){flag=1; break;} if (flag){cout<<"NO"<<endl; return 0;} int ans=0;
    cout<<"YES"<<endl; for (int i=1;i<=m;i++) if (A[i].a<1e-5&&a[i]) ans++; cout<<ans<<endl;
    for (int i=1;i<=m;i++) if (A[i].a<1e-5&&a[i]) printf("%d ",i); cout<<endl; return 0;
}