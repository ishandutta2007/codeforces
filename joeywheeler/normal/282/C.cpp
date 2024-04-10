#include <cstdio>
#include <cstring>

#ifdef DEBUG
#define D(x...) fprintf(stderr, x)
#else
#define D(x...)
#endif

#define FO(i,a,b) for (int i = (a); i < (b); i++)

using namespace std;

char a[2000005], b[2000005];

int main() {
    scanf("%s %s", a, b);
    int n = strlen(a), m = strlen(b);

    if (n != m) printf("NO\n");
    else {
        int h0 = 0, h1 = 0;
        FO(i,0,n) h0 += a[i] == '1';
        FO(i,0,m) h1 += b[i] == '1';
        if (!h0 != !h1) printf("NO\n");
        else printf("YES\n");
    }

    return 0;
}