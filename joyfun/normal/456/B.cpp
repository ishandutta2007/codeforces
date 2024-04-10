#include <cstdio>
#include <cstring>

const int N = 100005;
char str[N];

int num[5][10];

int main() {
    num[2][0] = 1; num[2][1] = 2; num[2][2] = 4; num[2][3] = 3;
    num[3][0] = 1; num[3][1] = 3; num[3][2] = 4; num[3][3] = 2;
    num[4][0] = 1; num[4][1] = 4;
    scanf("%s", str);
    if (strcmp(str, "0") == 0) {
    printf("4\n");
    return 0;
    }
    int yu = 0;
    for (int i = 0; i < strlen(str); i++) {
    yu = (yu * 10 + str[i] - '0') % 4;
    }
    int sb = yu % 2;
    int ans = (1 + num[2][yu] + num[3][yu] + num[4][sb]) % 5;
    printf("%d\n", ans);
    return 0;
}