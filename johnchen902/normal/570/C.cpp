#include <cstdio>
using namespace std;
char s[300002];
int main() {
    int n, m;
    scanf("%d %d %s", &n, &m, s + 1);
    int a = 0;
    for(int i = 1; i <= n; i++)
        if(s[i] == '.' && s[i + 1] == '.')
            a++;
    for(int i = 0; i < m; i++) {
        int x;
        char c[2];
        scanf("%d %1s", &x, c);
        if(s[x] == '.' && s[x + 1] == '.') a--;
        if(s[x] == '.' && s[x - 1] == '.') a--;
        s[x] = *c;
        if(s[x] == '.' && s[x + 1] == '.') a++;
        if(s[x] == '.' && s[x - 1] == '.') a++;
        printf("%d\n", a);
    }
}