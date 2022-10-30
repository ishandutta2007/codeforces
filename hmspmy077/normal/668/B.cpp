#include <cstdio>
#include <cstring>
#include <vector>

int main()
{
    int n, q;
    scanf("%d%d", &n, &q);
    int even = 0;
    int odd = 1;
    auto update = [&](int& index) {
        if (index & 1) {
            (index += n - 1) %= n;
        } else {
            (index += 1) %= n;
        }
    };
    while (q --) {
        int t;
        scanf("%d", &t);
        if (t == 1) {
            int x;
            scanf("%d", &x);
            x += n;
            (even += x) %= n;
            (odd += x) %= n;
        } else {
            update(even);
            update(odd);
        }
    }
    std::vector<int> result(n);
    for (int i = 0; i < n >> 1; ++ i) {
        result[(even + (i << 1)) % n] = i << 1;
        result[(odd + (i << 1)) % n] = i << 1 | 1;
    }
    for (int i = 0; i < n; ++ i) {
        printf("%d%c", result[i] + 1, " \n"[i == n - 1]);
    }
}