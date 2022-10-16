#include<cstdio>
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
int main(void) {
    int n;
    scanf("%d",&n);
    if (n<=3) {
        printf("NO");
        return 0;
    }
    printf("YES\n");
    if (n==5) {
        printf("3 - 1 = 2\n");
        printf("5 - 2 = 3\n");
        printf("2 * 3 = 6\n");
        printf("6 * 4 = 24\n");
        return 0;
    }
    printf("2 * 3 = 6\n");
    printf("6 * 4 = 24\n");
    if (n==4) {
        printf("24 * 1 = 24\n");
        return 0;
    }
    printf("6 - 5 = 1\n");
    printf("1 - 1 = 0\n");
    FOR(i,7,n) printf("0 * %d = 0\n",i);
    printf("24 + 0 = 24\n");
    return 0;
}