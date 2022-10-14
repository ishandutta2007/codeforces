#include<iostream>
#include<cstdio>

using namespace std;

const int MAXN = 1000005;

int n;
int p[MAXN], dp[MAXN], a[MAXN], b[MAXN];

void update (int x) {
    if (x == 0) return;
    dp[x]++;
    if (dp[x] > a[p[x]]) {
        a[p[x]] = dp[x];
        if (a[p[x]] > b[p[x]] +1) update(p[x]);
    } else if (dp[x] > b[p[x]]) {
        b[p[x]] = dp[x];
        if (a[p[x]] == b[p[x]]) update(p[x]);
    }
}

int main () {
    cin >> n;
    for (int i=2; i<=n+1; i++) {
        scanf("%d", &p[i]);
        update(i);
        printf("%d ", a[1]);
    }
    return 0;
}