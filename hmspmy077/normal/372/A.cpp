#include <cstdio>
#include <cstring>
#include <functional>
#include <algorithm>

const int N = 500000;

int n, size[N];

bool check(int left) {
    int pair = n - left;
    if (pair * 2 > n) {
        return false;
    }
    for (int i = 0; i < pair; ++ i) {
        if (size[i] * 2 > size[n - pair + i]) {
            return false;
        }
    }
    return true;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++ i) {
        scanf("%d", size + i);
    }
    std::sort(size, size + n);
    int low = 0;
    int high = n;
    while (low < high) {
        int middle = low + high >> 1;
        if (check(middle)) {
            high = middle;
        } else {
            low = middle + 1;
        }
    }
    printf("%d\n", high);
    return 0;
}