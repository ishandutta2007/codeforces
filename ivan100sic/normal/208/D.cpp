#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

long long rem,Items[6],P[100],Rec[6],N,i,j,k,l;

int main(){
    scanf("%I64d",&N);
    for (i=1; i<=N; i++) scanf("%I64d",P+i);
    for (i=1; i<=5; i++) scanf("%I64d",Items+i);
    for (i=1; i<=N; i++){
        rem+=P[i];
        for (j=5; j>=1; j--){
            Rec[j]+=rem/Items[j];
            rem%=Items[j];
            //printf("%I64d %I64d\n",rem,Items[j]);
        }
    }
    for (j=1; j<=5; j++) printf("%I64d ",Rec[j]);
    printf("\n%I64d\n",rem);
    return 0;
}