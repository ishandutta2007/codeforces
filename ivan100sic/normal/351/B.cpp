#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int A[3005],N,i,j,k,inv,i0,add;

int main(){
    scanf("%d",&N);
    for (i=1; i<=N; i++) scanf("%d",A+i);
    //simulate sorting
    for (i=1; i<=N; i++){
        for (j=1; j<N; j++) if (A[j+1] < A[j]){
            inv++;
            swap(A[j],A[j+1]);
        }
    }
    //another time
    for (i=1; i<=N; i++) A[i] = N-i+1;
    for (i=1; i<=N; i++){
        for (j=1; j<N; j++) if (A[j+1] < A[j]){
            i0++;
            swap(A[j],A[j+1]);
        }
    }
    if (N==1){
        printf("0\n");
    } else
    if (N==2){
        if (inv==1) printf("1\n"); else printf("0\n");
    } else {
        if (inv % 2 == 1) printf("%d\n",4*(inv/2)+1); else printf("%d\n",4*(inv/2));
    }
    return 0;
}