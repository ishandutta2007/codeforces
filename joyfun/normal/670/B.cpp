#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 100005;
int n, id[N];
long long k;

int main() {
    scanf("%d%lld", &n, &k);
    for (int i = 1; i <= n; i++) scanf("%d", &id[i]);
    long long sum = 0;
    int sb;
    for (int i = 1; i <= n; i++) {
        if (i >= k) {
            sb = i;
            break;
        }
        k -= i;
    }
    printf("%d\n", id[k]);
    return 0;
}