#include <cstdio>
#include <algorithm>
using namespace std;

bool isPossible(int a1, int a2, int a3, int a4, bool first4) {
    if (a3 < 0 || a4 < 0)
        return false;
    if (abs(a3 - a4) > 1)
        return false;
    if (min(a1, a2) < max(a3, a4))
        return false;
    if (first4) {
        if (a1 == 0)
            return false;
        if (a3 == 0) {
            return (a2 + a4 == 0);
        }
        if (a4 > a3)
            return false;
        if (a4 == a3) {
            return (a1 >= a3 + 1);
        } else {
            return true;
        }
    } else {
        if (a2 == 0)
            return false;
        if (a4 == 0) {
            return (a1 + a3 == 0);
        }
        if (a4 < a3)
            return false;
        if (a4 == a3) {
            return (a2 >= a3 + 1);
        } else {
            return true;
        }
    }
}

char res[3000000];

int main(void) {
    int a1, a2, a3, a4;
    scanf("%d%d%d%d", &a1, &a2, &a3, &a4); // 4, 7, 47, 74
    if (!isPossible(a1, a2, a3, a4, true) && !isPossible(a1, a2, a3, a4, false)) {
        printf("-1\n");
        return 0;
    }
    int n = a1 + a2;
    for (int i = 0; i < n; i++) {
        if (isPossible(a1, a2, a3, ((i != 0 && res[i-1] == '7')) ? (a4 - 1) : a4, true)) {
            res[i] = '4';
            --a1;
            if (i != 0 && res[i-1] == '7')
                --a4;
        } else {
            res[i] = '7';
            --a2;
            if (i != 0 && res[i-1] == '4')
                --a3;
        }
    }
    res[n] = 0;
    printf("%s\n", res);
    return 0;
}