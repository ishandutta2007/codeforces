#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 100005;

char a[N], b[N];

int main() {
    scanf("%s%s", a, b);
    int n = strlen(a);
    int m = strlen(b);
    int cnt = 0;
    for (int i = 0; i <= n - m; i++){
        int flag = 1;
        for (int j = 0; j < m; j++) {
            if (a[i + j] != b[j]) {
                flag = 0;
                break;
            }
        }
        if (flag) {
            a[i + m - 1] = '#';
            cnt++;
        }
    }
    printf("%d\n", cnt);
    return 0;
}