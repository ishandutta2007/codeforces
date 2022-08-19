#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
typedef long long lint;
typedef pair<lint,lint> pi;

int g(int x, int y){
    return y ? g(y,x%y) : x;
}

pi extgcd(int x, int y, int z){
    if(y == 0){
        if(x != 1){
            printf("ASSERTION ERROR");
        }
        return pi(z,0);
    }
    pi t = extgcd(y,x%y,z);
    return pi(t.second,t.first - (x / y) * t.second);
}

int main(){
    int a,b,c;
    scanf("%d %d %d",&a,&b,&c);
    c = -c;
    int buhox = (a < 0 ? -1 : 1);
    int buhoy = (b < 0 ? -1 : 1);
    a = abs(a);
    b = abs(b);
    int gcd = g(a,b);
    if(c % gcd){
        puts("-1");
        return 0;
    }
    a /= gcd;
    b /= gcd;
    c /= gcd;
    pi t = extgcd(a,b,c);
    printf("%I64d %I64d",t.first * buhox,t.second * buhoy);
}