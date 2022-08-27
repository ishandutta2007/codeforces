#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cstdio>
#include<iostream>
using namespace std;
int r,c;
#define id(x,y) ((y)*r+(x))
int f[3005*6005];
int gf(int x){return x==f[x]?x:f[x]=gf(f[x]);}
void un(int x,int y){if(x && y)f[gf(x)]=gf(y);}
int dx[8]={1,1,1,0,0,-1,-1,-1};
int dy[8]={1,0,-1,1,-1,1,0,-1};
int vis[3005*6005]={0};int tmp=0;
int main()
{
    scanf("%d%d",&r,&c);
    if(c==1){
        printf("0\n");
        return 0;
    }
    int q;scanf("%d",&q);
    int ans=0;
    while(q--){
        int x,y;scanf("%d%d",&x,&y);
        tmp++;
        for (int i=0;i<8;i++){
            int xx=x+dx[i],yy=y+dy[i];
            if(xx==0||xx>r)continue;
            if(yy<=0)yy+=2*c;
            vis[gf(id(xx,yy))]=tmp;
        }
        int bo=1;vis[0]=0;
        for (int i=0;i<8;i++){
            int xx=x+dx[i],yy=y+dy[i]+c;
            if(xx==0||xx>r)continue;
            if(yy<=0)yy+=2*c;
            if(yy>2*c)yy-=2*c;
            if(vis[gf(id(xx,yy))]==tmp){
                    bo=0;
                    break;
            }
        }
        if(bo){
            ans++;
            f[id(x,y)]=id(x,y);
            f[id(x,y+c)]=id(x,y+c);
            for (int i=0;i<8;i++){
                int xx=x+dx[i],yy=y+dy[i];
                if(xx==0||xx>r)continue;
                if(yy<=0)yy+=2*c;
                un(gf(id(x,y)),gf(id(xx,yy)));
            }
            int bo=1;
            for (int i=0;i<8;i++){
                int xx=x+dx[i],yy=y+dy[i]+c;
                if(xx==0||xx>r)continue;
                if(yy<=0)yy+=2*c;
                if(yy>2*c)yy-=2*c;
                un(gf(id(x,y+c)),gf(id(xx,yy)));
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}