#include <algorithm>
#include <cstdio>
using namespace std;

int b, k, a[100010], ans;

int main() {
    scanf("%d%d", &b, &k); b &= 1;
    for(int i = 1; i <= k; i ++)
        scanf("%d", a + i), (ans += (i != k ? b * a[i] : a[i])) &= 1;
    puts(ans ? "odd" : "even");
    return 0;
}