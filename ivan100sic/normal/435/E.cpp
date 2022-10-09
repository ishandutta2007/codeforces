#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

char A[1005][1005];
char B[1005][1005];
int N,M;

void ucitaj(){
    scanf("%d%d",&N,&M);
    int i,j;
    for (i=1; i<=N; i++) scanf("%s",A[i]+1);
    for (i=1; i<=N; i++){
        for (j=1; j<=M; j++) A[i][j] -= 48;
    }
}

int Ortak[10];

void proveri(){
    int i,j,c[5];

    /*
    //sranje:
    for (i=1; i<=N; i++){
        for (j=1; j<=M; j++){
            B[i][j] += 48;
        }
    }
    for (i=1; i<=N+1; i++) printf("%s\n",B[i]+1);

    for (i=1; i<=N; i++){
        for (j=1; j<=M; j++){
            B[i][j] -= 48;
        }
    }
    //end sranje
    */

    for (i=1; i<N; i++){
        for (j=1; j<M; j++){
            memset(c,0,sizeof(c));
            if (B[i][j] < 1 || B[i][j] > 4) return;
            c[B[i][j]]++;
            c[B[i+1][j]]++;
            c[B[i][j+1]]++;
            c[B[i+1][j+1]]++;
            if (c[1]*c[2]*c[3]*c[4] == 0) return;
        }
    }
    for (i=1; i<=N; i++){
        for (j=1; j<=M; j++){
            if (A[i][j] != 0 && B[i][j] != A[i][j]) return;
        }
    }
    for (i=1; i<=N; i++){
        for (j=1; j<=M; j++){
            B[i][j] += 48;
        }
    }
    for (i=1; i<=N; i++) printf("%s\n",B[i]+1);
    exit(0);
}

void probaj_hor(int p1,int p2,int n1,int n2){
    int i,j,k;
    memcpy(B,A,sizeof(A));
    for (i=1; i<=N; i++){
        if (i%2 == 1){
            //n
            for (j=1; j<=M; j++) if (B[i][j] != 0){
                k = j;
                break;
            }
            if (j==M+1){
                k = 1;
                B[i][1] = n1;
            }
            for (j=1; j<=M; j++) B[i][j] = ((j-k)%2==0)?B[i][k]:(n1+n2-B[i][k]);
        } else {
            //p
            for (j=1; j<=M; j++) if (B[i][j] != 0){
                k = j;
                break;
            }
            if (j==M+1){
                k = 1;
                B[i][1] = p1;
            }
            for (j=1; j<=M; j++) B[i][j] = ((j-k)%2==0)?B[i][k]:(p1+p2-B[i][k]);
        }
    }
    proveri();
}

void probaj_ver(int p1,int p2,int n1,int n2){
    int i,j,k;
    memcpy(B,A,sizeof(A));
    for (j=1; j<=M; j++){
        if (j%2 == 1){
            //n
            for (i=1; i<=N; i++) if (B[i][j] != 0){
                k = i;
                break;
            }
            if (i==N+1){
                k = 1;
                B[1][j] = n1;
            }
            for (i=1; i<=N; i++) B[i][j] = ((i-k)%2==0)?B[k][j]:(n1+n2-B[k][j]);
        } else {
            //p
            for (i=1; i<=N; i++) if (B[i][j] != 0){
                k = i;
                break;
            }
            if (i==N+1){
                k = 1;
                B[1][j] = p1;
            }
            for (i=1; i<=N; i++) B[i][j] = ((i-k)%2==0)?B[k][j]:(p1+p2-B[k][j]);
        }
    }
    proveri();
}

int main(){
    ucitaj();
    //h
    probaj_hor(1,2,3,4);
    probaj_hor(1,3,2,4);
    probaj_hor(1,4,2,3);
    probaj_hor(2,3,1,4);
    probaj_hor(2,4,1,3);
    probaj_hor(3,4,1,2);
    //v
    probaj_ver(1,2,3,4);
    probaj_ver(1,3,2,4);
    probaj_ver(1,4,2,3);
    probaj_ver(2,3,1,4);
    probaj_ver(2,4,1,3);
    probaj_ver(3,4,1,2);

    printf("0\n");
    return 0;
}