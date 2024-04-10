#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;
struct point{
    int x,y;
    void scan(){
        scanf("%d%d",&x,&y);
    }
}x[110000];
int n,L,R,U,D;
long double num[2100000];
long double *A;
long double get(point k1,point k2,int k3){
    if (k1.x==k2.x) return k2.y;
    return (long double)(k3-k1.x)/(long double)(k2.x-k1.x)*(k2.y-k1.y)+k1.y;
}
int pre(int k){
    return (k-2+n)%n+1;
}
int next(int k){
    return k%n+1;
}
int main(){
    scanf("%d",&n); 
    for (int i=1;i<=n;i++) x[i].scan();
    A=num+1005000;
    L=1e7; R=-1e7;
    for (int i=1;i<=n;i++){
        L=min(L,x[i].x); R=max(R,x[i].x);
    }
    int l,r;
    for (int i=1;i<=n;i++) if (x[i].x==L){l=i; r=i; break;}
    for (int i=L;i<=R;i++){
        while (x[l].x<=i&&x[l].x!=R) l=pre(l);
        while (x[r].x<=i&&x[r].x!=R) r=next(r);
        long double k3=get(x[l],x[next(l)],i),k4=get(x[r],x[pre(r)],i); if (k3>k4) swap(k3,k4);
        int k1=floor(k3-1e-7)+1,k2=floor(k4+1e-7);
        A[i]=k2-k1+1;
    }
//  for (int i=L;i<=R;i++) cout<<(double)A[i]<<" "; cout<<endl;
    long double ans=0,tot=0,sum=0;
    for (int i=L;i<=R;i++){tot+=A[i]; sum+=A[i]*i;}
    for (int i=L;i<=R;i++){
        ans+=-sum*2*A[i]*i+A[i]*(A[i]+1)*(long double)i*i+(long double)i*i*A[i]*(tot-1); sum-=A[i]*i;
    }
//  cout<<(double)ans<<endl;
    memset(num,0x00,sizeof num);
    for (int i=1;i<=n;i++) swap(x[i].x,x[i].y);
    L=1e7; R=-1e7;
    for (int i=1;i<=n;i++){
        L=min(L,x[i].x); R=max(R,x[i].x);
    }
    for (int i=1;i<=n;i++) if (x[i].x==L){l=i; r=i; break;}
    for (int i=L;i<=R;i++){
        while (x[l].x<=i&&x[l].x!=R) l=pre(l);
        while (x[r].x<=i&&x[r].x!=R) r=next(r);
        long double k3=get(x[l],x[next(l)],i),k4=get(x[r],x[pre(r)],i); if (k3>k4) swap(k3,k4);
        int k1=floor(k3-1e-7)+1,k2=floor(k4+1e-7);
        A[i]=k2-k1+1;
    }
//  for (int i=L;i<=R;i++) cout<<(double)A[i]<<" "; cout<<endl;
    tot=0,sum=0;
    for (int i=L;i<=R;i++){tot+=A[i]; sum+=A[i]*i;}
    for (int i=L;i<=R;i++){
        ans+=-sum*2*A[i]*i+A[i]*(A[i]+1)*(long double)i*i+(long double)i*i*A[i]*(tot-1); sum-=A[i]*i;
    }
//  cout<<(double)tot<<endl;
    printf("%.11lf\n",(double)(ans/tot/(tot-1)));
    return 0;
}