#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int A[100005],B[100005],N,X;

void ucitaj(){
    int i,j;
    scanf("%d%d",&N,&X);
    for (i=1; i<=N; i++) scanf("%d",A+i);
    for (i=1; i<=N; i++) scanf("%d",B+i);
    sort(A+1,A+N+1);
    sort(B+1,B+N+1);
}

void resi(){
    //1. deo - hocu da stavim sto vise ljudi ispod vasje
    int i,j,sol2;
    printf("1 ");
    //2. deo - hocu da stavim sto vise ljudi iznad vasje
    sol2=0;
    j=1;
    for (i=N; (i>0) && (j<=N) ; i--){
        while (j<N && A[i]+B[j] < X) j++;
        if (A[i]+B[j] >= X) sol2++;
        j++;
    }
    printf("%d\n",sol2);
}

int main(){
    ucitaj();
    resi();
    return 0;
}