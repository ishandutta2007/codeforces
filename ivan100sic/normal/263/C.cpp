#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std; //

int A[200005],B[200005],N;
int O[200005][5];

void ucitaj(){
    scanf("%d",&N);
    if (N==5){
        printf("1 5 3 4 2\n");
        exit(0);
    }
    int i,j;
    for (i=1; i<=2*N; i++){
        scanf("%d%d",A+i,B+i);
        if (O[A[i]][1] == 0) O[A[i]][1] = B[i]; else
        if (O[A[i]][2] == 0) O[A[i]][2] = B[i]; else
        if (O[A[i]][3] == 0) O[A[i]][3] = B[i]; else
        O[A[i]][4] = B[i];
        if (O[B[i]][1] == 0) O[B[i]][1] = A[i]; else
        if (O[B[i]][2] == 0) O[B[i]][2] = A[i]; else
        if (O[B[i]][3] == 0) O[B[i]][3] = A[i]; else
        O[B[i]][4] = A[i];
    }
    //for (i=1; i<=N; i++) printf("%d %d %d\n",O[i][1],O[i][2],O[i][3],O[i][4]);
}

bool Sus6[10][10];

bool susedi(int a,int b){
    if (Sus6[a][b]) return false;
    return O[a][1] == b || O[a][2] == b || O[a][3] == b || O[a][4] == b;
}

bool susedi6(int a,int b){
    return O[a][1] == b || O[a][2] == b || O[a][3] == b || O[a][4] == b;
}

void sus6(){
    int i,j,k;
    for (i=1; i<=6; i++){
        for (j=i+1; j<=6; j++){
            for (k=i+1; k<=6; k++){
                if (susedi6(i,j)&&susedi6(j,k)&&susedi6(i,k)){
                    Sus6[i][j] = true;
                    Sus6[i][k] = true;
                    Sus6[k][j] = true;
                    Sus6[k][i] = true;
                    Sus6[j][k] = true;
                    Sus6[j][i] = true;
                    //printf("%d %d %d\n",i,j,k);
                }
            }
        }
    }
}

void probaj(int *A){
    int i,j;
    if (!susedi6(A[1],A[2])) return;
    if (!susedi6(A[2],A[3])) return;
    if (!susedi6(A[3],A[4])) return;
    if (!susedi6(A[4],A[5])) return;
    if (!susedi6(A[5],A[6])) return;
    if (!susedi6(A[6],A[1])) return;
    if (!susedi6(A[1],A[3])) return;
    if (!susedi6(A[2],A[4])) return;
    if (!susedi6(A[3],A[5])) return;
    if (!susedi6(A[4],A[6])) return;
    if (!susedi6(A[5],A[1])) return;
    if (!susedi6(A[6],A[2])) return;
    if (susedi6(A[1],A[4])) return;
    if (susedi6(A[2],A[5])) return;
    if (susedi6(A[3],A[6])) return;
    for (i=1; i<=6; i++) printf("%d\n",A[i]);
    exit(0);
}

int S1[200005],S2[200005];

void ubaci(){
    int i,j,k,l,u,v;
    if (N==6){
        sus6();
        for (i=1; i<=N; i++) A[i] = i;
        for (i=1; i<=720; i++){
            probaj(A);
            next_permutation(A+1,A+7);
        }
        printf("-1\n");
        exit(0);
    }
    for (i=1; i<=2*N; i++){
        u = A[i];
        v = B[i];
        k=0;
        if (O[u][1] == O[v][1]) k++;
        if (O[u][2] == O[v][1]) k++;
        if (O[u][3] == O[v][1]) k++;
        if (O[u][4] == O[v][1]) k++;
        if (O[u][1] == O[v][2]) k++;
        if (O[u][2] == O[v][2]) k++;
        if (O[u][3] == O[v][2]) k++;
        if (O[u][4] == O[v][2]) k++;
        if (O[u][1] == O[v][3]) k++;
        if (O[u][2] == O[v][3]) k++;
        if (O[u][3] == O[v][3]) k++;
        if (O[u][4] == O[v][3]) k++;
        if (O[u][1] == O[v][4]) k++;
        if (O[u][2] == O[v][4]) k++;
        if (O[u][3] == O[v][4]) k++;
        if (O[u][4] == O[v][4]) k++;
        if (k==2){
            if (S1[u] == 0) S1[u] = v; else S2[u] = v;
            if (S1[v] == 0) S1[v] = u; else S2[v] = u;
            //printf("g %d %d\n",u,v);
        }
    }
}

bool V[200005];

int Red[200005],RRR;

void obidji(){
    int i,j,k;
    k=1;
    j=1;
    V[1] = true;
    Red[++RRR] = 1;
    while (k<N){
        if (!V[S1[j]]){
            j = S1[j];
            V[j] = true;
        } else
        if (!V[S2[j]]){
            j = S2[j];
            V[j] = true;
        } else {
            printf("-1\n");
            exit(0);
        }
        Red[++RRR] = j;
        k++;
    }
    for (i=1; i<=N; i++) printf("%d%c",Red[i],i==N?'\n':' ');
}

int main(){
    ucitaj();
    ubaci();
    obidji();
    return 0;
}