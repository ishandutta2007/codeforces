#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int N;
char A[105][105];
int i,j,k,l;
int X[105],Y[105];

int main(){
    scanf("%d",&N);
    for (i=1; i<=N; i++) scanf("%s",A[i]+1);
    //row cover
    for (i=1; i<=N; i++){
        int ima = 0;
        for (j=1; j<=N; j++){
            if (A[i][j] == '.'){
                ima = j;
                break;
            }
        }
        if (ima){
            X[i] = i;
            Y[i] = j;
        } else break;
    }
    if (i==N+1){
        //uspelo
        for (i=1; i<=N; i++) printf("%d %d\n",X[i],Y[i]);
        return 0;
    }
    //column cover
    for (j=1; j<=N; j++){
        int ima = 0;
        for (i=1; i<=N; i++){
            if (A[i][j] == '.'){
                ima = i;
                break;
            }
        }
        if (ima){
            X[j] = i;
            Y[j] = j;
        } else break;
    }
    if (j==N+1){
        //uspelo
        for (i=1; i<=N; i++) printf("%d %d\n",X[i],Y[i]);
        return 0;
    }
    //nista nije uspalo
    printf("-1\n");
    return 0;
}