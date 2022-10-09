#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int B[105][105],A[105],N,i,j,k,l;

int main(){
    scanf("%d",&N);
    for (i=1; i<=N; i++){
        for (j=1; j<=N; j++) scanf("%d",B[i]+j);
    }
    for (i=1; i<=N; i++){
        for (j=1; j<=N; j++) if (i!=j){
            for (k=0; k<30; k++){
                A[i] = A[i] | ((1<<k) & B[i][j]);
                A[j] = A[j] | ((1<<k) & B[i][j]);
            }
        }
    }
    for (i=1; i<=N; i++) printf("%d%c",A[i],i==N?'\n':' ');
    return 0;
}