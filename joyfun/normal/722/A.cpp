#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int s;
int a, b;

const int INF = 0x3f3f3f3f;

int cal(int x, int y) {
    int ans = 0;
    if (x / 10 != a / 10) ans++;
    if (x % 10 != a % 10) ans++;
    if (y / 10 != b / 10) ans++;
    if (y % 10 != b % 10) ans++;
    return ans;
}

int main() {
    scanf("%d", &s);
    scanf("%d:%d", &a, &b);
    int u, d;
    if (s == 12) {
        u = 12;
        d = 1;
    } else {
        u = 23;
        d = 0;
    }
    int ans = INF;
    int aa, bb;
    for (int i = d; i <= u; i++) {
        for (int j = 0; j <= 59; j++) {
            if (cal(i, j) < ans) {
                ans = cal(i, j);
                aa = i; bb = j;
            }
        }
    }
    printf("%02d:%02d\n", aa, bb);
    return 0;
}