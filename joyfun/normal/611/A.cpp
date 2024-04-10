#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int x;
char sb[20], s[20];

int main() {
    scanf("%d%s%s", &x, sb, s);
    if (s[0] == 'w') {
        if (x == 5 || x == 6) printf("53\n");
        else printf("52\n");
    } else {
        if (x <= 29) printf("12\n");
        if (x == 30) printf("11\n");
        if (x == 31) printf("7\n");
    }
    return 0;
}