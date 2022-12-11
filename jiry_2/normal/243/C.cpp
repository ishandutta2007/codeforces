#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<queue>
using namespace std;
struct point{
    int x,y;
}x[3000];
int n,len,fx[3000],fy[3000],m,a[3000],pd[3000][3000],gox[4]={1,-1,0,0},goy[4]={0,0,1,-1};
char getin(){
    char ch=getchar(); while (ch<'A'||ch>'Z') ch=getchar(); return ch;
}
queue<int>Q;
int main(){
    scanf("%d",&n); len=1; x[len]=(point){0,0};
    for (int i=1;i<=n;i++){
        char ch=getin(); len++; x[len]=x[len-1]; int k; scanf("%d",&k);
        if (ch=='U') x[len].y+=k; else if (ch=='D') x[len].y-=k; else if (ch=='L') x[len].x-=k; else x[len].x+=k;
    }
    for (int i=1;i<=len;i++){a[i*2-1]=x[i].x; a[i*2]=x[i].x+1;} sort(a+1,a+len*2+1);
    n=1; fx[1]=a[1];
    for (int i=2;i<=len*2;i++) if (a[i]!=a[i-1]) fx[++n]=a[i];
    for (int i=1;i<=len;i++){a[i*2-1]=x[i].y; a[i*2]=x[i].y+1;} sort(a+1,a+len*2+1);
    m=1; fy[1]=a[1];
    for (int i=2;i<=len*2;i++) if (a[i]!=a[i-1]) fy[++m]=a[i];
    for (int i=1;i<=len;i++){
        for (int j=1;j<=n;j++) if (fx[j]==x[i].x){x[i].x=j+1; break;}
        for (int j=1;j<=m;j++) if (fy[j]==x[i].y){x[i].y=j+1; break;}
    }
    Q.push(1); pd[1][1]=1;
    for (int i=1;i<len;i++)
        if (x[i].x==x[i+1].x){
            for (int j=min(x[i].y,x[i+1].y);j<=max(x[i].y,x[i+1].y);j++) pd[x[i].x][j]=2;
        } else for (int j=min(x[i].x,x[i+1].x);j<=max(x[i].x,x[i+1].x);j++) pd[j][x[i].y]=2; n+=2; m+=2;
    while (!Q.empty()){
        int k1=Q.front(),k2=(k1-1)%m+1; k1=(k1-k2)/m+1;
        for (int i=0;i<4;i++){
            int k3=k1+gox[i],k4=k2+goy[i];
            if (k3>0&&k3<=n&&k4>0&&k4<=m&&pd[k3][k4]==0) {Q.push((k3-1)*m+k4); pd[k3][k4]=1;}
        }
        Q.pop();
    }
    //for (int i=1;i<=len;i++) cout<<x[i].x<<" "<<x[i].y<<endl; cout<<endl;
    //for (int i=1;i<=n;i++){ for (int j=1;j<=m;j++) cout<<pd[i][j]<<" "; cout<<endl;}
    long long ans=0;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++) if (pd[i][j]!=1) ans+=1ll*(fx[i]-fx[i-1])*(fy[j]-fy[j-1]); cout<<ans<<endl;
}