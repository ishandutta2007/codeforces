#include <stdio.h>
using namespace std;
int p[109][109];
int main()
{
    int n, m, mn, f = 0, r1[99999], r2[99999], cnt1 = 0, cnt2 = 0;
    scanf("%d %d", &n, &m);
    if (m < n){
        int t = m; m = n; n = t;
        for (int i = 1; i <= m; i++)
            for (int j = 1; j <= n; j++)
                scanf("%d", &p[j][i]);
        f = 1;
    }
    else{
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                scanf("%d", &p[i][j]);
    }
    for (int i = 1; i <= n; i++){
        mn = 999;
        for (int j = 1; j <= m; j++)
            if (mn > p[i][j])
                mn = p[i][j];
        if (mn != 0){
            for (int j = 1; j <= m; j++)
                p[i][j] -= mn;
            for (int j = 1; j <= mn; j++)
                r1[++cnt1] = i;
        }
    }
    for (int i = 1; i <= m; i++){
        mn = 999;
        for (int j = 1; j <= n; j++)
            if (mn > p[j][i])
                mn = p[j][i];
        if (mn != 0){
            for (int j = 1; j <= n; j++)
                p[j][i] -= mn;
            for (int j = 1; j <= mn; j++)
                r2[++cnt2] = i;
        }
    }
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            if (p[i][j] != 0){
                printf("-1\n");
                return 0;
            }
        }
    }
    printf("%d\n", cnt1 + cnt2);
    for (int i = 1; i <= cnt1; i++){
        if (f == 0)
            printf("row %d\n", r1[i]);
        else
            printf("col %d\n", r1[i]);
    }
    for (int i = 1; i <= cnt2; i++){
        if (f == 1)
            printf("row %d\n", r2[i]);
        else
            printf("col %d\n", r2[i]);
    }
    return 0;
}