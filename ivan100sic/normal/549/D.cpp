#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

char A[105][105];
int D[105][105];

int sb,sw;

int i,j,k,l,N,M;


int main(){
    scanf("%d%d",&N,&M);
    for (i=1; i<=N; i++){
        scanf("%s",A[i]+1);
        for (j=1; j<=M; j++){
            D[i][j] = (A[i][j]=='B'?1:-1);
        }
    }
    for (i=N; i>=1; i--){
        for (j=M; j>=1; j--){
            int x = D[i][j];
            if (x!=0){
                for (k=1; k<=i; k++){
                    for (l=1; l<=j; l++){
                        D[k][l] -= x;
                    }
                }
                sw++;
            }
        }
    }
    printf("%d\n",sw);
    return 0;
}