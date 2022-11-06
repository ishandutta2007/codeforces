#include <stdio.h>
int main()
{
    int n, m, i, abc = 0;
    scanf("%d%d", &n, &m);
    for(i = 0; i < n; i += 1)
    {
        int x;
        scanf("%d", &x);
        if(x == 1) abc += 1;
    }
    if(abc > n - abc) abc = n - abc;
    abc *= 2;
    int arr[m][2];
    for(i = 0; i < m; i += 1)
        scanf("%d%d", &arr[i][0], &arr[i][1]);
    for(i = 0; i < m; i += 1)
    {
        int l = arr[i][0], r = arr[i][1];
        printf("%d\n", (r - l) % 2 && r - l < abc);
    }
    return 0;
}