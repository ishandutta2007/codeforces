#include <cstdio>

int A[1005],N,i,j,k,l,Z,kk;

int main(){
    scanf("%d",&N);
    for (i=1; i<=N; i++) scanf("%d",A+i);
    Z=1;
    while (2*Z+1 <= (N-1)/2) Z++;
    Z--;

    if (N==1 || N%2==0){
        printf("-1\n");
        return 0;
    }
    for (j=(N-1)/2; j>=1; j--){
        while (A[2*j]>0 || A[2*j+1]>0){
            if (A[j]>0) A[j]--;
            if (A[2*j]>0) A[2*j]--;
            if (A[2*j+1]>0) A[2*j+1]--;
            k++;
        }
    }
    k += A[1];
    printf("%d\n",k);
    return 0;
}