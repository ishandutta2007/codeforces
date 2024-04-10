#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <cstdint>
#include <unordered_set>
using namespace std;

typedef uint32_t ui32;

int main(void) {
    int n, k;
    scanf("%d%d", &n, &k);
    vector<ui32> v(n);
    for (int i = 0; i < n; ++i) {
        int v1, v2, v3, v4;
        scanf("%d.%d.%d.%d", &v1, &v2, &v3, &v4);
        v[i] = v1;
        v[i] <<= 8;
        v[i] |= v2;
        v[i] <<= 8;
        v[i] |= v3;
        v[i] <<= 8;
        v[i] |= v4;
    }

    for (int res = 31; res >= 1; --res) {
        unordered_set<ui32> h;
        for (int i = 0; i < n; ++i) {
            h.insert(v[i] >> res);
        }
        if (h.size() == k) {
            ui32 r = ui32(-1);
            r <<= res;
            printf("%u.%u.%u.%u\n", (r >> 24) & 0xff, (r >> 16) & 0xff, (r >> 8) & 0xff, r & 0xff);
            return 0;
        }
    }
    printf("-1");
    return 0;
}