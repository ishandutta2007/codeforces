#include <cstdlib>
#include <cstring>
#include <cstdio>
using namespace std;

char str[1000000];

int f(int p) {
    return (p == 0) ? 0 : (p%10 + f(p/10));
}

int main(void) {
    scanf("%s", str);
    if (strlen(str) == 1) {
        printf("0\n");
        return 0;
    }
    int cnt = 0;
    for (char *i = str; *i; i++) {
        cnt += (*i - '0');
    }
    int res = 1;
    while (cnt >= 10) {
        cnt = f(cnt);
        ++res;
    }
    printf("%d\n", res);
    return 0;
}