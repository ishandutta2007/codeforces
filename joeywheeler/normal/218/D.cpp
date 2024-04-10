#include <cstdio>
#include <algorithm>

using namespace std;

char buff[1000005];
char res[1000005];
int best = 2000000;
int n, r;

void make(int T, int B) {
    int i = n-1;
    while (n >= 0 && T != 0 && B != 0) {
        if (T >= B) {
            T -= B;
            buff[i--] = 'T';
        } else {
            B -= T;
            buff[i--] = 'B';
        }
    }
    if (i != -1 || !(T == 0 && B == 1)) return;
    int err = 0;
    for (i = 1; i < n; i++) if (buff[i] == buff[i-1]) err++;
    if (err < best) {
        best = err;
        for (i = 0; i < n; i++) res[i] = buff[i];
    }
}

int main() {
    scanf("%d %d", &n, &r);
    for (int i = 0; i <= r; i++) {
        make(i,r);
        make(r,i);
    }
    if (best == 2000000) printf("IMPOSSIBLE\n");
    else {
        printf("%d\n%s\n", best, res);
    }
    return 0;
}