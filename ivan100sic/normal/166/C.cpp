#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int A[1000],N,i,j,k,dodato,X;

void add(int x){
    N++;
    A[N] = x;
    sort(A+1,A+N+1);
    dodato++;
}

int median(){
    return A[(N+1)/2];
}

bool exists(int x){
    int i;
    for (i=1; i<=N; i++) if (A[i]==x) return true;
    return false;
}

int main(){
    scanf("%d%d",&N,&X);
    for (i=1; i<=N; i++) scanf("%d",A+i);
    sort(A+1,A+N+1);
    if (!exists(X)){
        add(X);
    }
    while (true){
        j = median();
        if (j < X) add(100000); else
        if (j > X) add(1); else break;
    }
    printf("%d\n",dodato);
    return 0;
}