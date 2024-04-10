#include <cstdio>
#include <algorithm>
using namespace std;
int main() {
    int n;
    scanf("%d", &n);

    int sum = 0, mini = 100000, neg = 0;
    for (int i = 0; i < 2 * n - 1; i++) {
        int a;
        scanf("%d", &a);
        sum += abs(a);
        mini = min(mini, abs(a));
        if (a < 0)
            neg++;
    }

    if (neg % 2 == 1 && n % 2 == 0)
        sum -= mini * 2;

    printf("%d\n", sum);
}