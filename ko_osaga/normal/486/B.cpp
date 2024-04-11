#include <cstdio>
#include <algorithm>
using namespace std;

int n, m;
int a[105][105];
int p[105], q[105];

int main(){
    scanf("%d %d",&n,&m);
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            scanf("%d",&a[i][j]);
            a[i][j] += a[i-1][j] + a[i][j-1] - a[i-1][j-1];
        }
    }
    for (int i=1; i<=n; i++) {
        int ret = a[i][m] - a[i-1][m];
        p[i] = (ret == m);
    }
    for (int i=1; i<=m; i++) {
        int ret = a[n][i] - a[n][i-1];
        q[i] = (ret == n);
    }
    if(count(p+1,p+n+1,1) == 0 || count(q+1,q+m+1,1) == 0){
        if(a[n][m] == 0){
            printf("YES\n");
            for (int i=1; i<=n; i++) {
                for (int j=1; j<=m; j++) {
                    printf("0 ");
                }
                puts("");
            }
        }
        else{
            puts("NO");
        }
        return 0;
    }
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            if((p[i] || q[j]) ^ (a[i][j] - a[i-1][j] - a[i][j-1] + a[i-1][j-1])){
                printf("NO");
                return 0;
            }
        }
    }
    puts("YES");
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            printf("%d ",p[i] & q[j]);
        }
        puts("");
    }
}