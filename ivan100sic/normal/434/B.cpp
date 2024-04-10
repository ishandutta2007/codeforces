#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int N,M,Q;

int A[1005][1005];

void ucitaj(){
    scanf("%d%d%d",&N,&M,&Q);
    int i,j;
    for (i=1; i<=N; i++){
        for (j=1; j<=M; j++){
            scanf("%d",A[i]+j);
        }
    }
}

int Levo[1005][1005],Dsno[1005][1005],Gore[1005][1005],Dole[1005][1005];

void const0(){
    int i,j;
    for (i=1; i<=N; i++){
        for (j=1; j<=M; j++){
            Gore[i][j] = A[i][j] * (Gore[i-1][j] + 1);
            Levo[i][j] = A[i][j] * (Levo[i][j-1] + 1);
        }
    }
    for (i=N; i>=1; i--){
        for (j=M; j>=1; j--){
            Dole[i][j] = A[i][j] * (Dole[i+1][j] + 1);
            Dsno[i][j] = A[i][j] * (Dsno[i][j+1] + 1);
        }
    }
}

void query_1(int x,int y){
    A[x][y] = 1 - A[x][y];
    //rekonstruisemo sve redom
    int i,j;
    for (i=1; i<=N; i++) Gore[i][y] = A[i][y] * (Gore[i-1][y] + 1);
    for (i=N; i>=1; i--) Dole[i][y] = A[i][y] * (Dole[i+1][y] + 1);
    for (j=1; j<=M; j++) Levo[x][j] = A[x][j] * (Levo[x][j-1] + 1);
    for (j=M; j>=1; j--) Dsno[x][j] = A[x][j] * (Dsno[x][j+1] + 1);
}

int H[1005],cent,len;

int histogram_solver(){
    int i,j,h,sol,hi,hj;
    i = cent;
    j = cent;
    h = H[cent];
    sol = h;
    while (true){
        if (i==1 && j==len) break;
        if (i==1){
            j++;
            h = min(h , H[j]);
            sol = max(sol , h * (j-i+1));
        } else
        if (j==len){
            i--;
            h = min(h , H[i]);
            sol = max(sol , h * (j-i+1));
        } else {
            hi = min(h , H[i-1]);
            hj = min(h , H[j+1]);
            if (hi > hj){
                i--;
            } else {
                j++;
            }
            h = min(h,min(H[i],H[j]));
            sol = max(sol , h * (j-i+1));
        }
    }
    return sol;
}

void query_2(int x,int y){
    //damo ulaz histogram solveru
    int i,j,sol=0;

    for (i=1; i<=N; i++) H[i] = Levo[i][y];
    len = N;
    cent = x;
    sol = max(sol,histogram_solver());

    for (i=1; i<=N; i++) H[i] = Dsno[i][y];
    sol = max(sol,histogram_solver());

    for (j=1; j<=M; j++) H[j] = Gore[x][j];
    len = M;
    cent = y;
    sol = max(sol,histogram_solver());

    for (j=1; j<=M; j++) H[j] = Dole[x][j];
    sol = max(sol,histogram_solver());

    printf("%d\n",sol);
}

int main(){
    ucitaj();
    const0();
    while (Q--){
        int t,x,y;
        scanf("%d%d%d",&t,&x,&y);
        if (t==1){
            query_1(x,y);
        } else {
            query_2(x,y);
        }
    }
    return 0;
}