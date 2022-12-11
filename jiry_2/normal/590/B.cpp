#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
struct atom{
    int x,y;
    void scan(){
        scanf("%d%d",&x,&y);
    }
}A,B,C;
int lim,t;
double dis(double k1,double k2,double k3,double k4){
    return sqrt((k1-k3)*(k1-k3)+(k2-k4)*(k2-k4));
}
int main(){
    int k1,k2,k3,k4; scanf("%d%d%d%d",&k1,&k2,&k3,&k4);
    scanf("%d%d",&lim,&t);
    A=(atom){k3-k1,k4-k2};
    B.scan(); C.scan();
    double l=0,r=t,ans=-1;
    for (int i=1;i<=60;i++){
        double mid=(l+r)/2.0;
        if (dis(A.x,A.y,B.x*mid,B.y*mid)<=mid*lim){
            ans=mid; r=mid;
        } else l=mid;
    }
    if (ans>0){
        printf("%.11lf\n",ans); return 0;
    }
    l=t,r=1e9;
    for (int i=1;i<=100;i++){
        double mid=(l+r)/2.0;
        if (dis(B.x*t,B.y*t,A.x-C.x*(mid-t),A.y-C.y*(mid-t))<=mid*lim){
            ans=mid; r=mid;
        } else l=mid;
    }
    printf("%.11lf\n",ans);
}