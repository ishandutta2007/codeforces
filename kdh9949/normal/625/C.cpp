#include <cstdio>

int n, k;
int ans, a[511][511], cnt;

int main(){
    scanf("%d%d", &n, &k);
    for(int i = 1; i <= n; i++){
        for(int j = 1; j < k; j++){
            a[i][j] = ++cnt;
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = k; j <= n; j++){
            a[i][j] = ++cnt;
            if(j == k) ans += a[i][j];
        }
    }
    printf("%d\n", ans);
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            printf("%d ", a[i][j]);
        }
        puts("");
    }
}