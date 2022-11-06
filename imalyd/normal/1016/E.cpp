#include<bits/stdc++.h>
using namespace std;
int n,q;
double sy,a,b,l[200005],r[200005],sum[200005];
double inter(double s,double t,int i){
    double L=max(s,l[i]),R=min(t,r[i]);
    if(R<L)return 0;
    return R-L;
}
double solve(double s,double t){
    int ls=lower_bound(r+1,r+n+1,s)-r,rs=upper_bound(l+1,l+n+1,t)-l-1;
    //printf("%d %d\n",ls,rs);
    if(rs<ls)return 0;
    if(ls==rs)return inter(s,t,ls);
    return inter(s,t,ls)+inter(s,t,rs)+sum[rs-1]-sum[ls];
}
int main(){
    scanf("%lf%lf%lf%d",&sy,&a,&b,&n);
    for(int i=1;i<=n;i++)scanf("%lf%lf",&l[i],&r[i]),sum[i]=sum[i-1]+r[i]-l[i];
    scanf("%d",&q);
    while(q--){
        double x,y,s,t;
        scanf("%lf%lf",&x,&y);
        s=(sy*x-y*a)/(sy-y);
        t=(sy*x-y*b)/(sy-y);
        //printf("%lf %lf\n",s,t);
        printf("%lf\n",solve(s,t)/(t-s)*(b-a));
    }
    return 0;
}