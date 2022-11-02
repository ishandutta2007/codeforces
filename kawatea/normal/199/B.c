#include <stdio.h>

int main()
{
    int x1, y1, r1, R1, x2, y2, r2, R2, d, sum = 0;
    
    scanf("%d %d %d %d", &x1, &y1, &r1, &R1);
    scanf("%d %d %d %d", &x2, &y2, &r2, &R2);
    
    d = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
    
    if (d >= r1 * r1) {
        if (r2 >= r1 && d <= r1 * r1 - 2 * r1 * r2 + r2 * r2) {
            sum++;
        } else if (d >= r1 * r1 + 2 * r1 * R2 + R2 * R2) {
            sum++;
        }
    } else {
        if (r1 >= R2 && d <= r1 * r1 - 2 * r1 * R2 + R2 * R2) {
            sum++;
        } else if (r2 >= r1 && d <= r1 * r1 - 2 * r1 * r2 + r2 * r2) {
            sum++;
        }
    }
    
    if (d >= r2 * r2) {
        if (r1 >= r2 && d <= r1 * r1 - 2 * r1 * r2 + r2 * r2) {
            sum++;
        } else if (d >= R1 * R1 + 2 * R1 * r2 + r2 * r2) {
            sum++;
        }
    } else {
        if (r2 >= R1 && d <= R1 * R1 - 2 * R1 * r2 + r2 * r2) {
            sum++;
        } else if (r1 >= r2 && d <= r1 * r1 - 2 * r1 * r2 + r2 * r2) {
            sum++;
        }
    }
    
    if (d >= R1 * R1) {
        if (d >= R1 * R1 + 2 * R1 * R2 + R2 * R2) {
            sum++;
        } else if (r2 >= R1 && d <= R1 * R1 - 2 * R1 * r2 + r2 * r2) {
            sum++;
        }
    } else {
        if (R1 >= R2 && d <= R1 * R1 - 2 * R1 * R2 + R2 * R2) {
            sum++;
        } else if (r2 >= R1 && d <= R1 * R1 - 2 * R1 * r2 + r2 * r2) {
            sum++;
        }
    }
    
    if (d >= R2 * R2) {
        if (d >= R1 * R1 + 2 * R1 * R2 + R2 * R2) {
            sum++;
        } else if (r1 >= R2 && d <= r1 * r1 - 2 * r1 * R2 + R2 * R2) {
            sum++;
        }
    } else {
        if (R2 >= R1 && d <= R1 * R1 - 2 * R1 * R2 + R2 * R2) {
            sum++;
        } else if (r1 >= R2 && d <= r1 * r1 - 2 * r1 * R2 + R2 * R2) {
            sum++;
        }
    }
    
    printf("%d\n", sum);
    
    return 0;
}