#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int N,K,i;
char S[1000005];

int main(){
    scanf("%d%d",&N,&K);
    if (K==1){
        if (N==1){
            S[1] = 'a';
        } else {
            printf("-1\n");
            return 0;
        }
    } else
    if (K==2){
        if (N>=2){
            for (i=1; i<=N; i++) S[i] = 'a' + 1 - i%2;
        } else {
            printf("-1\n");
            return 0;
        }
    } else {
        if (N==K){
            for (i=1; i<=N; i++) S[i] = i+'a'-1;
        } else
        if (N<K){
            printf("-1\n");
            return 0;
        } else {
            for (i=1; i<=N-K+2; i++) S[i] = 'a' + 1 - i%2;
            for (i=3; i<=K; i++) S[N-K+i] = 'a'+i-1;
        }
    }
    printf("%s\n",S+1);
    return 0;
}