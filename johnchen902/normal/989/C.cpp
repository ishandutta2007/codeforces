#include <cstdio>
#include <cassert>
using namespace std;

int ns = 0;
char s[50][51];

void solve(int a, int b, int c, int d) {
    assert(a == 1);

    for (int i = 0; i < 50; i++)
        s[ns][i] = 'A';
    ns++;

    while (b || c || d) {
        // add row
        for (int i = 0; i < 50; i++) {
            if (i == 0) {
                s[ns][i] = 'A';
            } else if (b && s[ns][i - 1] != 'B') {
                s[ns][i] = 'B';
                b--;
            } else if (c && s[ns][i - 1] != 'C') {
                s[ns][i] = 'C';
                c--;
            } else if (d && s[ns][i - 1] != 'D') {
                s[ns][i] = 'D';
                d--;
            } else {
                s[ns][i] = 'A';
            }
        }
        ns++;
        
        for (int i = 0; i < 50; i++)
            s[ns][i] = 'A';
        ns++;
    }
}

int main() {
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);

    if (a == 1) {
        solve(a, b, c, d);
    } else {
        solve(1, b - 1, c, d);

        int oldns = ns;
        solve(1, a - 1, 0, 0);
        for (int i = oldns; i < ns; i++)
            for (int j = 0; j < 50; j++)
                s[i][j] ^= 'A' ^ 'B';
    }

    printf("%d 50\n", ns);
    for (int i = 0; i < ns; i++) {
        s[i][50] = '\0';
        puts(s[i]);
    }
}