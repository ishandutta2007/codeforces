#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

long long N;

int main(){
    scanf("%I64d",&N);
    while (N%3==0) N/=3;
    printf("%I64d\n",(N+2)/3);
    return 0;
}