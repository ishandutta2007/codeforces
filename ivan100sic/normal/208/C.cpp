#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

double D1[105][105],DN[105][105],news,maxs;
int F[105][105][105];
int P1[5000],P2[5000],PA[105],C[105],O[10000],N,M,i,j,k;

void ucitajisredi(){
    scanf("%d%d",&N,&M);
    int i,j,k;
    for (i=1; i<=M; i++){
        scanf("%d%d",&j,&k);
        P1[i]=j;
        P2[i]=k;
        C[j]++;
        C[k]++;
    }
    PA[1] = 1;
    for (i=2; i<=N+1; i++) PA[i] = PA[i-1] + C[i-1];
    memset(C,0,sizeof(C));
    for (i=1; i<=M; i++){
        O[C[P1[i]]+PA[P1[i]]] = P2[i];
        O[C[P2[i]]+PA[P2[i]]] = P1[i];
        C[P1[i]]++;
        C[P2[i]]++;
    }
}

int mini(int a,int b){
    if (a<b) return a; else return b;
}

void floyd(){
    memset(F,63,sizeof(F));
    int i,j,k,l;
    for (i=1; i<=M; i++){
        F[P1[i]][P2[i]][0] = 1;
        F[P2[i]][P1[i]][0] = 1;
    }
    for (k=1; k<=N; k++){
        for (i=1; i<=N; i++){
            for (j=1; j<=N; j++){
                F[i][j][k] = mini(F[i][j][k-1] , F[i][k][k-1] + F[k][j][k-1]);
            }
        }
    }
}

void getd(){
    //d1
    int i,j,k,l;
    D1[1][0] = 1.0;
    for (j=1; j<=N; j++){
        for (i=1; i<=N; i++){
            if (D1[i][j-1]==0.0){ //OH YEA
                for (k=PA[i]; k<PA[i+1]; k++){
                    D1[i][j] += D1[O[k]][j-1];
                }
            }
        }
    }
    DN[N][0] = 1.0;
    for (j=1; j<=N; j++){
        for (i=1; i<=N; i++){
            if (DN[i][j-1]==0.0){
                for (k=PA[i]; k<PA[i+1]; k++){
                    DN[i][j] += DN[O[k]][j-1];
                }
            }
        }
    }
}

int main(){
    ucitajisredi();
    floyd();
    getd();
    //printf("%d\n",F[1][N][N]);
    for (i=2; i<N; i++){
        if (F[1][i][N] + F[i][N][N] == F[1][N][N]){
            news = 2.0 * D1[i][F[1][i][N]] * DN[i][F[N][i][N]] / D1[N][F[1][N][N]];
            if (news > maxs) maxs = news;
        }
    }
    if (1.0 > maxs) maxs = 1.0;
    //printf("%.14lf %.14lf\n",D1[4][2],DN[4][2]);
    printf("%.14lf\n",maxs);
    return 0;
}