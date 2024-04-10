#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
    int n,m,a,b;
    scanf("%d%d%d%d",&n,&m,&a,&b);
    if (b>=a*m) printf("%d",n*a);
    else printf("%d",n/m*b+min(n%m*a,b));
    return 0;
}