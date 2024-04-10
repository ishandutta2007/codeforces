#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int N,i,j,n,pla;
int A[1000005];

void op(){
    long long k=0;
    int i,j;
    for (i=0; i<=N; i++) k += i ^ A[i];
    printf("%lld\n",k);
    for (i=0; i<=N; i++) printf("%d%c",A[i],i==N?'\n':' ');
}


int main(){
    scanf("%d",&N);
    if (N==1){
        printf("2\n1 0\n");
        return 0;
    }
    j=1;
    n=N;
    pla=N+1;
    while (n>0){
        if (n==1){
            A[0] = 1;
            A[1] = 0;
            break;
        }
        if (n==0){
            A[0] = 0;
            break;
        }
        j=1;
        while (j<n) j = 2*j+1;
        for (i=j-n; i<=n; i++){
            pla--;
            A[pla] = i;
        }
        n = j-n-1;
    }
    op();
    return 0;
}