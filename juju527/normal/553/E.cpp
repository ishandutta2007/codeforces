#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=55,maxm=105,maxt=20005;
const double pai=acos(-1.0);
int n,m,t,x;
int a[maxm],b[maxm],c[maxm];
ll d[maxn][maxn];
vector<int>out[maxn];
struct C{
    double a,b;
    void clear(){a=b=0;return ;}
    C operator +(C x)const{return (C){a+x.a,b+x.b};}
    C operator -(C x)const{return (C){a-x.a,b-x.b};}
    C operator *(C x)const{return (C){a*x.a-b*x.b,a*x.b+b*x.a};}
};
int rev[8*maxt];
double p[maxm][maxt];
double g[maxm][maxt];
double f[maxn][2*maxt];
int read(){
    int x=0,y=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')y=-1;ch=getchar();}
    while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*y;
}
void FFT(C *f,int lim,int opt){
    for(int i=0;i<lim;i++)if(i<rev[i])swap(f[i],f[rev[i]]);
    for(int mid=1;mid<lim;mid<<=1){
        C wn=(C){cos(pai/mid),opt*sin(pai/mid)};
        for(int j=0;j<lim;j+=(mid<<1)){
            C w=(C){1,0};
            for(int k=0;k<mid;k++,w=w*wn){
                C u=f[j+k],v=w*f[j+k+mid];
                f[j+k]=u+v;
                f[j+k+mid]=u-v;
            }
        }
    }
    if(opt==1)return ;
    for(int i=0;i<lim;i++)f[i].a/=lim;
    return ;
}
C A[8*maxt],B[8*maxt];
void cdq(int l,int r){
    if(l==r){
        for(int i=1;i<n;i++){
            double res=1e18;
            for(int j=0;j<out[i].size();j++){
                int e=out[i][j];
                res=min(res,g[e][l]+c[e]);
            }
            f[i][l]=res;
        }
        f[n][l]=0;
        return ;
    }
    int mid=l+((r-l)>>1);
    if(mid==t)for(int i=t+1;i<=2*t;i++)for(int j=1;j<=n;j++)f[j][i]=d[j][n]+x;
    else cdq(mid+1,r);
    int lim=1,k=0,l1=max(t-(r-l),0);
    while(lim<min(r-l+1,t)+r-mid)lim<<=1,k++;
    for(int i=1;i<lim;i++)rev[i]=rev[i>>1]>>1|((i&1)<<(k-1));
    for(int i=1;i<=m;i++){
        for(int j=0;j<lim;j++)A[j].clear(),B[j].clear();
        for(int j=mid+1;j<=r;j++)A[j-mid-1].a=f[b[i]][j];
        for(int j=l1;j<=t;j++)B[j-l1].a=p[i][j];
        FFT(A,lim,1);FFT(B,lim,1);
        for(int j=0;j<lim;j++)A[j]=A[j]*B[j];
        FFT(A,lim,-1);
        for(int j=0;j<=r-mid-1+t-l1;j++){
            if(j+mid+1+l1-t>=l&&j+mid+1+l1-t<=mid)
                g[i][j+mid+1+l1-t]+=A[j].a;
        }
    }
    cdq(l,mid);
    return ;
}
int main(){
    n=read();m=read();t=read();x=read();
    memset(d,0x3f,sizeof(d));for(int i=1;i<=n;i++)d[i][i]=0;
    for(int i=1;i<=m;i++){
        a[i]=read();b[i]=read();c[i]=read();
        out[a[i]].push_back(i);
        for(int j=1;j<=t;j++)p[i][t-j]=1.0*read()/100000;
        d[a[i]][b[i]]=min(d[a[i]][b[i]],1ll*c[i]);
    }
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
    cdq(0,2*t);
    printf("%.9lf\n",f[1][0]);
    return 0;
}