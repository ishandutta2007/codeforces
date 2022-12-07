#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 1000005;

int n;
char str[N];
char s[N];
int top = 0;
char to[500];

int main() {
    to['>'] = '<';
    to['}'] = '{';
    to[')'] = '(';
    to[']'] = '[';
    scanf("%s", str);
    n = strlen(str);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (top == 0 && (str[i] == '>' ||
                         str[i] == ']' ||
                         str[i] == ')' ||
                        str[i] == '}')) {
                        printf("Impossible\n");
                        return 0;
                        }
        if (str[i] == '<' || str[i] == '[' || str[i] == '{' || str[i] == '(')
            s[top++] = str[i];
        else {
            if (to[str[i]] != s[top - 1]) ans++;
            top--;
        }
    }
    if (top) {
        printf("Impossible\n");
        return 0;
    }
    printf("%d\n", ans);
    return 0;
}