#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;
int a[110000],b[110000],n,dx,dy;
struct point{
    int x,y;
    void scan(){
        scanf("%d%d",&x,&y);
    }
}x[110000];
int main(){
    scanf("%d",&n);
    for (int i=1;i<=n;i++) x[i].scan();
    for (int i=1;i<=n;i++){a[i]=x[i].x; b[i]=x[i].y;}
    sort(a+1,a+n+1); sort(b+1,b+n+1); int mid=(n+1)/2;
    dx=a[mid+1]-a[mid]; dy=b[mid+1]-b[mid];
    if (n&1){
        dx=min(dx,a[mid]-a[mid-1]); dy=min(dy,b[mid]-b[mid-1]);
    }
    long long ans=0;
    int k1=0,k2=0,k3=0;
    for (int i=1;i<=n;i++){
        ans+=abs(a[mid]-a[i])+abs(b[mid]-b[i]);
        if (x[i].x>a[mid]&&x[i].y<=b[mid]) k1=1;
        if (x[i].x>a[mid]&&x[i].y>b[mid]) k2=1;
        if (x[i].x==a[mid]&&x[i].y==b[mid]) k3=1;
    }
    if (n%2==0||k3){
        if (k1&&k2) ans-=min(dx,dy);
    }
    cout<<ans*2<<endl; return 0;
}