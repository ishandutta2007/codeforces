#include <cstdio>
#include <cstring>
#include <algorithm>
#define MOD 1000000007
using namespace std;

int md(long long x){
    x %= MOD;
    if (x>=0) return x;
    return x + MOD;
}

long long A[6],x,y,n;

int main(){
    scanf("%lld%lld%lld",&x,&y,&n);
    A[1] = x; A[2] = y;
    A[3] = A[2] - A[1];
    A[4] = A[3] - A[2];
    A[5] = A[4] - A[3];
    A[0] = A[5] - A[4];
    printf("%d\n",md(A[n%6]));
    return 0;
}