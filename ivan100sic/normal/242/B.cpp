#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int LL,RR,N,L[100005],R[100005],i,j,k,l;

int main(){
    scanf("%d",&N);
    LL = 1000000005;
    RR = 0;
    for (i=1; i<=N; i++){
        scanf("%d%d",L+i,R+i);
        LL = min(LL,L[i]);
        RR = max(RR,R[i]);
    }
    j=0;
    for (i=1; i<=N; i++){
        if (LL == L[i] && RR==R[i]) j=i;
    }
    if (j==0) printf("-1\n"); else printf("%d\n",j);
    return 0;
}