#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 9;

int k;

char ans[1000][1000];
int r, c;

void gao(int x) {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            ans[i][j + c] = ans[i + r][j] = ans[i][j];
        }
    }
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            char tmp = ans[i][j];
            if (tmp == '+') tmp = '*';
            else tmp = '+';
            ans[i + r][j + c] = tmp;
        }
    }
    r *= 2;
    for (int i = 0; i < c; i++) {
        ans[r][i] = '+';
        ans[r][i + c] = '*';
    }
    r++; c*= 2;
}

int main() {
    scanf("%d", &k);
    r = 0;
    c = 1;
    for (int i = 0; i < k; i++)
        gao(i);
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            printf("%c", ans[i][j]);
        }
        printf("\n");
    }
    for (int i = 0; i < (1<<k); i++) printf("+"); printf("\n");
    return 0;
}