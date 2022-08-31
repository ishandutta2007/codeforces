#include<cstring>
#include<cstdio>
#include<algorithm>
#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<cstdlib>
using namespace std;
int n,m;
char a[2005][2005];
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};


int qx[4000005],qy[4000005];int p=0,q=0;
int inq[2005][2005]={0};
inline int deg(int i,int j){
    int su=0;
    for (int k=0;k<4;k++)su+=a[i+dx[k]][j+dy[k]]=='.';
    return su;
}
int main()
{
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++)scanf("%s",a[i]+1);
    for (int i=0;i<=m+1;i++)a[0][i]=a[n+1][i]='*';
    for (int i=0;i<=n+1;i++)a[i][0]=a[i][m+1]='*';
    int emp=0;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)if(a[i][j]=='.'){
            emp++;
            if(deg(i,j)==1)qx[q]=i,qy[q++]=j,inq[i][j]=1;
        }
    while(p!=q){
        int x=qx[p],y=qy[p++];
        if(a[x][y]!='.')continue;
        int vx=-1,vy=-1;
        int kk;
        for (int k=0;k<4;k++)if(a[x+dx[k]][y+dy[k]]=='.'){
            kk=k;vx=x+dx[k],vy=y+dy[k];break;
        }
        if(vx==-1){
            printf("Not unique\n");
            return 0;
        }
        if(kk==0){
            a[x][y+1]='>';
            a[x][y]='<';
        }else if(kk==1){
            a[x+1][y]='v';
            a[x][y]='^';
        }else if(kk==2){
            a[x][y-1]='<';
            a[x][y]='>';
        }else {
            a[x-1][y]='^';
            a[x][y]='v';
        }
        emp-=2;
        for (int k=0;k<4;k++)
            if(a[vx+dx[k]][vy+dy[k]]=='.' && !inq[vx+dx[k]][vy+dy[k]] && deg(vx+dx[k],vy+dy[k])==1){
                qx[q]=vx+dx[k];qy[q++]=vy+dy[k];inq[vx+dx[k]][vy+dy[k]]=1;
            }
    }
    if(emp){
            printf("Not unique\n");
            return 0;
    }
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++)putchar(a[i][j]);
        printf("\n");
    }
    return 0;
}