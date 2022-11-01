#include <cstdio>
#include <algorithm>
#include <utility>

#define MAX_N 100010

using namespace std;

int n;
int t[MAX_N];
int less[MAX_N], more[MAX_N];

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", t+i);
    }
    for (int i = 1; i <= n; i++) {
        less[i] = less[i-1];
        if (t[i-1] >= 0) less[i]++;
    }
    for (int i = n-1; i >= 0; i--) {
        more[i] = more[i+1];
        if (t[i] <= 0) more[i]++;
    }
    int ans = 2000000000;
    for (int i = 1; i < n; i++) {
        //printf("%d: %d %d\n", i, less[i], more[i]);
        ans = min(ans, less[i] + more[i]);
    }
    printf("%d\n", ans);
}