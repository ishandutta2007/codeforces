#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 1000005;

int n;
char a[N], b[N];
char to[500];
int jump[N];

int main() {
    to['N'] = 'S';
    to['S'] = 'N';
    to['E'] = 'W';
    to['W'] = 'E';
    scanf("%d", &n);
    n--;
    scanf("%s", a + 1);
    scanf("%s", b + 1);
    reverse(a + 1, a + 1 + n);
    a[1] = to[a[1]];
    int j = 0;
    for (int i = 2; i <= n; i++) {
        a[i] = to[a[i]];
        while (j && a[i] != a[j + 1]) j = jump[j];
        if (a[i] == a[j + 1]) j++;
        jump[i] = j;
    }
    j = 0;
    for (int i = 1; i <= n; i++) {
        if (j == n) j = jump[j];
        while (j && b[i] != a[j + 1]) j = jump[j];
        if (b[i] == a[j + 1]) j++;
    }
    printf("%s\n", j ? "NO" : "YES");
    return 0;
}