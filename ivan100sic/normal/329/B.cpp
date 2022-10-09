#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

char A[1005][1005];
int D[1005][1005];
int T[1005][1005];
int N,M;

//-1 neprohodno

int xe,ye,xm,ym,xs,ys,i,j,k,l,x0,y0,d0;

int Qx[1000005],Qy[1000005],qs,qe;

void obidji(int x,int y,int d){
    //printf("%d %d %d\n",x,y,D[x][y]);
    if (D[x][y]==-1) return;
    if (D[x][y]!=1234567) return;
    D[x][y] = d+1;
    qe++;
    Qx[qe] = x;
    Qy[qe] = y;
}

void debug(){
    int i,j;
    for (i=1; i<=N; i++){
        for (j=1; j<=M; j++) printf("%9d",D[i][j]);
        puts("");
    }
}

int main(){
    scanf("%d%d",&N,&M);
    memset(D,255,sizeof(D));
    for (i=1; i<=N; i++){
        scanf("%s",A[i]+1);
        for (j=1; j<=M; j++){
            if (A[i][j]=='T'){
                D[i][j] = -1;
            } else
            if (A[i][j]=='S'){
                xs = i;
                ys = j;
                D[i][j] = 1234567;
            } else
            if (A[i][j]=='E'){
                xe = i;
                ye = j;
                D[i][j] = 0;
            } else {
                T[i][j] = A[i][j] - 48;
                D[i][j] = 1234567;
            }
        }
    }
    qs=1;
    qe=1;
    Qx[1] = xe;
    Qy[1] = ye;
    while (qs<=qe){
        x0 = Qx[qs];
        y0 = Qy[qs];
        d0 = D[x0][y0];
        qs++;
        obidji(x0,y0+1,d0);
        obidji(x0,y0-1,d0);
        obidji(x0+1,y0,d0);
        obidji(x0-1,y0,d0);
    }

    //debug();

    int dja = D[xs][ys],sol=0;
    for (i=1; i<=N; i++){
        for (j=1; j<=M; j++){
            if (D[i][j] != -1 && D[i][j] <= dja) sol += T[i][j];
        }
    }
    printf("%d\n",sol);
    return 0;
}