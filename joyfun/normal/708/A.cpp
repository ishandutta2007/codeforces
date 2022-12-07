#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 1000005;

char str[N];

int main() {
    scanf("%s", str);
    int n = strlen(str);
    int f = 0;
    for (int i = 0; i < n; i++) {
        if (str[i] != 'a') {
            f = 1;
        }
    }
    if (!f) {
        for (int i = 0; i < n - 1; i++)
            printf("a");
        printf("z\n");
    } else {
        f = 0;
        for (int i = 0; i < n; i++) {
            if (f == 0 && str[i] != 'a') {
                f = 1;
            }
            if (f == 1 && str[i] == 'a') {
                f = 2;
            }
            if (f == 1) printf("%c", str[i] - 1);
            else printf("%c", str[i]);
        }
        printf("\n");
    }
    return 0;
}