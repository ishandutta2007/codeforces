#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int N,M,K;
char A[405][405];
int H[405][405],V[405][405],G[405][405],S[405][405],sol;

void ucitaj(){
    scanf("%d%d",&N,&M);
    int i;
    for (i=1; i<=N; i++) scanf("%s",A[i]+1);
}

void sumice(){
    int i,j,k;
    for (i=1; i<=N; i++){
        for (j=1; j<=M; j++){
            k = (A[i][j]=='1')?1:0;
            G[i][j] = G[i-1][j-1] + k;
            S[i][j] = S[i-1][j+1] + k;
            H[i][j] = H[i-1][j] + k;
            V[i][j] = V[i][j-1] + k;
        }
    }
}

inline bool ps(int x1,int y1,int x2,int y2){
    if (x1==x2){
        return V[x1][y1] == V[x2][y2];
    } else
    if (y1==y2){
        return H[x1][y1] == H[x2][y2];
    } else
    if (x1+y1 == x2+y2){
        return S[x1][y1] == S[x2][y2];
    } else {
        return G[x1][y1] == G[x2][y2];
    }
}

inline void proveri_trougao(int x1,int y1,int x2,int y2,int x3,int y3){
    if (x1 < 1 || x1 > N || x2 < 1 || x2 > N || x3 < 1 || x3 > N) return;
    if (y1 < 1 || y1 > M || y2 < 1 || y2 > M || y3 < 1 || y3 > M) return;
    if (A[x1][y1] == '1' || A[x2][y2] == '1' || A[x3][y3] == '1') return;
    //printf("%d,%d ; %d,%d ; %d,%d\n",x1,y1,x2,y2,x3,y3);
    //printf("etapa 3\n");
    if (ps(x1,y1,x2,y2) && ps(x1,y1,x3,y3) && ps(x2,y2,x3,y3)) sol++;
}



void kukulele(){
    int i,j,s;
    K = min(N,M);
    for (i=1; i<=N; i++){
        for (j=1; j<=M; j++){
            for (s=1; s<=K; s++){
                //printf("haha %d %d %d\n",i,j,s);
                //mali trouglovi

                proveri_trougao(i,j,i+s,j,i,j+s);
                proveri_trougao(i,j,i-s,j,i,j+s);
                proveri_trougao(i,j,i+s,j,i,j-s);
                proveri_trougao(i,j,i-s,j,i,j-s);

                //veliki trouglovi
                proveri_trougao(i-s,j , i,j+s , i,j-s);
                proveri_trougao(i+s,j , i,j+s , i,j-s);
                proveri_trougao(i+s,j , i-s,j , i,j-s);
                proveri_trougao(i+s,j , i-s,j , i,j+s);
            }
        }
    }
    printf("%d\n",sol);
}

int main(){
    ucitaj();
    sumice();
    kukulele();
    return 0;
}