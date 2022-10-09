#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int GameGrundy[2][105],Lista[205],N,R,x,i,j,prazna,y,tip;
char A[105][5];

void victor(int x){
    if (x>0) printf("WIN\n"); else printf("LOSE\n");
    exit(0);
}

int par(int x,int y){
    //3 - ivica table
    if (x>y) swap(x,y);
    if (x==1 && y==1) return 0;
    if (x==1 && y==2) return 1;
    if (x==1 && y==3) return 2;
    if (x==2 && y==2) return 0;
    if (x==2 && y==3) return 2;
}

int main(){
    scanf("%d%d",&N,&R);
    //make grundies
    //0 - isti red
    //1 - razlicit red
    GameGrundy[0][0] = 0;
    GameGrundy[1][0] = 0;
    GameGrundy[0][1] = 1;
    GameGrundy[1][1] = 0;
    GameGrundy[2][0] = 0;
    GameGrundy[2][1] = 1;
    for (i=2; i<=N+4; i++){
        //tip 0
        memset(Lista,0,sizeof(Lista));
        //stavljamo u levu stranu
        for (j=2; j<=i-1; j++){
            x = GameGrundy[0][j-2] ^ GameGrundy[0][i-j-1];
            Lista[x]++;
        }
        //stavljamo u desnu stranu
        for (j=3; j<=i-2; j++){
            x = GameGrundy[1][j-2] ^ GameGrundy[1][i-j-1];
            //if (i==5) printf("%d %d\n",j,x);
            Lista[x]++;
        }
        for (j=0; 1; j++){
            if (Lista[j]==0) break;
        }
        GameGrundy[0][i-2] = j;

        //tip 1
        memset(Lista,0,sizeof(Lista));
        for (j=2; j<=i-2; j++){
            x = GameGrundy[0][j-2] ^ GameGrundy[1][i-j-1];
            Lista[x]++;
        }
        for (j=0; 1; j++){
            if (Lista[j]==0) break;
        }
        GameGrundy[1][i-2] = j;

        //tip 2
        memset(Lista,0,sizeof(Lista));
        //stavljamo sa leve strane
        for (j=1; j<=i-2; j++){
            x = GameGrundy[2][j-1] ^ GameGrundy[1][i-j-1];
            Lista[x]++;
        }
        //stavljamo sa desne strane
        for (j=1; j<=i-1; j++){
            x = GameGrundy[2][j-1] ^ GameGrundy[0][i-j-1];
            Lista[x]++;
        }
        for (j=0; 1; j++){
            if (Lista[j]==0) break;
        }
        GameGrundy[2][i-1] = j;
    }
    /*
    for (j=0; j<3; j++){
        for (i=0; i<=N; i++) printf("%d %d %d\n",j,i,GameGrundy[j][i]);
    }
    */

    //ostaje samo tabula rasa
    memset(Lista,0,sizeof(Lista));
    for (i=1; i<=N; i++){
        x = GameGrundy[2][i-1] ^ GameGrundy[2][N-i];
        Lista[x]++;
    }


    for (j=0; 1; j++){
        if (Lista[j]==0) break;
    }
    prazna = j;

    if (R==0){
        victor(prazna);
    }

    while (R--){
        scanf("%d%d",&x,&y);
        A[x][y] = 1;
    }

    int tlast=3,tnew,len=0,xorr=0;
    for (i=1; i<=N+1; i++){
        if (A[i][1]) tnew = 1; else
        if (A[i][2]) tnew = 2; else tnew = 0;

        if (i==N+1) tnew = 3;

        if (tnew==0){
            len++;
        } else {
            tip = par(tlast,tnew);
            //printf("t %d %d %d\n",tip,len,GameGrundy[tip][len]);
            xorr ^= GameGrundy[tip][len];
            len = 0;
            tlast = tnew;
        }
    }
    victor(xorr);
    return 0;
}