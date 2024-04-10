#include <cstdio>
#include <cstring>
#include <algorithm>
#define probaj(x,y) if(LoopPart[x][y]==sunac){xc=x;yc=y;goto zajedno;}
using namespace std;

int D[1605][1605],N,M;
int A[1605][1605],RayPart[1605][1605],LoopPart[1605][1605];
int Zraka[1000];

void ucitaj(){
    int i,j;
    scanf("%d%d",&N,&M);
    for (i=1; i<=N; i++){
        for (j=1; j<=M; j++) scanf("%d",A[i]+j);
    }
}

int Qx[2560005],Qy[2560005],qs,qe,suns;

void obidji0(int x,int y){
    if (x<1 || x>N || y<1 || y>M) return;
    if (D[x][y] != 0) return;
    if (A[x][y] == 0) return;
    qe++;
    Qx[qe] = x;
    Qy[qe] = y;
    D[x][y] = suns;
}

void bfs0(int x,int y){
    suns++;
    qs=1;
    qe=1;
    Qx[1] = x;
    Qy[1] = y;
    D[x][y] = suns;
    while (qs<=qe){
        x = Qx[qs];
        y = Qy[qs];
        qs++;
        obidji0(x+1,y);
        obidji0(x-1,y);
        obidji0(x,y+1);
        obidji0(x,y-1);
    }
}

void find_suns(){
    int x,y;
    for (x=1; x<=N; x++){
        for (y=1; y<=M; y++){
            if (D[x][y] == 0 && A[x][y] == 1) bfs0(x,y);
        }
    }
}

inline int sun_index(int x,int y){
    if (x<1 || x>N || y<1 || y>M) return 0;
    return D[x][y];
}

void find_rays(){
    int x,y,dx,dy;
    bool found;
    for (x=1; x<=N; x++){
        for (y=1; y<=M; y++){
            //uslov:
            //da pripadaju krugu
            //da u njihovoj 1,2,3-okolini postoji polje koje ne pripada krugu
            if (D[x][y] != 0){
                found=false;
                for (dy=-3; dy<=3; dy++){
                    for (dx=abs(dy)-3; dx<=3-abs(dy); dx++){
                        if (sun_index(x+dx,y+dy)==0){
                            found=true;
                            goto fuck;
                        }
                    }
                }
                fuck:
                if (found) RayPart[x][y] = D[x][y];
            }
        }
    }
}

int pknz(int x,int y){
    if (x<1 || x>N || y<1 || y>M) return 0;
    if (RayPart[x][y]!=0) return 0;
    return D[x][y];
}

void find_loops(){
    int x,y,dx,dy;
    int found5;
    bool found4;
    for (x=1; x<=N; x++){
        for (y=1; y<=M; y++){
            //uslov
            //da njihova 4-okolina ne sadrzi polje koje pripada krugu i nije zrak, ali da 5-okolina sadrzi
            found4=false;
            for (dx=-5; dx<=5; dx++){
                if (pknz(x+dx,y+5-abs(dx))!=0 || pknz(x+dx,y-(5-abs(dx)))!=0){
                    found4=true;
                    break;
                }
            }
            if (found4) continue;
            found5=0;
            for (dx=-6; dx<=6; dx++){
                found5 = pknz(x+dx,y+6-abs(dx));
                if (found5!=0) break;
                found5 = pknz(x+dx,y-(6-abs(dx)));
                if (found5!=0) break;
            }
            if (found5!=0){
                LoopPart[x][y] = found5;
                //printf("loop of %d : %d %d\n",found5,x,y);
            }
        }
    }
}

void traverse_loops(){
    int x,y,xc,yc,pres,i,j,sunac,len;
    for (x=1; x<=N; x++){
        for (y=1; y<=M; y++){
            if (LoopPart[x][y]!=0 && RayPart[x][y]==0){
                //krecemo da se zebavamo po tu oblas
                xc=x;
                yc=y;
                sunac = LoopPart[x][y];
                pres = 0;
                len = 0;
                while (true){
                    len++;
                    //brisemo postojanja
                    LoopPart[xc][yc] = 0;
                    j = RayPart[xc][yc];
                    //trazimo suseda u kog cemo da idemo
                    probaj(xc+1,yc);
                    probaj(xc-1,yc);
                    probaj(xc,yc+1);
                    probaj(xc,yc-1);
                    //onda po dijagonali
                    probaj(xc+1,yc+1);
                    probaj(xc-1,yc+1);
                    probaj(xc+1,yc-1);
                    probaj(xc-1,yc-1);
                    //onda malo dalje
                    probaj(xc+2,yc);
                    probaj(xc-2,yc);
                    probaj(xc,yc+2);
                    probaj(xc,yc-2);
                    //i jos malo dalje
                    probaj(xc+2,yc+1);
                    probaj(xc-2,yc+1);
                    probaj(xc+2,yc-1);
                    probaj(xc-2,yc-1);
                    probaj(xc+1,yc+2);
                    probaj(xc-1,yc+2);
                    probaj(xc+1,yc-2);
                    probaj(xc-1,yc-2);
                    //ok ovo je vec mnogo
                    probaj(xc+2,yc+2);
                    probaj(xc-2,yc+2);
                    probaj(xc+2,yc-2);
                    probaj(xc-2,yc-2);
                    //nismo nasli suseda
                    //printf("%d %d\n",sunac,len);
                    break;
                    zajedno:
                    if (RayPart[xc][yc]==sunac && j==0) pres++;
                }
                if (len > 20) Zraka[sunac] = pres;
            }
        }
    }
}

void printem(){
    sort(Zraka+1,Zraka+suns+1);
    printf("%d\n",suns);
    for (int i=1; i<=suns; i++) printf("%d%c",Zraka[i],i==suns?'\n':' ');
}

int main(){
    //freopen("21.in.txt","r",stdin);
    ucitaj();
    find_suns();
    find_rays();
    find_loops();
    traverse_loops();
    printem();
    return 0;
}