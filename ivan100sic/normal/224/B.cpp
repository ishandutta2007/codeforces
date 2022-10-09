#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
using namespace std;

int A[100005],N,i,j,k,l,r,K;
set <int> S;

int main(){
    scanf("%d%d",&N,&K);
    for (i=1; i<=N; i++) scanf("%d",A+i);
    j=1;
    while (A[j]==A[j+1]) j++;
    for (i=j; i<=N; i++){
        S.insert(A[i]);
        if (S.size() == K){
            break;
        }
    }
    if (i==N+1){
        printf("-1 -1\n");
        return 0;
    }
    S.clear();
    //printf("right end %d\n",i);
    for (j=i; j; j--){
        S.insert(A[j]);
        if (S.size() == K){
            printf("%d %d\n",j,i);
            return 0;
        }
    }
}