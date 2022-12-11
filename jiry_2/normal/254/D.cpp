#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<vector>
#include<queue>
using namespace std;
int pd[1100][1100],n,m,d,A[1100][1100],B[1100][1100],sign,ans,bo[1100][1100],where1,where2,gox[4]={1,-1,0,0},goy[4]={0,0,1,-1};
char getin(){
    char ch=getchar(); while (ch!='X'&&ch!='R'&&ch!='.') ch=getchar(); return ch;
}
struct atom{
    int x,y;
};
vector<atom>x;
vector<atom>go[1100][1100];
struct atom2{
    int x,y,d;
};
queue<atom2>Q;
void getgo(int k1,int k2){
    sign++; bo[k1][k2]=sign; Q.push((atom2){k1,k2,0}); go[k1][k2].clear();
    while (!Q.empty()){
        int k3=Q.front().x,k4=Q.front().y; go[k1][k2].push_back((atom){k3,k4});
        if (Q.front().d!=d){
            for (int i=0;i<4;i++){
                int k5=k3+gox[i],k6=k4+goy[i];
                if (bo[k5][k6]!=sign&&pd[k5][k6]){
                    Q.push((atom2){k5,k6,Q.front().d+1}); bo[k5][k6]=sign;
                }
            }
        }
        Q.pop();
    }
}
void addin(int k1,int k2){
    for (int i=0;i<go[k1][k2].size();i++){
        int k3=go[k1][k2][i].x,k4=go[k1][k2][i].y;
        if (A[k3][k4]!=sign){A[k3][k4]=sign; B[k3][k4]=0;} B[k3][k4]++;
        if (B[k3][k4]>ans){ans=B[k3][k4]; where1=k3; where2=k4;}
    }
}
int change(int k1,int k2){
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++) if (pd[i][j]&&(i!=k1||j!=k2)){where1=i; where2=j; return 1;}
    return 0;
}
int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    scanf("%d%d%d",&n,&m,&d); int lim=(2*d*d+2*d+1)*2;
    sign=0; memset(pd,0x00,sizeof pd);
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++){
            char ch=getin(); 
            if (ch=='.') pd[i][j]=1; else if (ch=='R'){pd[i][j]=2; x.push_back((atom){i,j}); if (x.size()>lim){cout<<-1<<endl; return 0;} }
        }
    for (int i=1;i<x.size();i++) getgo(x[i].x,x[i].y);
    sign=0; memset(bo,0x00,sizeof bo);
    for (int i=max(x[0].x-d,0);i<=min(x[0].x+d,n);i++)
        for (int j=max(1,x[0].y-(d-abs(i-x[0].x)));j<=min(m,x[0].y+(d-abs(i-x[0].x)));j++)
            if (pd[i][j]){
                int num=0; ans=0; sign++; getgo(i,j); where1=i; where2=j;
                for (int k=0;k<x.size();k++)
                    if (bo[x[k].x][x[k].y]!=sign){num++; addin(x[k].x,x[k].y);}
            //  cout<<ans<<" "<<num<<" "<<i<<" "<<j<<" "<<where1<<" "<<where2<<endl;
                if (ans==num){if (where1==i&&where2==j){if (change(i,j)==0) continue;} cout<<i<<" "<<j<<" "<<where1<<" "<<where2; return 0;}
            }
    cout<<-1<<endl; return 0;
}