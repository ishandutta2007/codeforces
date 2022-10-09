#include <cstdio>
using namespace std;

long long a,b,r;

int main(){
    scanf("%I64d%I64d%I64d",&a,&b,&r);
    printf("%I64d\n",((a+r-1)/r) * ((b+r-1)/r));
    return 0;
}