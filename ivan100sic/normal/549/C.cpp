#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

//S igra prvi

int N,K;
int par,nepar,x,i,j;

int main(){
    scanf("%d%d",&N,&K);
    K = N-K;
    for (i=1; i<=N; i++){
        scanf("%d",&x);
        if (x%2==0) par++; else nepar++;
    }
    if (K==0){
        if (nepar%2){
            printf("Stannis\n");
        } else {
            printf("Daenerys\n");
        }
    } else
    if (K%2==0){
        if (K/2>=par && (N-K)%2==1){
            printf("Stannis\n");
        } else {
            printf("Daenerys\n");
        }
    } else {
        /*
        stanis igra poslednji
        ako dean moze da ga isforsira da mu ostanu samo 0, dean pobedjuje
        ako dean moze da ga isforsira da mu ostanu samo 1, gledamo parnost
        ako dean ne moze da ga isforsira, stan pobedlje
        */
        if (K/2>=nepar || (K/2>=par && (N-K)%2==0)){
            printf("Daenerys\n");
        } else {
            printf("Stannis\n");
        }
    }
    return 0;
}