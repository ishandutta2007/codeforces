#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int vx,vy,sx,sy;
int Dx[4]={1,0,-1,0};
int Dy[4]={0,1,0,-1};
char c[4]={'R','U','L','D'};
int bd[205][205]={0};
int rx=-100,ry=-100;
int lx=1000,ly=1000;
int ux=-100,uy=-100;
int dx=1000,dy=1000;
int vis[205][205]={0};
int qux[44444],quy[44444],p,q;
int pre[44444],pp[44444];
int bfs(){
    p=q=0;
    int tx=sx,ty=sy;
    qux[q]=vx,quy[q++]=vy;vis[vx][vy]=1;
    while(p!=q){
        int x=qux[p],y=quy[p++];
        for (int i=0;i<4;i++){
            int xx=x+Dx[i],yy=y+Dy[i];
            if(xx>=0 && xx<=202 && yy>=0 && yy<=202 && !vis[xx][yy] && !bd[xx][yy]){
                vis[xx][yy]=1;
                qux[q]=xx;quy[q++]=yy;pre[q-1]=p-1;pp[q-1]=i;
                if(xx==tx && yy==ty)return 1;
            }           
        }
    }
    return 0;
}
int out[44444];int tot=0;
int shd[4444444];int len=0;int pr=0;
int main(){
    scanf("%d%d%d%d",&vx,&vy,&sx,&sy);  

    int m;scanf("%d",&m);vx+=101,vy+=101,sx+=101,sy+=101;
    if(m==0){
        printf("-1\n");
        return 0;
    }
    while(m--){
        int a,b;scanf("%d%d",&a,&b);
        a+=101,b+=101;
        if(a>rx)rx=a,ry=b;
        if(a<lx)lx=a,ly=b;
        if(b>uy)ux=a,uy=b;
        if(b<dy)dx=a,dy=b;
        bd[a][b]=1;
    }
    if(!bfs()){
        printf("-1\n");
        return 0;
    }else{
        int cur=q-1;
        while(cur!=0){
            out[++tot]=pp[cur];
            cur=pre[cur];
        }
        for (int i=tot;i>=1;i--){
            sx+=Dx[out[i]],sy+=Dy[out[i]];
            vx+=Dx[out[i]],vy+=Dy[out[i]];
            putchar(c[out[i]]);
            if(sx>=0 && sx<=202 && sy>=0 && sy<=202 && bd[sx][sy]){             
                sx-=Dx[out[i]],sy-=Dy[out[i]];
            }else {
                shd[++len]=out[i];
            }
        }
        while((sx!=vx || sy!=vy)){
            if(max(sx,vx)<0 || min(sx,vx)>202 || max(sy,vy)<0 || min(sy,vy)>202)break;
            int i=shd[++pr];
            sx+=Dx[i],sy+=Dy[i];
            vx+=Dx[i],vy+=Dy[i];
            putchar(c[i]);
            if(sx>=0 && sx<=202 && sy>=0 && sy<=202 && bd[sx][sy]){             
                sx-=Dx[i],sy-=Dy[i];
            }else shd[++len]=i;
            if(vx>=0 && vx<=202 && vy>=0 && vy<=202 && bd[vx][vy]){ printf("ouch\n");}      
        }
        if(sx!=vx || sy!=vy){
            if(sx>vx){
                if(!(max(sy,vy)<0 || min(sy,vy)>202)){
                    while(min(sy,vy)<=202){
                        sy++,vy++;putchar('U');
                    }
                }
            
                while(max(sx,vx)>=0){
                    sx--,vx--;putchar('L');
                }
                while(sy>ly){
                    sy--,vy--;putchar('D');
                }
                while(sy<ly){
                    sy++,vy++;putchar('U');
                }
                while(vx<sx){
                    vx++,sx++;
                    if(sx==lx)sx--;
                    putchar('R');
                
                }
                    while(max(sx,vx)>=0){
                        sx--,vx--;putchar('L');
                    }
            }else if(sx<vx){
                if(!(max(sy,vy)<0 || min(sy,vy)>202)){
                    while(min(sy,vy)<=202){
                        sy++,vy++;putchar('U');
                    }
                }
                while(min(sx,vx)<=202){
                    sx++,vx++;putchar('R');
                }
                while(sy>ry){
                    sy--,vy--;putchar('D');
                }
                while(sy<ry){
                    sy++,vy++;putchar('U');
                }
                while(vx>sx){
                    vx--,sx--;
                    if(sx==rx)sx++;
                    putchar('L');
                    
                }
                while(min(sx,vx)<=202){
                    sx++,vx++;putchar('R');
                }
            }
            if(sy>vy){
                if(!(max(sx,vx)<0 || min(sx,vx)>202)){
                    while(min(sx,vx)<=202){
                        sx++,vx++;putchar('R');
                    }
                }
                while(max(sy,vy)>=0){
                    sy--,vy--;putchar('D');
                }
                while(sx<dx){
                    sx++,vx++;putchar('R');
                }
                while(sx>dx){
                    sx--,vx--;putchar('L');
                }
                while(sy>vy){
                    sy++,vy++;putchar('U');
                    if(sy==dy)sy--;
                }               
            }else if(sy<vy){
                if(!(max(sx,vx)<0 || min(sx,vx)>202)){
                    while(min(sx,vx)<=202){
                        sx++,vx++;putchar('R');
                    }
                }
                while(min(sy,vy)<=202){
                    sy++,vy++;putchar('U');
                }
                while(sx<ux){
                    sx++,vx++;putchar('R');
                }
                while(sx>ux){
                    sx--,vx--;putchar('L');
                }
                while(sy<vy){
                    sy--,vy--;putchar('D');
                    if(sy==uy)sy++;
                }
            }   
        }
    }
    printf("\n");
    return 0;
}