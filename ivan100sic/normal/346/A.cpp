#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int gcd2(int a,int b){
    if (b==0) return a; else return gcd2(b,a%b);
}

int N,gcd,i,j,k,mx;

int main(){
    scanf("%d",&N);
    for (i=1; i<=N; i++){
        scanf("%d",&k);
        gcd = gcd2(k,gcd);
        mx = max(mx,k);
    }
    mx /= gcd;
    printf((mx-N)%2?"Alice\n":"Bob\n");
    return 0;
}