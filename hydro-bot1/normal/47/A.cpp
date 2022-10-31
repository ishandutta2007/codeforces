// Hydro submission #62cd07eee4874952a0849a8b@1657604079605
#include <math.h>
#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    int l = (int)sqrt(n), r = (n << 1) + 1;
    while (l < r)
    {
        int mid = (l + r) >> 1;
        if (mid * (mid + 1) < (n << 1))
            l = mid + 1;
        else
            r = mid;
    }
    if (l * (l + 1) == (n << 1))
        puts("YES");
    else
        puts("NO");
    return 0;
}