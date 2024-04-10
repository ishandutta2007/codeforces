#include <cstdio>
#include <cstring>
#include <algorithm>
#define MOD 1000000007ll
using namespace std;

long long A[4][55][55],N;

int M,K,i,j,k,l;

void mnozi(int src1,int src2,int tgt){
    //printf("eve mnozim %d %d %d\n",src1,src2,tgt);
    int i,j,k;
    long long res;
    for (i=1; i<=M; i++){
        for (j=1; j<=M; j++){
            res=0;
            for (k=1; k<=M; k++){
                res += A[src1][i][k] * A[src2][k][j];
                res %= MOD;
            }
            A[tgt][i][j] = res;
        }
    }
}

int dolan(char x){
    if ('a' <= x && x <= 'z') return x-'a'+1;
    else return x-'A'+27;
}

char S[5];

int main(){
    scanf("%I64d%d%d",&N,&M,&K);
    N--;
    if (N==0){
        printf("%d\n",M);
        return 0;
    }
    for (i=1; i<=M; i++){
        for (j=1; j<=M; j++) A[0][i][j] = 1;
    }
    for (i=1; i<=K; i++){
        scanf("%s",S);
        A[0][dolan(S[0])][dolan(S[1])] = 0;
    }
    memcpy(A[3],A[0],sizeof(A[0]));
    memcpy(A[1],A[0],sizeof(A[0]));
    for (i=60; i>=0; i--){
        if (N & (1ll<<(long long)i)) break;
    }
    /*
    for (i=1; i<=M; i++){
        for (j=1; j<=M; j++) printf("%lld ",A[3][i][j]);
        puts("");
    }
    */
    i--;
    for (j=i; j>=0; j--){
        mnozi(1,1,2);
        memcpy(A[1],A[2],sizeof(A[0]));
        if (N & (1ll<<(long long)j)){
            mnozi(1,3,2);
            memcpy(A[1],A[2],sizeof(A[0]));
        }
    }
    long long res=0;
    for (i=1; i<=M; i++){
        for (j=1; j<=M; j++){
            res += A[1][i][j];
        }
    }
    printf("%I64d\n",res%MOD);
    return 0;
}