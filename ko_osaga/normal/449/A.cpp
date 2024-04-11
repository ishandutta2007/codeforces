#include <cstdio>
#include <algorithm>
long long n,m,k;

long long f(long long x){
    if(x>k || x<0) return 0;
    return (n/(x+1)) * (m/(k-x+1));
}


int main(){
    scanf("%I64d %I64d %I64d",&n,&m,&k);
    if(n+m-2<k){
        puts("-1");
        return 0;
    }
    long long r = std::max(std::max(f(0),f(k)),std::max(f(n-1),f(k-m+1)));
    printf("%I64d",r);
}