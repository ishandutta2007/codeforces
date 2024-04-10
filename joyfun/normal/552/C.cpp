#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int w, m;
int bit[105], bn;

bool judge() {
    for (int i = 0; i < bn; i++) {
        if (bit[i] <= 1) continue;
        if (bit[i] == w - 1) {
            bit[i]++;
            for (int j = i; ; j++) {
                if (bit[j] == w) {
                    bit[j + 1]++;
                    bit[j] = 0;
                } else break;
            }
        } else return false;
    }
    return true;
}

int main() {
    scanf("%d%d", &w, &m);
    while (m) {
        bit[bn++] = m % w;
        m /= w;
    }
    printf("%s\n", judge() ? "YES" : "NO");
    return 0;
}