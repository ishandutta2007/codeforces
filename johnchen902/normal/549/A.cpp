#include <cstdio>
using namespace std;

char s[50][51];

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++)
        scanf("%s", s[i]);
    int x = 0;
    for(int i = 0; i + 1 < n; i++)
        for(int j = 0; j + 1 < m; j++) {
            bool f = s[i][j] == 'f' || s[i + 1][j] == 'f' || s[i][j + 1] == 'f' || s[i + 1][j + 1] == 'f';
            bool a = s[i][j] == 'a' || s[i + 1][j] == 'a' || s[i][j + 1] == 'a' || s[i + 1][j + 1] == 'a';
            bool c = s[i][j] == 'c' || s[i + 1][j] == 'c' || s[i][j + 1] == 'c' || s[i + 1][j + 1] == 'c';
            bool e = s[i][j] == 'e' || s[i + 1][j] == 'e' || s[i][j + 1] == 'e' || s[i + 1][j + 1] == 'e';
            if(f && a && c && e)
                x++;
        }
    printf("%d\n", x);
}