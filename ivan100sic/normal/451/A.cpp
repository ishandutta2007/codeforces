#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main(){
    int a,b,x;
    scanf("%d%d",&a,&b);
    x = min(a,b);
    printf(x%2?"Akshat":"Malvika");
    return 0;
}