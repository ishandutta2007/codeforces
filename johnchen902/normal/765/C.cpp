#include <cstdio>
#include <cstring>
using namespace std;
int solve(int k, int a, int b) {
    if(a < k && b < k)
        return -1;
    if(a % k && b < k)
        return -1;
    if(a < k && b % k)
        return -1;

    return a / k + b / k;
}
int main() {
    int k, a, b;
    scanf("%d %d %d", &k, &a, &b);
    printf("%d\n", solve(k, a, b));
}