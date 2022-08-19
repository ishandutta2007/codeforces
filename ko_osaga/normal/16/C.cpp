#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long lint;

int g(int x, int y){
    return y ? g(y,x%y) : x;
}

int main(){
    int a,b,x,y;
    scanf("%d %d %d %d",&a,&b,&x,&y);
    int gcd = g(x,y);
    x /= gcd, y /= gcd;
    int ret = min(a/x,b/y);
    printf("%d %d",ret * x, ret * y);
}