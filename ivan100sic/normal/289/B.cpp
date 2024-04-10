#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int N,i,j,k,l,m,d;
int A[10005];

int aps(int x){
    if (x<0) return -x; else return x;
}

int main(){
    scanf("%d%d%d",&N,&m,&d);
    N*=m;
    for (i=1; i<=N; i++) scanf("%d",A+i);
    bool ok=true;
    for (i=1; i<N; i++){
        if (A[i]%d != A[i+1]%d) ok=false;
    }
    if (!ok){
        printf("-1\n");
        return 0;
    }
    for (i=1; i<=N; i++) A[i]/=d;
    sort(A+1,A+N+1);
    m = A[(N+1)/2];
    for (i=1; i<=N; i++) k+=aps(m-A[i]);
    printf("%d\n",k);
    return 0;
}