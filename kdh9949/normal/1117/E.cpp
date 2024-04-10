#include <bits/stdc++.h>
using namespace std;

const int N = 10005;

int n, p[N];
char a[3][N], b[3][N], s[N];

int main(){
    scanf("%s", s);
    n = strlen(s);
    for(int i = 0, x, y, z; i < n; i++){
        x = i % 26;
        y = (i / 26) % 26;
        z = i / (26 * 26);
        a[0][i] = x + 'a';
        a[1][i] = y + 'a';
        a[2][i] = z + 'a';
    }
    for(int i = 0; i < 3; i++){
        printf("? %s\n", a[i]);
        fflush(stdout);
        scanf("%s", b[i]);
    }
    for(int i = 0, x, y, z, w; i < n; i++){
        x = b[0][i] - 'a';
        y = b[1][i] - 'a';
        z = b[2][i] - 'a';
        w = x + y * 26 + z * 26 * 26;
        p[w] = i;
    }
    printf("! ");
    for(int i = 0; i < n; i++) putchar(s[p[i]]);
    puts("");
    fflush(stdout);
}