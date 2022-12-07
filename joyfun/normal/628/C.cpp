#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 100005;

int n, k;
char s[N];

int main() {
    scanf("%d%d", &n, &k);
    scanf("%s", s + 1);
    int Max = 0;
    for (int i = 1; i <= n; i++) {
        int c = s[i] - 'a';
        Max += max(c, 25 - c);
    }
    if (Max < k) printf("-1\n");
    else {
        for (int i = 1; i <= n; i++) {
            int c = s[i] - 'a';
            int cao = min(k, max(c, 25 - c));
            k -= cao;
            if (c - cao >= 0) printf("%c", 'a' + c - cao);
            else if (c + cao <= 25) printf("%c", 'a' + c + cao);
        }
        printf("\n");
    }
    return 0;
}