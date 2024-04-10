#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int N,M,i,j,k,l;

int main(){
    scanf("%d",&N);
    if (N<=2){
        printf("-1\n");
    } else
    if (N==3){
        printf("210\n");
    } else {
        M = 1;
        for (i=1; i<N; i++){
            M*=10;
            M%=210;
        }
        printf("1");
        for (i=1; i<=N-4; i++) printf("0");
        printf("%03d\n",210-M);
    }
    return 0;
}