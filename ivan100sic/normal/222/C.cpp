#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int FSF[10000005],N,M,p,q,pg;
int C[10000005],A[100005],B[100005];
int GGG,DDD;

long long nextprint,old;

void fsito(){
    int i,j,k,l;
    FSF[1] = 1;
    j = 2;
    for (i=1; i<=500; i++){
        while (FSF[j] != 0) j++;
        FSF[j] = j;
        for (k=j*j; k<10000005; k+=j) if (FSF[k]==0) FSF[k] = j;
    }
    for (i=1; i<10000005; i++) if (FSF[i] == 0) FSF[i] = i;
}

int main(){
    int i;
    fsito();
    //return FSF[9999987];
    scanf("%d%d",&N,&M);
    for (i=1; i<=N; i++){
        scanf("%d",A+i);
        p = A[i];
        while (p > 1){
            C[FSF[p]]++;
            p /= FSF[p];
        }
    }
    for (i=1; i<=M; i++){
        scanf("%d",B+i);
        p = B[i];
        while (p > 1){
            C[FSF[p]]--;
            p /= FSF[p];
        }
    }
    printf("%d %d\n",N,M);
    for (i=1; i<=N; i++){
        p = A[i];
        pg = 1;
        while (p>1){
            q = FSF[p];
            if (C[q] > 0){
                C[q]--;
                pg*=q;
            }
            p /= q;
        }
        printf("%d ",pg);
    }
    puts("");
    for (i=1; i<=M; i++){
        p = B[i];
        pg = 1;
        while (p>1){
            q = FSF[p];
            if (C[q] < 0){
                C[q]++;
                pg*=q;
            }
            p /= q;
        }
        printf("%d ",pg);
    }
    puts("");
    return 0;
}