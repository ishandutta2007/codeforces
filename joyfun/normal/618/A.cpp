#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n;

int main() {
    scanf("%d", &n);
    for (int i = 20; i >= 0; i--) {
        if (n&(1<<i)) printf("%d ", i + 1);
    }
    return 0;
}