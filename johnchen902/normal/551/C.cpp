#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int a[100000];

bool ok(long long t) {
    int j = 0, aj = a[0];
    for(int i = 0; i < m; i++) {
        long long tt = t - (j + 1);
        while(j < n && tt > 0) {
            int x = min((long long) aj, tt);
            aj -= x;
            tt -= x;
            while(j < n && aj == 0) {
                aj = a[++j];
                tt--;
            }
        }
    }
    return j == n;
}

int main() {
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++) scanf("%d", a + i);

    long long l = 1, r = n + accumulate(a, a + n, 0LL);
    while(l < r) {
        long long t = (l + r) / 2;
        ok(t) ? (r = t) : (l = t + 1);
    }
    cout << l << endl;
}