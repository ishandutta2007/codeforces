#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

char S[10005];
int N,i,j,k,l,n,x;

int main(){
    scanf("%s",S+1);
    N = strlen(S+1);
    for (i=1; i<=N; i++){
        if (S[i]=='+') k++; else k--;
        n = min(n,k);
        x = max(x,k);
    }
    printf("%d\n",x-n);
    return 0;
}