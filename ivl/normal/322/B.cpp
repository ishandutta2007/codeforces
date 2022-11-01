#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    int r = a / 3 + b / 3 + c / 3;
    if (a > 0 && b > 0 && c > 0) r = max(r, (a - 1) / 3 + (b - 1) / 3 + (c - 1) / 3 + 1);
    if (a > 1 && b > 1 && c > 1) r = max(r, (a - 2) / 3 + (b - 2) / 3 + (c - 2) / 3 + 2);
    printf("%d\n", r);
    return 0;
}