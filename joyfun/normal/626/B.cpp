#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 205;
int n;
char str[N];
int cnt[3];
char col[4] = {"BGR"};

int get(char c){
    if (c == 'B') return 0;
    if (c == 'G') return 1;
    if (c == 'R') return 2;
}

void solve() {
    if (n == 1) {
        for (int i = 0; i < 3; i++) {
            if (cnt[i] == 1) {
                printf("%c\n", col[i]);
                return;
            }
        }
    }
    if (n == 2) {
        for (int i = 0; i < 3; i++) {
            if (cnt[i] == 2) {
                printf("%c\n", col[i]);
                return;
            }
        }
        for (int i = 0; i < 3; i++) {
            if (cnt[i] == 0) {
                printf("%c\n", col[i]);
                return;
            }
        }
    }
    if (cnt[0] && cnt[1] && cnt[2]) {
        printf("BGR\n");
        return;
    }
    for (int i = 0; i < 3; i++) {
        if (cnt[i] == n) {
            printf("%c\n", col[i]);
            return;
        }
    }
    for (int i = 0; i < 3; i++) {
        if (cnt[i] == 0) {
            for (int j = 0; j < 3; j++) {
                if (i != j) {
                    int av = j;
                    int bv = 3 - i - j;
                    if (cnt[av] >= 2 && cnt[bv] >= 2) {
                        printf("BGR\n");
                        return;
                    }
                    if (cnt[av] == 1) {
                        int aa = av;
                        int bb = i;
                        if (aa > bb) swap(aa, bb);
                        printf("%c%c\n", col[aa], col[bb]);
                        return;
                    }
                    if (cnt[bv] == 1) {
                        int aa = bv;
                        int bb = i;
                        if (aa > bb) swap(aa, bb);
                        printf("%c%c\n", col[aa], col[bb]);
                        return;
                    }
                }
            }
            return;
        }
    }
}

int main() {
    scanf("%d", &n);
    scanf("%s", str + 1);
    for (int i = 1; i <= n; i++)
        cnt[get(str[i])]++;
    solve();
    return 0;
}