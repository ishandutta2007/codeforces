#include <cstdio>
#include <cstring>
#include <algorithm>
#define MOD (1000000007ll)
using namespace std;

long long Polibroj[2005],N,K;
long long A[2005],R[2005];

void ucitaj(){
    scanf("%I64d%I64d",&N,&K);
    int i;
    for (i=1; i<=N; i++) scanf("%I64d",A+i);
}

long long stepen(long long x,long long e){
    if (e==0) return 1;
    if (e%2==0) return (stepen(x,e/2)*stepen(x,e/2)) % MOD;
    return (((stepen(x,e/2)*stepen(x,e/2)) % MOD)*x) % MOD;
}

long long inv(long long x){
    return stepen(x,MOD-2);
}

void napravi(){
    Polibroj[1] = 1;
    Polibroj[2] = K;
    long long i;
    for (i=3; i<=N; i++){
        Polibroj[i] = (((Polibroj[i-1] * (K+i-2)) % MOD) * inv(i-1)) % MOD;
    }
}

void resi(){
    long long i,j,k;
    for (i=1; i<=N; i++){
        for (j=1; j<=i; j++){
            R[i] += A[j] * Polibroj[i+1-j];
            R[i] %= MOD;
        }
    }
    for (i=1; i<=N; i++) printf("%I64d ",R[i]);
    puts("");
}

int main(){
    ucitaj();
    napravi();
    resi();
    return 0;
}