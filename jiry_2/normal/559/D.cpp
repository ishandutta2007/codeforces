#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
struct point{
    int x,y;
    void scan(){
        scanf("%d%d",&x,&y);
    }
}x[110000];
int n,lim=60;
long double two[1100];
long long cross(point k1,point k2){
    return 1ll*k1.x*k2.y-1ll*k1.y*k2.x;
}
int gcd(int k1,int k2){
    if (k2==0) return k1; return gcd(k2,k1%k2);
}
void force(){
    long double tot=1;
    for (int i=1;i<=n;i++) tot=tot*2;
    tot-=1+n+n*(n-1)/2;
    two[0]=1; for (int i=1;i<=n;i++) two[i]=two[i-1]*2;
    long double ans=0;
    for (int i=1;i<=n;i++){
        long long pre=0,now=1; int k1=i,k2=i%n+1,rem=n-2;
        for (int j=1;j<n;j++){
            pre+=cross(x[k1],x[k2]); 
            int k3=gcd(abs(x[k1].x-x[k2].x),abs(x[k1].y-x[k2].y));
            now+=k3;
            k3=gcd(abs(x[k2].x-x[i].x),abs(x[k2].y-x[i].y));
            long long k4=pre+cross(x[k2],x[i]),k5=now+k3-1;
        //  cout<<i<<" "<<j<<" "<<k4<<" "<<k5<<endl;
            k4=(k4+k5)/2; if (j==1) k4=k3;
            if (i==1&&j==n-1){
                ans+=k4+1;
            } else if (j<n-1){
        //      cout<<i<<" "<<j<<" "<<k4<<" "<<(double)(two[rem]-1)<<" "<<(double)tot<<endl;
                ans-=(k4)*(two[rem]-1)/tot;
            }
            k1=(k1%n+1); k2=k2%n+1; rem--;
        }
    }
    printf("%.11lf\n",(double)ans);
}
int main(){
    scanf("%d",&n);
    for (int i=1;i<=n;i++) x[i].scan();
    if (n<=1000){
        force(); return 0;
    }
    two[1]=0.25; for (int i=2;i<=lim;i++) two[i]=two[i-1]/2.0;
    long double ans=0;
    for (int i=1;i<=n;i++){
        long long pre=0,now=1; int k1=i,k2=i%n+1,rem=n-2;
        int r=lim; if (i==1) r=n;
        for (int j=1;j<r;j++){
            pre+=cross(x[k1],x[k2]); 
            int k3=gcd(abs(x[k1].x-x[k2].x),abs(x[k1].y-x[k2].y));
            now+=k3;
            k3=gcd(abs(x[k2].x-x[i].x),abs(x[k2].y-x[i].y));
            long long k4=pre+cross(x[k2],x[i]),k5=now+k3-1;
        //  cout<<i<<" "<<j<<" "<<k4<<" "<<k5<<endl;
            k4=(k4+k5)/2; if (j==1) k4=k3;
            if (i==1&&j==n-1){
                ans+=k4+1;
            } else if (j<lim){
        //      cout<<i<<" "<<j<<" "<<k4<<" "<<(double)(two[rem]-1)<<" "<<(double)tot<<endl;
                ans-=(k4)*two[j];
            }
            k1=(k1%n+1); k2=k2%n+1; rem--;
        }
    }
    printf("%.11lf\n",(double)ans);
}