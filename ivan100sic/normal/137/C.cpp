#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

struct erval{
    int l,r;
};

bool cmp(erval a,erval b){
    return a.l < b.l;
}

erval A[200000];
int N,i,j,k,l,sol,maxr;

int main(){
    maxr = -1;
    scanf("%d",&N);
    for (i=1; i<=N; i++) scanf("%d%d",&A[i].l,&A[i].r);
    sort(A+1,A+N+1,cmp);
    for (i=1; i<=N; i++){
        if (A[i].r > maxr){
            maxr = A[i].r;
        } else sol++;
    }
    printf("%d\n",sol);
    return 0;
}