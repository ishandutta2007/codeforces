#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

//   a/b e/o
int D[2] [2][100005],N,i,j,k,l;
long long par,nepar;
char A[100005];

int main(){
    scanf("%s",A+1);
    N = strlen(A+1);
    for (i=1; i<=N; i++){
        par += D[A[i]=='b'][i%2][i-1];
        nepar += D[A[i]=='b'][1-i%2][i-1];
        D[0][0][i] = D[0][0][i-1];
        D[1][0][i] = D[1][0][i-1];
        D[0][1][i] = D[0][1][i-1];
        D[1][1][i] = D[1][1][i-1];
        D[A[i]=='b'][i%2][i]++;
    }
    printf("%lld %lld\n",nepar,par+N);
    return 0;
}