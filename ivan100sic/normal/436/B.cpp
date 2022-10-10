#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int N,M,i,j,k,l,F[2005];
char A[2005];

int main(){
    scanf("%d%d%d",&N,&M,&k);
    for (i=1; i<=N; i++){
        scanf("%s",A+1);
        for (j=1; j<=M; j++){
            k = 0;
            if (A[j]=='L'){
                k = j - i + 1;
            } else
            if (A[j]=='R'){
                k = j + i - 1;
            } else
            if (A[j]=='U'){
                if (i%2==1) k = j;
            }
            if (k > 0 && k <= M) F[k]++;
        }
    }
    for (i=1; i<=M; i++){
        printf("%d%c",F[i],i==M?'\n':' ');
    }
    return 0;
}