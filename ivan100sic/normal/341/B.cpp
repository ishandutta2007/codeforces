#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int A[100005],L[100005],LLL,N,i,j,k,l,r,m,o;

int main(){
    scanf("%d",&N);
    for (i=1; i<=N; i++) scanf("%d",A+i);
    memset(L,63,sizeof(L));
    L[1] = A[1];
    LLL = 1;
    for (i=2; i<=N; i++){
        l=1;
        r=LLL;
        o=0;
        while (l<=r){
            m = (l+r)/2;
            if (L[m] < A[i]){
                o = m;
                l = m+1;
            } else {
                r = m-1;
            }
        }
        o++;
        LLL = max(o,LLL);
        L[o] = min(L[o],A[i]);
    }
    printf("%d\n",LLL);
    return 0;
}