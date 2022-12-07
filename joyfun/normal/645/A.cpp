#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

char a[5][5], b[5][5];
char s1[10], s2[10];
int sn1, sn2;

bool judge() {
    for (int i = 0; i < 3; i++) {
        int flag = 1;
        for (int j = 0; j < 3; j++) {
            if (s1[i + j] != s2[j]) {
                flag = 0;
                break;
            }
        }
        if (flag) return true;
    }
    return false;
}

int main() {
    for (int i = 0; i < 2; i++)
        scanf("%s", a[i]);
    for (int i = 0; i < 2; i++)
        scanf("%s", b[i]);

    for (int i = 0; i < 2; i++) {
        if (a[0][i] != 'X')
            s1[sn1++] = a[0][i];
    }
    for (int i = 1; i >= 0; i--) {
        if (a[1][i] != 'X')
            s1[sn1++] = a[1][i];
    }

    for (int i = 0; i < 2; i++) {
        if (b[0][i] != 'X')
            s2[sn2++] = b[0][i];
    }
    for (int i = 1; i >= 0; i--) {
        if (b[1][i] != 'X')
            s2[sn2++] = b[1][i];
    }

    s1[sn1] = 0; s2[sn2] = 0;
   // printf("%s %s\n", s1, s2);
    for (int i = 0; i < 3; i++) s1[i + 3] = s1[i];

    printf("%s\n", judge() ? "YES" : "NO");
    return 0;
}