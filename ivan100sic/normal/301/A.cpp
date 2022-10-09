#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int N,A[205],i,j,k,l,lp;
int B[205];

inline int aps(int x){
    if (x<0) return -x; return x;
}

int main(){
    scanf("%d",&N);
    for (i=1; i<2*N; i++) scanf("%d",A+i);
    if (N%2==1){
        for (i=1; i<2*N; i++){
            A[i] = aps(A[i]);
        }
        lp = 0;
    } else {
        sort(A+1,A+2*N);
        for (i=1; i<=2*N-2; i++){
            if (A[i] + A[i+1] < 0){
                 A[i] = -A[i];
                 A[i+1] = -A[i+1];
            }
        }
    }
    l=0;
    for (i=1; i<2*N; i++) l+=A[i];
    printf("%d\n",l);
    return 0;
}