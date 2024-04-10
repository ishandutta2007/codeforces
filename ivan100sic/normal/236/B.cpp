#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int Primes[100] = {0,2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,0,0};
int a,b,c,i,j,k,r;

int divisor(int x){
    int rez=1,i,j,k;
    while (x>1){
        k=1;
        for (i=1; i<=25; i++) if (x % Primes[i] == 0) break;
        while (x % Primes[i] == 0){
            k++;
            x /= Primes[i];
        }
        rez*=k;
    }
    return rez;
}

int main(){
    scanf("%d%d%d",&a,&b,&c);
    for (i=1; i<=a; i++){
        for (j=1; j<=b; j++){
            for (k=1; k<=c; k++){
                r += divisor(i*j*k);
            }
        }
    }
    printf("%d\n",r);
    return 0;
}