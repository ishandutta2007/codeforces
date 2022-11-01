#include <cstdio>

using namespace std;

int main(){
    int a, b, c, d, e, f;
    scanf("%d%d%d%d%d%d", &a, &b, &c, &d, &e, &f);
    int n;
    scanf("%d", &n);
    n -= (a + b + c + 4) / 5;
    n -= (d + f + e + 9) / 10;
    if (n < 0) printf("NO\n");
    else printf("YES\n");
    return 0;
}