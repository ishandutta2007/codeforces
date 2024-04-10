#include <cstdio>
#include <cstring>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);

    int a = 1, b = 1;
    for (int i = 0; i < n; i++) {
        char s[5];
        scanf("%4s", s);
        if (strcmp(s, "UL") == 0 || strcmp(s, "DR") == 0)
            a++;
        else if (strcmp(s, "UR") == 0 || strcmp(s, "DL") == 0)
            b++;
        else
            a++, b++;
    }

    printf("%lld\n", (long long) a * b);
}