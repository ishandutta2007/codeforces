#include <cstdio>
#include <algorithm>
using namespace std;

long long N,L,R,i,j,k;

int main(){
    scanf("%I64d",&N);
    for (i=1; i<=N; i++){
        scanf("%I64d%I64d",&j,&k);
        L+=j;
        R+=k;
    }
    printf("%I64d\n",min(L,N-L)+min(R,N-R));
    return 0;
}