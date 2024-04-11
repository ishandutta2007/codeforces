#include <iostream>
#include <stdio.h>
#include <algorithm>

typedef long long ll;
using namespace std;

const int N = 2000111;
int ans = 0;
bool u[N];
int l[N];

inline void check(int a, int b) {
    if (a < b || !b || !a) return;
    ans = max(ans, a % b);
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        int x;
        scanf("%d", &x);
        u[x] = true;
    }
    for (int i = 1; i < N; ++i) {
        if (u[i - 1]) l[i] = i - 1;
        else l[i] = l[i - 1];
    }

    for (int i = 2; i < N; ++i)
        if (u[i]) {
            for (int j = i; j < N; j += i) {
                check(l[j], i);
            }
        }

    cout << ans << endl;

    return 0;
}