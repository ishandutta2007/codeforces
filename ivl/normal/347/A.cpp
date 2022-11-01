#include <cstdio>
#include <algorithm>

using namespace std;

int n;
int a[105];

int main(){
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", a + i);
    sort(a, a + n);
    int x = a[0];
    a[0] = a[n - 1];
    a[n - 1] = x;
    for (int i = 0; i < n; ++i) printf("%d ", a[i]);
    return 0;
}