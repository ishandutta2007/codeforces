#include <cstdio>
#include <algorithm>
using namespace std;

int n;
int x, y, z;

int main(){
    scanf("%d", &n);
    if(n == 1) puts("1");
    else if(n == 2) puts("2");
    else if(n % 2) printf("%I64d", (long long)n * (n - 1ll) * (n - 2ll));
    else if(n % 6 == 0) printf("%I64d", (long long)(n - 1ll) * (n - 2ll) * (n - 3ll));
    else printf("%I64d", (long long)n * (n - 1ll) * (n - 3ll));
}