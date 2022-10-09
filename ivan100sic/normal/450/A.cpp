#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int N,M,i,j,k,b,bv;

int main(){
    scanf("%d%d",&N,&M);
    int i,j;
    for (i=1; i<=N; i++){
        scanf("%d",&k);
        k = (k+M-1)/M;
        if (k>=bv){
            b = i;
            bv = k;
        }
    }
    printf("%d\n",b);
    return 0;
}