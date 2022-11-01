#include <cstdio>
#include <algorithm>
using namespace std;
int a[200000];
int main() {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", a + i);
        a[i] += i;
    }
    sort(a, a + n);
    if(adjacent_find(a, a + n) != a + n) {
        puts(":(");
    } else {
        for(int i = 0; i < n; i++) {
            a[i] -= i;
            printf("%d ", a[i]);
        }
    }
}