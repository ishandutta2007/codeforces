#include<bits/stdc++.h>
using namespace std;
int n,k,m;
double sum=0,res=0,a[100005];
int main()
{
    scanf("%d%d%d",&n,&k,&m);
    for(int i=1;i<=n;i++) scanf("%lf",&a[i]),sum+=a[i];
    sort(a+1,a+1+n);
    int t=min(n-1,m);
    double ans=0;
    for(int i=0;i<=t;i++)
        res+=a[i],ans=max(ans,(sum-res+max(0,min(m-i,(n-i)*k)))/(n-i));
    printf("%.10f",ans);
}