#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int K,i,j,k,l,k0;
int A3[105],A2[105];
bool Graf[105][105];

int main(){
    scanf("%d",&K);
    for (i=3; i<=100; i++) A3[i] = i*(i-1)*(i-2)/6;
    for (i=2; i<=100; i++) A2[i] = i*(i-1)/2;
    for (k=3; A3[k+1]<=K; k++);
    for (i=1; i<=k; i++){
        for (j=i+1; j<=k; j++){
            Graf[i][j] = true;
            Graf[j][i] = true;
        }
    }
    l = K - A3[k];
    k0 = k;
    while (l>0){
        for (i=2; A2[i+1]<=l && i<k0; i++);
        l -= A2[i];
        k++;
        for (j=1; j<=i; j++){
            Graf[k][j] = true;
            Graf[j][k] = true;
        }
    }
    printf("%d\n",k);
    for (i=1; i<=k; i++){
        for (j=1; j<=k; j++) putchar(Graf[i][j]+48);
        puts("");
    }
    return 0;
}