#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
int a,b;
const double lim=1e18;
int main(){
    scanf("%d%d",&a,&b);
    if (a==b){
        printf("%.11lf\n",(double)a); return 0;
    }
    if (a<b){
        printf("-1\n"); return 0;
    }
    int k1=a+b;
    double ans=lim;
    int k2=trunc((double)(a+b)/(double)b/2.0+1e-9);
    if (k2){
        double x=(double)(a+b)/(double)(k2*2);
        ans=min(ans,x);
    }
    if (a>b){
        k2=trunc((double)(a-b)/(double)b/2.0+1e-9);
        if (k2){
            double x=(double)(a-b)/(double)(k2*2);
            ans=min(ans,x);
        }
    }
    if (ans>a) printf("-1\n"); else printf("%.11lf\n",ans);
    return 0;
}