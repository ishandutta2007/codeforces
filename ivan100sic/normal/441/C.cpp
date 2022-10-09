#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int M,N,K,X[100005],Y[100005],i,j,k;

int main(){
    scanf("%d%d%d",&N,&M,&K);
    for (i=0; i<N*M; i++){
        X[i+1] = i/M + 1;
        Y[i+1] = 1 + ((X[i+1]%2)?(i%M):(M-1-i%M));
    }
    for (i=1; i<K; i++){
        printf("2 %d %d %d %d\n",X[2*i-1],Y[2*i-1],X[2*i],Y[2*i]);
    }
    printf("%d",N*M-2*(K-1));
    for (i=2*K-1; i<=N*M; i++){
        printf(" %d %d",X[i],Y[i]);
    }
    puts("");
    return 0;
}