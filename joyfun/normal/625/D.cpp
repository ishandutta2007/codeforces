#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 100005;

char num[N];
int n;
int c[N];
int ans[N];

bool judge(){
    if (n == 0) return false;
    int i = 0;
    for (; i < n / 2; i++) {
        int j = n - i - 1;
        if (c[i] == c[j] + 1) {
            c[i]--;
            c[i + 1] += 10;
        } else if (c[i] == c[j] + 10) {
            c[j] += 10;
            c[j - 1]--;
        } else if (c[i] == c[j] + 11) {
            c[j] += 10;
            c[j - 1]--;
            if (i + 1 != j) {
                c[i]--;
                c[i + 1] += 10;
            }
        }
        if (c[i] != c[j]) return false;
    }
    if (c[0] == 0) return false;
    //for (int i = 0; i < n; i++) printf("%d ", c[i]); printf("\n");
    if (n % 2 && (c[i] > 18 || c[i] % 2 || c[i] < 0)) return false;
    while (i >= 0) {
        int j = n - i - 1;
        if (c[i] > 18 || c[i] < 0) return false;
        ans[i] = (c[i] + 1) / 2; ans[j] = c[i] / 2;
        i--;
    }
    return true;
}

bool check() {
    for (int i = 0; i < n; i++) c[i] = num[i] - '0';
    if (judge()) return true;
    if (num[0] == '1') {
        for (int i = 0; i < n - 1; i++) num[i] = num[i + 1];
        n--;
        for (int i = 0; i < n; i++) c[i] = num[i] - '0';
        c[0] += 10;
        if (judge()) return true;
    }
    return false;
}

int main() {
    scanf("%s", num);
    n = strlen(num);
    if (check()) {
        for (int i = 0; i < n; i++)
            printf("%c", ans[i] + '0');
        printf("\n");
    } else printf("0\n");
    return 0;
}