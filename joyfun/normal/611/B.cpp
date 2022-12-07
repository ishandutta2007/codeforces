#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef unsigned long long ll;

int x;
ll a, b;

int main() {
    scanf("%llu%llu", &a, &b);
    int ans = 0;
    for (int i = 1; i < 64; i++) {
        ll tmp = (1ULL<<i) - 1;
        for (int j = 0; j < i - 1; j++) {
            ll sb = (tmp^(1ULL<<j));
            if (sb >= a && sb <= b) {
              //  printf("%llu %llu\n", tmp, sb);
                ans++;
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}