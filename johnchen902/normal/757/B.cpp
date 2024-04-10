#include <cstdio>
#include <algorithm>
using namespace std;
int cnt[100001];
int main() {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        cnt[x]++;
    }
    int ans = 1;
    for(int i = 2; i <= 100000; i++) {
        int c = 0;
        for(int j = i; j <= 100000; j += i)
            c += cnt[j];
        ans = max(ans, c);
    }
    printf("%d\n", ans);
}