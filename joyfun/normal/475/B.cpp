#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

int n, m;
char a[25], b[25];

bool judge(char up, char down, char left, char right) {
    if (up == down) return false;
    if (left == right) return false;
    if (up == '<' && left == '^') return false;
    if (down == '<' && left == 'v') return false;
    if (up == '>' && right == '^') return false;
    if (down == '>' && right == 'v') return false;
    return true;
}

int main() {
    scanf("%d%d", &n, &m);
    scanf("%s%s", a, b);
    char up = a[0], down = a[n - 1];
    char left = b[0], right = b[m - 1];
    if (judge(up, down, left, right)) printf("YES\n");
    else printf("NO\n");
    return 0;
}