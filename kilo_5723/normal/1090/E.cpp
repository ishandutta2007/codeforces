#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int dx[8]={-2,-1,1,2,2,1,-1,-2},dy[8]={1,2,2,1,-1,-2,-2,-1};
const int maxn=1.5e3+5,maxm=70;
bool exi[10][10];
int dep[10][10];
char s[10];
int que[maxm][2];
int ans[maxn][4],siz;
inline bool leag(int x,int y){
    return x>=0&&y>=0&&x<8&&y<8;
}
void bfs(int x1,int y1,int x2,int y2){
    int i,l,r,ss;
    int xx,yy;
    memset(dep,-1,sizeof(dep));
    que[0][0]=x2; que[0][1]=y2;
    dep[x2][y2]=0;
    l=0; r=1;
    while (l<r&&dep[x1][y1]==-1){
        for (i=0;i<8;i++){
            xx=que[l][0]+dx[i]; yy=que[l][1]+dy[i];
            if (!leag(xx,yy)||dep[xx][yy]!=-1) continue;
            dep[xx][yy]=dep[que[l][0]][que[l][1]]+1;
            que[r][0]=xx; que[r][1]=yy;
            r++;
        }
        l++;
    }
    while (x1!=x2||y1!=y2){
        ss=0;
        while (!exi[x1][y1]){
            if (ss==0) exi[x1][y1]=true;
            que[ss][0]=x1; que[ss][1]=y1;
            ss++;
            for (i=0;i<8;i++){
                xx=x1+dx[i]; yy=y1+dy[i];
                if (leag(xx,yy)&&dep[x1][y1]-dep[xx][yy]==1){
                    x1=xx; y1=yy;
                    break;
                }
            }
        }
        que[ss][0]=x1; que[ss][1]=y1;
        ss++; exi[x1][y1]=false;
        for (i=ss-1;i>0;i--){
            ans[siz][0]=que[i][0]; ans[siz][1]=que[i][1];
            ans[siz][2]=que[i-1][0]; ans[siz][3]=que[i-1][1];
            siz++;
        }
    }
}
int main(){
    int i,j,i2,j2,k;
    int x,y;
    bool flg;
    scanf("%d",&k);
    for (i=0;i<k;i++){
        scanf("%s",s);
        y=s[0]-'a'; x=s[1]-'1';
        exi[x][y]=true;
    }
    for (i=0;i<8;i++) for (j=0;j<8;j++) if (k){
        k--; flg=true;
        if (exi[i][j]) continue;
        for (i2=7;i2>=0&&flg;i2--) for (j2=7;j2>=0&&flg;j2--) if (exi[i2][j2]){
            flg=false;
            bfs(i,j,i2,j2);
        }
    }
    printf("%d\n",siz);
    for (i=0;i<siz;i++)
        printf("%c%c-%c%c\n",'a'+ans[i][1],'1'+ans[i][0],
               'a'+ans[i][3],'1'+ans[i][2]);
    return 0;
}