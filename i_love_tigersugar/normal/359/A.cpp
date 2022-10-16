#include<cstdio>
#define MAX   55
#define FOR(i,a,b) for (int i=(a);i<=(b);i=i+1)
int a[MAX][MAX];
int m,n;
void init(void) {
    scanf("%d",&m);
    scanf("%d",&n);
    FOR(i,1,m) FOR (j,1,n) {
        scanf("%d",&a[i][j]);
        if ((i==1 || j==1 || i==m || j==n) && a[i][j]==1) {
            printf("2");
            return;
        }
    }
    printf("4");
}
int main(void) {
    init();
    return 0;
}