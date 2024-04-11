#include <cstdio>
#include <algorithm>
using namespace std;

long long f(long long x){
    if(x % 2 == 0) return x/2;
    else return f(x-1) - x;
}

int main(){
    long long t;
    scanf("%lld",&t);
    printf("%lld",f(t));
}