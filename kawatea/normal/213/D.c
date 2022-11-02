#include <stdio.h>
#include <math.h>

int main()
{
    int n, m, i;
    double p = 0, q = 0;
    double pi = acos(-1);
    double x = (1 + sqrt(5)) / 2;
    
    scanf("%d", &n);
    
    m = 4 * (n - 1) + 5;
    
    printf("%d\n", m);
    
    for (i = 0; i < n; i++) {
        if (i == 0) printf("%.12lf %.12lf\n", p, q);
        
        printf("%.12lf %.12lf\n", p + 10 * x, q);
        printf("%.12lf %.12lf\n", p + 5 * x, 10 * cos(54 * pi / 180));
        printf("%.12lf %.12lf\n", p + 10 * cos(72 * pi / 180), -10 * sin(72 * pi / 180));
        printf("%.12lf %.12lf\n", p + 10 * x - 10 * cos(72 * pi / 180), -10 * sin(72 * pi / 180));
        
        p += 10 * x;
    }
    
    for (i = 0; i < n; i++) {
        if (i == 0) {
            printf("1");
        } else {
            printf("%d", i * 4 - 2);
        }
        
        printf(" %d %d %d %d\n", i * 4 + 4, i * 4 + 5, i * 4 + 2, i * 4 + 3);
    }
    
    printf("1");
    
    for (i = 0; i < n; i++) printf(" %d", i * 4 + 2);
    
    for (i = n - 1; i >= 0; i--) {
        printf(" %d %d %d", i * 4 + 4, i * 4 + 3, i * 4 + 5);
        
        if (i == 0) {
            printf(" 1");
        } else {
            printf(" %d", i * 4 - 2);
        }
    }
    
    puts("");
    
    return 0;
}