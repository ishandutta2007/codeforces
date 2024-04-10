#include <cstdio>

#ifdef DEBUG
#define D(x...) fprintf(stderr, x)
#else
#define D(x...)
#endif

#define FO(i,a,b) for (int i = (a); i < (b); i++)

using namespace std;

int n;
int a, g;

int main() {
    scanf("%d", &n);
    int A = 0,G = 0;
    FO(i,0,n) {
        scanf("%d %d", &a, &g);
        if (A+a <= G+500) {
            A+=a;
            printf("A");
        } else {
            G+=g;
            printf("G");
        }
    }
    printf("\n");

    return 0;
}