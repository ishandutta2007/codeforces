//Problem D
#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int n;
double a[N],b[N],c[N],x[N],y[N];
double chk(double x){
    double s=0;
    for(int i=1;i<=n;i++)s=max(s,a[i]*x*x+b[i]*x+c[i]);//printf("chk %lf %lf\n",x,s);
    return s;
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%lf%lf",&x[i],&y[i]);
    if(y[1]<0){for(int i=1;i<=n;i++)y[i]=-y[i];}
    for(int i=2;i<=n;i++)if(y[i]<0){printf("-1");return 0;}
    for(int i=1;i<=n;i++)a[i]=0.5/y[i],b[i]=-x[i]/y[i],c[i]=0.5*(x[i]*x[i]+y[i]*y[i])/y[i];
    //for(int i=1;i<=n;i++)printf("%lf %lf %lf\n",a[i],b[i],c[i]);
    double l=-10000000,r=10000000;
    while(l+0.00000001<r){
        double m1=(l+l+r)/3,m2=(l+r+r)/3;
        if(chk(m1)<chk(m2))r=m2;else l=m1;
    }//printf("%lf\n",(l+r)/2);
    printf("%.10lf",chk((l+r)/2));
    return 0;
}