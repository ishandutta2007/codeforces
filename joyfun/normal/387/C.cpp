#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
const int N = 100005;

char seq[N];
int i, j;
char save[N];
int sn = 0;
int len;

bool judge(int len) {
    if (i > sn) return true;
    if (i < sn) return false;
    if (i == sn) {
        for (int j = sn - 1; j >= 0; j--) {
            if (seq[sn - 1 - j] < save[j]) return false;
        }
    }
    return true;
}

int main() {
    int ans = 1;
    scanf("%s", seq);
    len = strlen(seq);
    for (i = len - 1; i >= 0; i--) {
        if (seq[i] != '0') {
            save[sn++] = seq[i];
            if (judge(i)) {
                ans++;
                sn = 0;
            }
        }
        else {
            save[sn++] = seq[i];
        }
    }
    printf("%d\n", ans);
    return 0;
}