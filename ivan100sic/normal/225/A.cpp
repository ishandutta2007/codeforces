#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int L[105],R[105],T,N,i,j,k,l;

int main(){
    scanf("%d%d",&N,&T);
    for (i=1; i<=N; i++) scanf("%d%d",L+i,R+i);
    for (i=1; i<=N; i++){
        if (L[i]==T || R[i]==T || L[i]==7-T || R[i]==7-T){
            printf("NO\n");
            return 0;
        }
    }
    printf("YES\n");
    return 0;
}