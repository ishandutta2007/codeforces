#include <cstdio>
#include <algorithm>
using namespace std;
int x[300000];
int main() {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d", x + i);
    int k = (n - 1) / 2;
    nth_element(x, x + k, x + n);
    printf("%d\n", x[k]);
}