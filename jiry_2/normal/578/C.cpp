#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
long long a[210000];
long double b[210000];
int n;
long double get(long double k){
    for (int i=1;i<=n;i++) b[i]=a[i]-k*i;
    long double k1=0,k2=0,ans=0; 
    for (int i=1;i<=n;i++){
        ans=max(ans,max(abs(b[i]-k1),abs(b[i]-k2)));
        k1=max(k1,b[i]); k2=min(k2,b[i]);
    }
    return ans;
}
int main(){
    scanf("%d",&n);
    for (int i=1;i<=n;i++) scanf("%I64d",&a[i]);
    for (int i=1;i<=n;i++) a[i]+=a[i-1];
    long double l=-10000,r=10000;
    for (int i=1;i<=150;i++){
        double mid1=l+(r-l)/3.0,mid2=r-(r-l)/3.0;
    //  cout<<(double)mid1<<" "<<(double)mid2<<" "<<(double)get(mid1)<<" "<<(double)get(mid2)<<endl;
        if (get(mid1)>get(mid2)) l=mid1; else r=mid2;
    }
    printf("%.11lf\n",(double)(get((l+r)/2.0)));
    return 0;
}