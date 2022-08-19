#include <cstdio>
typedef long long lint;

lint g(lint x, lint y){
    return y ? (g(y,x%y) + x/y) : 0;
}

int main(){
    lint a, b;
    scanf("%lld %lld",&a,&b);
    printf("%lld",g(a,b));
}