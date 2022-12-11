#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;
struct atom{
    int h,l,r;
}x[1010][1010];
int n,vx,vy,lim,w[1010][1010],num[10100000],a[10100000];
struct point{
    int x,y;
}A[1010000];
int compare(point k1,point k2){
    return w[k1.x][k1.y]<w[k2.x][k2.y];
}
void changeall(int k1,int k2){
    num[k1]=max(num[k1],k2); a[k1]=max(a[k1],k2);
}
void pushdown(int k){
    if (a[k]){
        changeall(k*2,a[k]); changeall(k*2+1,a[k]); a[k]=0;
    }
}
int findmin(int k1,int k2,int k3,int k4,int k5){
//  cout<<"find "<<k1<<" "<<k2<<" "<<k3<<" "<<k4<<" "<<k5<<" "<<num[k1]<<endl;
    if (k2>k5||k3<k4) return 2e9;
    if (k2>=k4&&k3<=k5) return num[k1];
    int mid=k2+k3>>1; pushdown(k1);
    return min(findmin(k1*2,k2,mid,k4,k5),findmin(k1*2+1,mid+1,k3,k4,k5));
}
void change(int k1,int k2,int k3,int k4,int k5,int k6){
    if (k2>k5||k3<k4) return;
    if (k2>=k4&&k3<=k5){changeall(k1,k6); return;}
    int mid=k2+k3>>1; pushdown(k1);
    change(k1*2,k2,mid,k4,k5,k6);
    change(k1*2+1,mid+1,k3,k4,k5,k6); num[k1]=min(num[k1*2],num[k1*2+1]);
}
int main(){
    scanf("%d%d%d",&n,&vx,&vy);
    for (int i=1;i<=n;i++) 
        for (int j=1;j<=n;j++) scanf("%d",&x[i][j].h);
    if (vy<0){
        vy=-vy;
        for (int i=1;i<=n;i++)
            for (int j=1;j<=n-j+1;j++) swap(x[i][j],x[i][n-j+1]);
    }
    if (vx<0){
        vx=-vx;
        for (int i=1;i<=n-i+1;i++)
            for (int j=1;j<=n;j++) swap(x[i][j],x[n-i+1][j]);
    }
    if (vx==0){
        lim=n+1;
        for (int i=1;i<=n;i++)
            for (int j=1;j<=n;j++){
                x[i][j].l=i; x[i][j].r=i;
            }
        int cnt=0;
    }else if (vy==0){
        lim=n+1;
        for (int i=1;i<=n;i++)
            for (int j=1;j<=n;j++){
                x[i][j].l=j; x[i][j].r=j;
            }
    }else {
        for (int i=0;i<=n;i++)
            for (int j=0;j<=n;j++) w[i][j]=j*vx-i*vy;
        int len=0;
        for (int i=0;i<=n;i++)
            for (int j=0;j<=n;j++) A[++len]=(point){i,j};
//      for (int i=0;i<=n;i++){
//          for (int j=0;j<=n;j++) cout<<w[i][j]<<" "; cout<<endl;} cout<<endl;
        sort(A+1,A+len+1,compare); lim=1; int now=w[A[1].x][A[1].y]; w[A[1].x][A[1].y]=1;
        for (int i=2;i<=len;i++){
            if (w[A[i].x][A[i].y]!=now){now=w[A[i].x][A[i].y]; lim++;}
            w[A[i].x][A[i].y]=lim;
        }
        for (int i=1;i<=n;i++)
            for (int j=1;j<=n;j++){
                x[i][j].r=w[i-1][j]-1; x[i][j].l=w[i][j-1];
            }
        
//      for (int i=0;i<=n;i++){
//          for (int j=0;j<=n;j++) cout<<w[i][j]<<" "; cout<<endl;} cout<<endl;
    }
    memset(A,0x00,sizeof A);
    int k1=0,k2=2,cnt=0;
    while(1){
        k1++; k2--;
        if (k1>n||k2==0){
            int k3=k1+k2+1; k1=max(1,k3-n); k2=k3-k1;
        }
        A[++cnt]=(point){k1,k2}; if (k1==n&&k2==n) break;
    }
//  for (int i=1;i<=n;i++){
//      for (int j=1;j<=n;j++) cout<<x[i][j].h<<" "; cout<<endl;}
    memset(num,0x00,sizeof num); memset(a,0x00,sizeof a);
    long long ans=0;
    for (int i=1;i<=n*n;i++){
        int k1=findmin(1,1,lim,x[A[i].x][A[i].y].l,x[A[i].x][A[i].y].r);
        if (k1<x[A[i].x][A[i].y].h){
            ans+=x[A[i].x][A[i].y].h-k1; change(1,1,lim,x[A[i].x][A[i].y].l,x[A[i].x][A[i].y].r,x[A[i].x][A[i].y].h); 
        //  cout<<"find "<<A[i].x<<" "<<A[i].y<<" "<<k1<<" "<<x[A[i].x][A[i].y].l<<" "<<x[A[i].x][A[i].y].r<<endl;
        //  cout<<"change "<<x[A[i].x][A[i].y].l<<" "<<x[A[i].x][A[i].y].r<<" "<<x[A[i].x][A[i].y].h<<endl;
        }
    }
    cout<<ans<<endl; return 0;
}