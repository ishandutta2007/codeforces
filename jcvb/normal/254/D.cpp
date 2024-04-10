#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cstdio>
#include<iostream>
using namespace std;
int n,m,d;
int a[1005][1005];
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int rx[500],ry[500];int tot=0;

int qx[1000],qy[1000],dis[1000];
int vis[1005][1005]={0};
int p,q;
int tmp=0;
void bfs(int x,int y){
    tmp++;
    p=q=0;
    dis[q]=0;qx[q]=x;qy[q++]=y;vis[x][y]=tmp;
    while(p!=q){
        int ux=qx[p],uy=qy[p++];
        if(dis[p-1]==d)continue;
        for (int i=0;i<4;i++){
            int vx=ux+dx[i],vy=uy+dy[i];
            if(vis[vx][vy]!=tmp && ~a[vx][vy]){
                dis[q]=dis[p-1]+1;
                qx[q]=vx,qy[q++]=vy;
                vis[vx][vy]=tmp;
            }
        }
    }
}
        
int lix[1000],liy[1000];
int lix2[1000],liy2[1000];
int yes[1000]={0},yestmp=0;
int main()
{
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
    scanf("%d%d%d",&n,&m,&d);
    for(int i=1;i<=n;i++)
        for (int j=1;j<=m;j++){
            char c;while((c=getchar())!='X' && c!='.' && c!='R');
            if(c=='R'){
                ++tot;
                rx[tot]=i,ry[tot]=j;
                a[i][j]=tot;
                if(tot>290){
                    printf("-1\n");
                    return 0;
                }
            }else if(c=='X'){
                a[i][j]=-1;
            }else a[i][j]=0;
        }
    bfs(rx[1],ry[1]);int ttot=q;
    for (int j=0;j<ttot;j++)lix[j]=qx[j],liy[j]=qy[j];
    for (int j=0;j<ttot;j++){
        bfs(lix[j],liy[j]);
        yestmp++;
        for (int t=1;t<=tot;t++){
            if(vis[rx[t]][ry[t]]==tmp)yes[t]=yestmp;
        }
        int t;
        for (t=1;t<=tot;t++)if(yes[t]!=yestmp)break;
        if(t==tot+1){
            for (int i=1;i<=n;i++)
                for (int k=1;k<=m;k++){
                    if(a[i][k]!=-1 && (i!=lix[j] || k!=liy[j])){
                        printf("%d %d %d %d\n",lix[j],liy[j],i,k);
                        return 0;
                    }
                }
        }
        bfs(rx[t],ry[t]);
        int ttot2=q;
        for (int i=0;i<q;i++)lix2[i]=qx[i],liy2[i]=qy[i];
        for (int i=0;i<ttot2;i++){
            if(lix[j]==2 && liy[j]==3 && lix2[i]==6 && liy2[i]==9){
                printf("haha");
            }
            bfs(lix2[i],liy2[i]);
            int bo=1;
            for (int k=1;k<=tot;k++)if(yes[k]!=yestmp && vis[rx[k]][ry[k]]!=tmp){bo=0;break;}
            if(bo){
                printf("%d %d %d %d",lix[j],liy[j],lix2[i],liy2[i]);
                return 0;
            }
        }
    }
    printf("-1\n");
    return 0;
}