#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<cstdio>
using namespace std;
struct point{
    int x,y;
}f[3100][6100];
int n,m,q,gox[8]={1,1,1,-1,-1,-1,0,0},goy[8]={1,0,-1,1,0,-1,1,-1},pd[3100][6100];
int operator == (const point k1,const point k2){
    return k1.x==k2.x&&k1.y==k2.y;
}
point operator + (const point k1,const int k2){
    return (point){k1.x+gox[k2],k1.y+goy[k2]};
}
point findfather(point k1){
    if (f[k1.x][k1.y]==k1) return k1;
    f[k1.x][k1.y]=findfather(f[k1.x][k1.y]); return f[k1.x][k1.y];
}
int check(point k1,point k2){
    for (int i=0;i<8;i++){
        point k3=k1+i;
        if (k3.y<1) k3.y+=m*2;
        if (k3.y>m*2) k3.y-=m*2;
        if (pd[k3.x][k3.y]==0) continue;
        for (int j=0;j<8;j++){
            point k4=k2+j; 
            if (k4.y<1) k4.y+=m*2;
            if (k4.y>m*2) k4.y-=m*2;
            if (pd[k4.x][k4.y]==0) continue;
            if (findfather(k3)==findfather(k4))return 1;
        }
    }
    return 0;
}
int main(){
    scanf("%d%d%d",&n,&m,&q); int ans=0; if (m==1){cout<<0<<endl; return 0;}
    memset(pd,0x00,sizeof pd);
    for (int i=0;i<=n+1;i++)
        for (int j=0;j<=2*m+1;j++) f[i][j]=(point){i,j};
    for (;q;q--){
        int k1,k2; scanf("%d%d",&k1,&k2);
        if (check((point){k1,k2},(point){k1,k2+m})==0){
            ans++; //cout<<"asdasd"<<endl;
            for (int i=0;i<8;i++){
                point k3=(point){k1+gox[i],k2+goy[i]};
                if (k3.y<1) k3.y+=m*2;
                if (k3.y>m*2) k3.y-=m*2;
                if (k3.x<=0||k3.x>n) continue;
                if (pd[k3.x][k3.y]==0) continue;
                k3=findfather(k3); f[k3.x][k3.y]=(point){k1,k2};
            }
            pd[k1][k2]=1;
            k2+=m;
            for (int i=0;i<8;i++){
                point k3=(point){k1+gox[i],k2+goy[i]};
                if (k3.y<1) k3.y+=m*2;
                if (k3.y>m*2) k3.y-=m*2;
                if (k3.x<=0||k3.x>n) continue;
                if (pd[k3.x][k3.y]==0) continue;
                k3=findfather(k3); f[k3.x][k3.y]=(point){k1,k2};
            }
            pd[k1][k2]=1;
        }
    }
    cout<<ans<<endl; return 0;
}