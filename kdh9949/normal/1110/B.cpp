#include <bits/stdc++.h>
using namespace std;

const int N = 100005;

int n, m, k, a[N], b[N], r;

int main(){
    scanf("%d%d%d", &n, &m, &k);
    for(int i = 0; i < n; i++) scanf("%d", a + i);
    r = a[n - 1] - a[0] + 1;
    for(int i = 0; i < n - 1; i++) b[i] = a[i + 1] - a[i] - 1;
    sort(b, b + n - 1, greater<int>());
    for(int i = 0; i < k - 1; i++) r -= b[i];
    printf("%d\n", r);
}