#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int N,K,C,A[400],i,j,k,l;

int main(){
    scanf("%d%d%d",&N,&K,&C);
    for (i=1; i<=C; i++){
        scanf("%d",&k);
        A[k]=1;
    }
    K--;
    for (i=1; i<=N; i++){
        if (A[i]==1 || j==K){
            l++;
            j=0;
        } else j++;
    }
    printf("%d\n",l);
    return 0;
}