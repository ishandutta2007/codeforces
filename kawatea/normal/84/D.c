#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int a;
    int i;
} animal;

int cmp1(const void *a, const void *b)
{
    return ((animal *)a)->a - ((animal *)b)->a;
}

int cmp2(const void *a, const void *b)
{
    return ((animal *)a)->i - ((animal *)b)->i;
}

int main()
{
    int n, p = 0, f = 0, i;
    long long int k, s = 0, t1, t2;
    animal a[100000];

    scanf("%d %I64d", &n, &k);

    for (i = 0; i < n; i++) {
        scanf("%d", &a[i].a);
        s += a[i].a;
        a[i].i = i;
    }
    
    qsort(a, n, sizeof(animal), cmp1);

    t1 = a[0].a; t2 = 0;

    if (s < k) {
        puts("-1");
    } else if (s > k) {
        while ((t1 - t2) * (n - p) <= k) {
            k -= (t1 - t2) * (n - p);
            
            t2 = a[p].a;
            
            while (a[p].a == t1) p++;
            
            t1 = a[p].a;
        }

        while ((n - p) <= k) {
         k -= n - p; t2++;
        }

        qsort(a, n, sizeof(animal), cmp2);

        for (i = 0; i < n; i++) {
            if (a[i].a > t2) {
                k--;
                if (k == -1) {
                    k = i; break;
                }
            }
        }

        for (i = k; i < n; i++) {
            if (a[i].a > t2) {
                if (i > k) putchar(' ');
                printf("%d", i + 1);
            }
        }

        for (i = 0; i < k; i++) {
            if (a[i].a > t2 + 1) {
                putchar(' ');
                printf("%d", i + 1);
            }
        }
        
        puts("");
    }

    return 0;
}