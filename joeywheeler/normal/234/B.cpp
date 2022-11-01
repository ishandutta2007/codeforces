#include <cstdio>
#include <algorithm>
#include <utility>

#define MAX_N 1010

using namespace std;

int n, k;
pair<int,int> a[MAX_N];

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i].first);
        a[i].second = i+1;
    }
    sort(a, a+n);
    printf("%d\n", a[n-k].first);
    for (int i = n-k; i < n; i++) {
        printf("%d ", a[i].second);
    }
}