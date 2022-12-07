#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <set>
using namespace std;

const int N = 150005;

int n, a, b;

int main() {
    scanf("%d%d%d", &n, &a, &b);
    a--;
    printf("%d\n", ((a + b) % n + n) % n + 1);
    return 0;
}