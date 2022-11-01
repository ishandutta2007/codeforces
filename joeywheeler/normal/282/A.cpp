#include <cstdio>

#ifdef DEBUG
#define D(x...) fprintf(stderr, x)
#else
#define D(x...)
#endif

#define FO(i,a,b) for (int i = (a); i < (b); i++)

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    int x = 0;
    FO(i,0,n) {
        char s[4];
        scanf("%s", s);
        if (s[0] == '+' || s[1] == '+') x++;
        else x--;
    }
    printf("%d\n", x);

    return 0;
}