#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n;

int solve() {
    if (n % 2) return 0;
    n /= 2;
    return (n - 1) / 2;
}

int main() {
    scanf("%d", &n);
    printf("%d\n", solve());
    return 0;
}