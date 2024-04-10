#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    if (n & 1) printf("-1");
    else {
        for (int i = 1; i <= n; i += 2) {
            printf("%d %d ", i+1, i);
        }
    }
}