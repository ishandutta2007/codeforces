#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n;

bool judge(int x) {
    if (x % 400 == 0) return true;
    if (x % 4 == 0 && x % 100) return true;
    return false;
}

int main() {
    scanf("%d", &n);
    int sum = 0;
    int f = judge(n);
    for (int i = n; ;i++) {
        sum += judge(i) ? 366 : 365;
        if (sum % 7 == 0 && judge(i + 1) == f) {
            printf("%d\n", i + 1);
            break;
        }
    }
    return 0;
}