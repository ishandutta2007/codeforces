#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int Max1[1000005],Max2[1000005],N,i,j,k,l,x,ins,nu;
int P[1000005],D[1000005];

int main(){
    scanf("%d",&N);
    for (i=2; i<=N+1; i++){
        scanf("%d",P+i);
        D[i] = 1;
        x = i;
        ins = 1;
        while (x != 1){
            //insertion
            if (ins > Max1[P[x]]){
                Max2[P[x]] = Max1[P[x]];
                Max1[P[x]] = ins;
            } else
            if (ins > Max2[P[x]]){
                Max2[P[x]] = ins;
            }
            //
            //printf("%d %d %d %d\n",P[x],x,Max1[x],Max2[x]);
            x = P[x];
            nu = max(Max1[x],Max2[x]+1);
            if (nu == D[x]) break;
            D[x] = nu;
            ins = D[x];
        }
        printf("%d\n",Max1[1]);
    }
    return 0;
}