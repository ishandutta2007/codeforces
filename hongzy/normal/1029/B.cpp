#include <iostream>
#include <cstdio>
using namespace std;

int n, ans, a[200010];
bool tag[200010];

int main() {
    scanf("%d", &n);
    a[0] = 0;
    for(int i = 1; i <= n; i ++) {
        scanf("%d", &a[i]);
        tag[i] = a[i] <= a[i - 1] << 1;
    }
    int cnt = 0;
    for(int i = 1; i <= n; i ++) {
        if(tag[i]) cnt ++, ans = max(ans, cnt);
        else cnt = 0;
    }
    printf("%d\n", ans + 1);
    return 0;
}