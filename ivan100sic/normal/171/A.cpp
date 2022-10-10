#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

long long A,B;

long long naopak(long long x){
    long long r=0;
    while (x>0){
        r*=10;
        r+=x%10;
        x/=10;
    }
    return r;
}

int main(){
    scanf("%I64d%I64d",&A,&B);
    printf("%I64d\n",A+naopak(B));
    return 0;
}