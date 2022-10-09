#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int A[100005],N,l,r,i,j;

int main(){
    scanf("%d",&N);
    for (i=1; i<=N; i++) scanf("%d",A+i);
    A[N+1] = 1231231231;
    for (i=2; i<=N+1; i++){
        if (A[i] < A[i-1] && l==0) l = i-1;
        if (A[i] > A[i-1] && l>0 && r==0) r = i-1;
    }
    //printf("%d %d\n",l,r);
    if (l==0 && r==0) l=r=1;
    reverse(A+l,A+r+1);
    for (i=2; i<=N+1; i++) if (A[i] < A[i-1]){
        printf("no\n");
        return 0;
    }
    printf("yes\n%d %d\n",l,r);
    return 0;
}