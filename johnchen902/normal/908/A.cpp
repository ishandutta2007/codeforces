#include <cstdio>
using namespace std;
char s[51];
int main() {
    scanf("%s", s);
    int ans = 0;
    for (int i = 0; s[i]; i++) {
        switch (s[i]) {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
        case '1':
        case '3':
        case '5':
        case '7':
        case '9':
            ans++;
        }
    }
    printf("%d\n", ans);
}