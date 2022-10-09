#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int N,A[100005],i,j,k,l,S;
char O[100005];

int main(){
    scanf("%d",&N);
    for (i=1; i<=N; i++) scanf("%d",A+i);
    for (i=N; i>=1; i--){
        if (S<0){
            S+=A[i];
            O[i] = '+';
        } else {
            S-=A[i];
            O[i] = '-';
        }
    }
    if (S<0){
        for (i=1; i<=N; i++) O[i] = '-'+'+'-O[i];
    }
    puts(O+1);
    return 0;
}